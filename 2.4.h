#pragma once
#include "Tester.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Employee;//2.4
class Department {
private:
    std::string name;
    Employee* head;

public:
    Department(const std::string& n) : name(n), head(nullptr) {}
    void setHead(Employee* emp);
    std::string getName() const { return name; }
    Employee* getHead() const { return head; }
};

class Employee {
private:
    std::string name;
    Department* department;

public:
    Employee(const std::string& n) : name(n), department(nullptr) {}
    void setDepartment(Department* dep) { department = dep; }
    std::string toString() const {
        if (!department) return name + " не работает ни в каком отделе";
        Employee* head = department->getHead();
        if (head == this) return name + " начальник отдела " + department->getName();
        else if (head) return name + " работает в отделе " + department->getName() + ", начальник которого " + head->getName();
        else return name + " работает в отделе " + department->getName();
    }
    std::string getName() const { return name; }
    void print() const { std::cout << toString() << "\n"; }
};

void Department::setHead(Employee* emp) {
    head = emp;
    if (emp) emp->setDepartment(this);
}

void Task1() {
    std::vector<Employee*> employees;
    std::string deptName = Tester::getString("Введите название отдела: ");
    Department dept(deptName);

    int n = Tester::getInt("Сколько сотрудников создать? ");
    for (int i = 0; i < n; ++i) {
        std::string name = Tester::getString("Имя сотрудника: ");
        Employee* emp = new Employee(name);
        emp->setDepartment(&dept);
        employees.push_back(emp);
    }

    for (size_t i = 0; i < employees.size(); ++i)
        std::cout << i + 1 << ". " << employees[i]->getName() << "\n";
    int idx = Tester::getInt("\nВыберите начальника (номер):\n");
    if (idx >= 1 && idx <= (int)employees.size())
        dept.setHead(employees[idx - 1]);
    else std::cout << "Неверный номер\n";

    std::cout << "\nСотрудники:\n";
    for (auto e : employees) e->print();
}

void task24Interactive() {
    int choice;
    do {
        std::cout << "\nЗадача 2.4. Сотрудники и отделы. Создайте сущность Сотрудник, которая описывается\n"
            "именем(в строковой форме) и отделом, в котором сотрудник работает, причем у\n"
            "каждого отдела есть название и начальник, который также является\n"
            "Сотрудником.Сотрудник может быть приведен к текстовой форме вида : “Имя\n"
            "работает в отделе Название, начальник которого Имя”.В случае если сотрудник\n"
            "является руководителем отдела, то текстовая форма должна быть “Имя\n"
            "начальник отдела Название”.\n"
            "Необходимо выполнить следующие задачи : \n"
            "1. Создать cотрудников работающих в отделе IT.\n"
            "2. Сделать сотрудника начальником IT отдела.\n"
            "3. Вывести на экран текстовое представление всех Сотрудников(у всех\n"
            "    должен оказаться один и тот же отдел и начальник).\n\n";

        std::cout << "1. Выполнить задачу\n";
        std::cout << "0. Выход\n\n";

        choice = Tester::getInt("Выберите: ");
        std::cout << "\n";
        switch (choice) {
        case 1: Task1();
        case 0: std::cout << "Выход\n"; break;
        default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);
}