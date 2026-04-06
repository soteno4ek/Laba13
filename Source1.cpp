#include "Tester.h"
#include "1.2.h"
#include "1.3.h"
#include "2.4.h"
#include "3.4.h"
#include "4.5.h"
#include "5.1.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    do {
        std::cout << "\n========== ЛАБОРАТОРНАЯ РАБОТА №15 ==========\n";
        std::cout << "1. Имена (Клеопатра, Пушкин Александр Сергеевич, Маяковский Владимир)\n";
        std::cout << "2. Люди (Клеопатра 152, Пушкин 167, Владимир 189)\n";
        std::cout << "3. Сотрудники и отделы (Петров, Козлов, Сидоров в IT, Козлов начальник)\n";
        std::cout << "4. Сотрудники и отделы с просмотром списка\n";
        std::cout << "5. Создание имён\n";
        std::cout << "6. Пистолет с 3 патронами\n";
        std::cout << "0. Выход\n";
        choice = Tester::getInt("Выберите: ");
        std::cout << "\n";
        switch (choice) {
        case 1: task13Interactive(); break;
        case 2: task12Interactive(); break;
        case 3: task24Interactive(); break;
        case 4: task34Interactive(); break;
        case 5: task45Interactive(); break;
        case 6: task51Interactive(); break;
        case 0: std::cout << "Выход\n"; break;
        default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);
}