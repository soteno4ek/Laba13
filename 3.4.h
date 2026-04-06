#pragma once
#include "Tester.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Department2;//3.4
class Employee2 {
private:
    std::string name;
    Department2* department;

public:
    Employee2(const std::string& n) : name(n), department(nullptr) {}
    void setDepartment(Department2* dep);
    std::string getName() const { return name; }
    void print() const;
};

class Department2 {
private:
    std::string name;
    Employee2* head;
    std::vector<Employee2*> employees;

public:
    Department2(const std::string& n) : name(n), head(nullptr) {}
    void addEmployee(Employee2* emp) {
        employees.push_back(emp);
        if (emp) emp->setDepartment(this);
    }
    void setHead(Employee2* emp) {
        head = emp;
        if (emp) {
            emp->setDepartment(this);
            if (std::find(employees.begin(), employees.end(), emp) == employees.end())
                employees.push_back(emp);
        }
    }
    std::string getName() const { return name; }
    Employee2* getHead() const { return head; }
    const std::vector<Employee2*>& getEmployees() const { return employees; }
};

void Employee2::setDepartment(Department2* dep) { department = dep; }
void Employee2::print() const {
    if (!department) {
        std::cout << name << " не работает ни в каком отделе\n";
        return;
    }
    Employee2* head = department->getHead();
    if (head == this) {
        std::cout << name << " начальник отдела " << department->getName() << "\n";
        std::cout << "  Сотрудники отдела:\n";
        for (auto emp : department->getEmployees())
            if (emp != this) std::cout << "    " << emp->getName() << "\n";
    }
    else if (head) {
        std::cout << name << " работает в отделе " << department->getName() << ", начальник которого " << head->getName() << "\n";
    }
    else {
        std::cout << name << " работает в отделе " << department->getName() << "\n";
    }
}

void task34Interactive() {
    std::cout << "\nЗадача 3.4. Сотрудники и отделы. Измените решение, полученное в задаче 2.4 таким\n"
        "образом, чтобы имея ссылку на сотрудника, можно было бы узнать список всех\n"
        "сотрудников этого отдела.\n\n";

    std::vector<Employee2*> employees;
    std::string deptName = Tester::getString("Введите название отдела: ");
    Department2 dept(deptName);

    int n = Tester::getInt("Сколько сотрудников создать? ");
    for (int i = 0; i < n; ++i) {
        std::string name = Tester::getString("Имя сотрудника: ");
        Employee2* emp = new Employee2(name);
        dept.addEmployee(emp);
        employees.push_back(emp);
    }

    for (size_t i = 0; i < employees.size(); ++i)
        std::cout << i + 1 << ". " << employees[i]->getName() << "\n";
    int idx = Tester::getInt("\nВыберите начальника (номер): ");
    if (idx >= 1 && idx <= (int)employees.size())
        dept.setHead(employees[idx - 1]);
    else std::cout << "Неверный номер\n";

    std::cout << "\nСотрудники:\n";
    for (auto e : employees) e->print();

    std::string s = Tester::getString("\nВведите имя сотрудника для просмотра отдела (или 0): ");
    if (s != "0") {
        bool found = false;
        for (auto e : employees) {
            if (e->getName() == s) { e->print(); found = true; break; }
        }
        if (!found) std::cout << "Не найден\n";
    }
    for (auto e : employees) delete e;
}