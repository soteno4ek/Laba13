#pragma once
#include "Tester.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Name2 {
private:
    std::string firstName;
    std::string lastName;
    std::string middleName;

public:
    Name2() {}
    explicit Name2(const std::string& fn) : firstName(fn) {}
    Name2(const std::string& fn, const std::string& ln) : firstName(fn), lastName(ln) {}
    Name2(const std::string& fn, const std::string& mn, const std::string& ln) : firstName(fn), middleName(mn), lastName(ln) {}

    std::string toString() const {
        std::string result;
        if (!firstName.empty()) result += firstName;
        if (!middleName.empty()) {
            if (!result.empty()) result += " ";
            result += middleName;
        }
        if (!lastName.empty()) {
            if (!result.empty()) result += " ";
            result += lastName;
        }
        return result;
    }

    void print() const { std::cout << toString() << "\n"; }
};

void task45Interactive() {
    std::cout << "\nЗадача 4.5. Создаем Имена. Измените сущность Имя из задачи 1.3. Новые требования\n"
        "включают:\n"
        " Имя можно создать указав только Личное имя\n"
        " Имя можно создать указав Личное имя и Фамилию.\n"
        " Имя можно создать указав все три параметра : Личное имя, Фамилию,\n"
        "Отчество.\n"
        "Необходимо создать следующие имена :\n"
        "1. Клеопатра\n"
        "2. Александр Сергеевич Пушкин\n"
        "3. Владимир Маяковский\n"
        "4. Христофор Бонифатьевич(здесь Христофор это имя, а Бонифатьевич -\n"
        "    фамилия) \n\n";

    std::vector<Name2> names;
    int choice;
    do {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Добавить имя\n";
        std::cout << "2. Вывести все имена\n";
        std::cout << "3. Очистить\n";
        std::cout << "0. Назад\n";
        choice = Tester::getInt("Выберите: ");

        if (choice == 1) {
            int t = Tester::getInt("Тип:\n1. Только имя\n2. Имя + фамилия\n3. Имя + отчество + фамилия\n");
            std::string fn, ln, mn;
            if (t == 1) {
                fn = Tester::getString("Имя: ");
                names.push_back(Name2(fn));
            }
            else if (t == 2) {
                fn = Tester::getString("Имя: ");
                ln = Tester::getString("Фамилия: ");
                names.push_back(Name2(fn, ln));
            }
            else if (t == 3) {
                fn = Tester::getString("Имя: ");
                mn = Tester::getString("Отчество: ");
                ln = Tester::getString("Фамилия: ");
                names.push_back(Name2(fn, mn, ln));
            }
            else std::cout << "Неверно\n";
        }
        else if (choice == 2) {
            if (names.empty()) std::cout << "Нет имён\n";
            else for (size_t i = 0; i < names.size(); ++i) {
                std::cout << i + 1 << ": "; names[i].print();
            }
        }
        else if (choice == 3) {
            names.clear();
            std::cout << "Очищено\n";
        }
    } while (choice != 0);
}