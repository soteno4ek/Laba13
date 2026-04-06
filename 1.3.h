#pragma once
#include "Tester.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Name {//1.3
private:
    std::string lastName;
    std::string firstName;
    std::string middleName;

public:
    Name() {}
    Name(const std::string& fn) : firstName(fn) {}
    Name(const std::string& fn, const std::string& ln) : firstName(fn), lastName(ln) {}
    Name(const std::string& fn, const std::string& ln, const std::string& mn) : firstName(fn), lastName(ln), middleName(mn) {}

    std::string toString() const {
        std::string result;
        if (!lastName.empty()) result += lastName;
        if (!firstName.empty()) {
            if (!result.empty()) result += " ";
            result += firstName;
        }
        if (!middleName.empty()) {
            if (!result.empty()) result += " ";
            result += middleName;
        }
        return result;
    }

    void print() const { std::cout << toString() << "\n"; }
};

void task13Interactive() {
    std::cout << "\nЗадача 1.3. Имена. Создайте сущность Имя, которая описывается тремя параметрами:\n"
        "Фамилия, Личное имя, Отчество.Имя может быть приведено к строковому виду,\n"
        "включающему традиционное представление всех трех параметров : Фамилия Имя\n"
        "Отчество(например “Иванов Иван Иванович”).Необходимо предусмотреть\n"
        "возможность того, что какой - либо из параметров может быть не задан, и в этом\n"
        "случае он не учитывается при приведении к текстовому виду.\n"
        "Необходимо создать следующие имена : \n"
        " Клеопатра\n"
        " Пушкин Александр Сергеевич\n"
        " Маяковский Владимир\n"
        "Обратите внимание, что при выводе на экран, не заданные параметры никак не\n"
        "участвуют в образовании строки.\n\n";

    std::vector<Name> names;
    int choice;
    do {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Добавить имя\n";
        std::cout << "2. Вывести все имена\n";
        std::cout << "3. Очистить\n";
        std::cout << "0. Назад\n";
        choice = Tester::getInt("Выберите: ");

        if (choice == 1) {
            int t = Tester::getInt("Выберите тип : \n1.Только имя\n2.Имя + фамилия\n3.Имя + фамилия + отчество\n");
            std::string fn, ln, mn;
            if (t == 1) {
                fn = Tester::getString("Введите имя: ");
                names.push_back(Name(fn));
            }
            else if (t == 2) {
                fn = Tester::getString("Введите имя: ");
                ln = Tester::getString("Введите фамилию: ");
                names.push_back(Name(fn, ln));
            }
            else if (t == 3) {
                fn = Tester::getString("Введите имя: ");
                ln = Tester::getString("Введите фамилию: ");
                mn = Tester::getString("Введите отчество: ");
                names.push_back(Name(fn, ln, mn));
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