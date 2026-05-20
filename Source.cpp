#include <iostream>
#include <locale>
#include "Tester.h"
#include "TreeWork5.h"
#include "TreeWork16.h"
#include "TreeWork18.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        std::cout << "\n========== ЛАБОРАТОРНАЯ РАБОТА №16 (БИНАРНЫЕ ДЕРЕВЬЯ) ==========\n";
        std::cout << "1. Задача 5 - листья справа налево\n";
        std::cout << "2. Задача 16 - построение дерева поиска и инфиксный вывод\n";
        std::cout << "3. Задача 18 - второй максимум за O(log n)\n";
        std::cout << "0. Выход\n";
        choice = Tester::getInt("Выберите задачу: ");
        switch (choice) {
        case 1: TreeWork5::run(); break;
        case 2: TreeWork16::run(); break;
        case 3: TreeWork18::run(); break;
        case 0: std::cout << "Выход\n"; break;
        default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);
    return 0;
}