#pragma once
#include "Tester.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Human {
private:
    std::string name;
    int height;

public:
    Human(const std::string& n, int h) : name(n), height(h) {}

    std::string toString() const {
        return name + ", рост: " + std::to_string(height);
    }

    void print() const {
        std::cout << toString() << "\n";
    }
};

void task12Interactive() {
    std::cout << "\nЗадача 1.2. Человек. Создайте сущность Человек, которая описывается:\n"
        " Имя : строка\n"
        " Рост : целое число\n"
        "Может возвращать текстовое представление вида \"Name, рост : height\", где Name и\n"
        "height это переменная с именем и ростом.\n"
        "Необходимо создать и вывести на экран следующих людей :\n"
        " Человек с именем \"Клеопатра\" и ростом 152\n"
        " Человек с именем \"Пушкин\" и ростом 167\n"
        " Человек с именем \"Владимир\" и ростом 189\n\n";

    std::vector<Human> humans;
    int choice;
    do {
        std::cout << "\n--- Меню ---\n";
        std::cout << "1. Добавить человека\n";
        std::cout << "2. Вывести всех\n";
        std::cout << "3. Очистить\n";
        std::cout << "0. Назад\n";
        choice = Tester::getInt("Выберите: ");

        if (choice == 1) {
            std::string name = Tester::getString("Введите имя: ");
            int h = Tester::getInt("Введите рост: ");
            if (h > 0) {
                humans.push_back(Human(name, h));
                std::cout << "Человек добавлен\n";
            }
            else std::cout << "Рост должен быть >0\n";
        }
        else if (choice == 2) {
            if (humans.empty()) std::cout << "Нет людей\n";
            else for (size_t i = 0; i < humans.size(); ++i) {
                std::cout << i + 1 << ": "; humans[i].print();
            }
        }
        else if (choice == 3) {
            humans.clear();
            std::cout << "Очищено\n";
        }
    } while (choice != 0);
}