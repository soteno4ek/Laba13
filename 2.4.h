#pragma once
#include "Tester.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Employee;
class Department {
private:
    std::string name;
    Employee* head;
    std::vector<Employee*> employees;

public:
    Department(const std::string& n) : name(n), head(nullptr) {}

    std::string getName() const { return name; }
    Employee* getHead() const { return head; }
    const std::vector<Employee*>& getEmployees() const { return employees; }

    void addEmployee(Employee* emp);
    void removeEmployee(Employee* emp);
    void setHead(Employee* emp);
};

class Employee {
private:
    std::string name;
    Department* department;

public:
    Employee(const std::string& n) : name(n), department(nullptr) {}

    void setDepartment(Department* dep) { department = dep; }
    std::string getName() const { return name; }
    Department* getDepartment() const { return department; }

    std::string toString() const {
        if (!department) return name + " не работает ни в каком отделе";
        Employee* head = department->getHead();
        if (head == this) return name + " начальник отдела " + department->getName();
        else if (head) return name + " работает в отделе " + department->getName() + ", начальник которого " + head->getName();
        else return name + " работает в отделе " + department->getName();
    }

    void print() const { std::cout << toString() << "\n"; }
};

void Department::addEmployee(Employee* emp) {
    if (emp && std::find(employees.begin(), employees.end(), emp) == employees.end()) {
        employees.push_back(emp);
        emp->setDepartment(this);
    }
}

void Department::removeEmployee(Employee* emp) {
    auto it = std::find(employees.begin(), employees.end(), emp);
    if (it != employees.end()) {
        if (head == emp) {
            head = nullptr;
            std::cout << "Внимание: начальник отдела " << name << " был удалён из отдела. Отдел остался без начальника.\n";
        }
        employees.erase(it);
        if (emp->getDepartment() == this) emp->setDepartment(nullptr);
    }
}

void Department::setHead(Employee* emp) {
    if (emp && std::find(employees.begin(), employees.end(), emp) != employees.end()) {
        head = emp;
        emp->setDepartment(this);
    }
    else if (emp == nullptr) {
        head = nullptr;
    }
    else {
        std::cout << "Ошибка: сотрудник " << emp->getName() << " не работает в отделе " << name << "\n";
    }
}

void task24Interactive() {
    std::vector<Department*> departments;
    std::vector<Employee*> allEmployees;

    int choice;
    do {
        std::cout << "\nЗадача 2.4. Сотрудники и отделы\n";
        std::cout << "1. Создать новый отдел\n";
        std::cout << "2. Создать нового сотрудника и добавить в отдел\n";
        std::cout << "3. Назначить начальника отдела\n";
        std::cout << "4. Переместить сотрудника в другой отдел\n";
        std::cout << "5. Уволить сотрудника (удалить из отдела)\n";
        std::cout << "6. Вывести информацию о всех отделах и сотрудниках\n";
        std::cout << "7. Вывести информацию о конкретном сотруднике\n";
        std::cout << "0. Назад\n\n";

        choice = Tester::getInt("Выберите: ");

        if (choice == 1) {
            std::string name = Tester::getString("Введите название отдела: ");
            Department* dept = new Department(name);
            departments.push_back(dept);
            std::cout << "Отдел \"" << name << "\" создан\n";
        }
        else if (choice == 2) {
            if (departments.empty()) {
                std::cout << "Сначала создайте отдел\n";
                continue;
            }
            std::string empName = Tester::getString("Введите имя сотрудника: ");
            Employee* emp = new Employee(empName);
            allEmployees.push_back(emp);

            std::cout << "Выберите отдел:\n";
            for (size_t i = 0; i < departments.size(); ++i) {
                std::cout << i + 1 << ". " << departments[i]->getName() << "\n";
            }
            int deptIdx = Tester::getInt("Номер отдела: ") - 1;
            if (deptIdx >= 0 && deptIdx < (int)departments.size()) {
                departments[deptIdx]->addEmployee(emp);
                std::cout << "Сотрудник " << empName << " добавлен в отдел " << departments[deptIdx]->getName() << "\n";
            }
            else {
                std::cout << "Неверный номер\n";
                delete emp;
                allEmployees.pop_back();
            }
        }
        else if (choice == 3) {
            if (departments.empty()) {
                std::cout << "Нет отделов\n";
                continue;
            }
            std::cout << "Выберите отдел:\n";
            for (size_t i = 0; i < departments.size(); ++i) {
                std::cout << i + 1 << ". " << departments[i]->getName() << "\n";
            }
            int deptIdx = Tester::getInt("Номер отдела: ") - 1;
            if (deptIdx < 0 || deptIdx >= (int)departments.size()) {
                std::cout << "Неверный номер\n";
                continue;
            }
            Department* dept = departments[deptIdx];
            const auto& emps = dept->getEmployees();
            if (emps.empty()) {
                std::cout << "В отделе " << dept->getName() << " нет сотрудников\n";
                continue;
            }
            std::cout << "Сотрудники отдела " << dept->getName() << ":\n";
            for (size_t i = 0; i < emps.size(); ++i) {
                std::cout << i + 1 << ". " << emps[i]->getName() << "\n";
            }
            int empIdx = Tester::getInt("Выберите начальника (номер): ") - 1;
            if (empIdx >= 0 && empIdx < (int)emps.size()) {
                dept->setHead(emps[empIdx]);
                std::cout << emps[empIdx]->getName() << " назначен начальником отдела " << dept->getName() << "\n";
            }
            else {
                std::cout << "Неверный номер\n";
            }
        }
        else if (choice == 4) {
            if (allEmployees.empty()) {
                std::cout << "Нет сотрудников\n";
                continue;
            }
            std::cout << "Выберите сотрудника:\n";
            for (size_t i = 0; i < allEmployees.size(); ++i) {
                std::cout << i + 1 << ". " << allEmployees[i]->getName()
                    << " (отдел: " << (allEmployees[i]->getDepartment() ? allEmployees[i]->getDepartment()->getName() : "нет") << ")\n";
            }
            int empIdx = Tester::getInt("Номер сотрудника: ") - 1;
            if (empIdx < 0 || empIdx >= (int)allEmployees.size()) {
                std::cout << "Неверный номер\n";
                continue;
            }
            Employee* emp = allEmployees[empIdx];

            std::cout << "Выберите новый отдел:\n";
            for (size_t i = 0; i < departments.size(); ++i) {
                std::cout << i + 1 << ". " << departments[i]->getName() << "\n";
            }
            int deptIdx = Tester::getInt("Номер отдела: ") - 1;
            if (deptIdx >= 0 && deptIdx < (int)departments.size()) {
                Department* oldDept = emp->getDepartment();
                if (oldDept) oldDept->removeEmployee(emp);
                departments[deptIdx]->addEmployee(emp);
                std::cout << "Сотрудник " << emp->getName() << " перемещён в отдел " << departments[deptIdx]->getName() << "\n";
            }
            else {
                std::cout << "Неверный номер\n";
            }
        }
        else if (choice == 5) {
            if (allEmployees.empty()) {
                std::cout << "Нет сотрудников\n";
                continue;
            }
            std::cout << "Выберите сотрудника для увольнения:\n";
            for (size_t i = 0; i < allEmployees.size(); ++i) {
                std::cout << i + 1 << ". " << allEmployees[i]->getName()
                    << " (отдел: " << (allEmployees[i]->getDepartment() ? allEmployees[i]->getDepartment()->getName() : "нет") << ")\n";
            }
            int empIdx = Tester::getInt("Номер сотрудника: ") - 1;
            if (empIdx < 0 || empIdx >= (int)allEmployees.size()) {
                std::cout << "Неверный номер\n";
                continue;
            }
            Employee* emp = allEmployees[empIdx];
            Department* dept = emp->getDepartment();
            if (dept) dept->removeEmployee(emp);
            delete emp;
            allEmployees.erase(allEmployees.begin() + empIdx);
            std::cout << "Сотрудник уволен\n";
        }
        else if (choice == 6) {
            if (departments.empty()) {
                std::cout << "Нет отделов\n";
            }
            else {
                for (auto dept : departments) {
                    std::cout << "\nОтдел: " << dept->getName() << "\n";
                    std::cout << "  Начальник: " << (dept->getHead() ? dept->getHead()->getName() : "не назначен") << "\n";
                    std::cout << "  Сотрудники:\n";
                    for (auto emp : dept->getEmployees()) {
                        std::cout << "    " << emp->getName();
                        if (dept->getHead() == emp) std::cout << " (начальник)";
                        std::cout << "\n";
                    }
                }
            }
            if (allEmployees.empty()) {
                std::cout << "\nНет сотрудников\n";
            }
            else {
                std::cout << "\nВсе сотрудники:\n";
                for (auto emp : allEmployees) {
                    emp->print();
                }
            }
        }
        else if (choice == 7) {
            if (allEmployees.empty()) {
                std::cout << "Нет сотрудников\n";
                continue;
            }
            std::cout << "Выберите сотрудника:\n";
            for (size_t i = 0; i < allEmployees.size(); ++i) {
                std::cout << i + 1 << ". " << allEmployees[i]->getName() << "\n";
            }
            int empIdx = Tester::getInt("Номер сотрудника: ") - 1;
            if (empIdx >= 0 && empIdx < (int)allEmployees.size()) {
                allEmployees[empIdx]->print();
            }
            else {
                std::cout << "Неверный номер\n";
            }
        }

    } while (choice != 0);

    for (auto emp : allEmployees) delete emp;
    for (auto dept : departments) delete dept;
}