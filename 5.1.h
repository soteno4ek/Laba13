#pragma once
#include "Tester.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Gun {//5.1
private:
    int bullets;

public:
    Gun() : bullets(5) {}
    Gun(int b) : bullets(b) {}
    void shoot() {
        if (bullets > 0) {
            std::cout << "Бах!\n";
            bullets--;
        }
        else {
            std::cout << "Клац!\n";
        }
    }
    int getBullets() const { return bullets; }
    void reload(int b) {
        if (b >= 0) bullets = b;
        else std::cout << "Неверное количество патронов\n";
    }
    void print() const { std::cout << "Патронов: " << bullets << "\n"; }
};

void task51Interactive() {
    std::cout << "\nЗадача 5.1. Пистолет стреляет. Создайте сущность Пистолет, которая описывается\n"
        "следующим образом : \n"
        " Имеет Количество патронов(целое число)\n"
        " Может быть создан с указанием начального количества патронов\n"
        " Может быть создан без указания начального количества патронов, в этом\n"
        "случае он изначально заряжен пятью патронами.\n"
        " Может Стрелять, что приводит к выводу на экран текста “Бах!” в том\n"
        "случае, если количество патронов больше нуля, иначе делает “Клац!”.\n"
        "После каждого выстрела(когда вывелся “Бах!”) количество патронов\n"
        "уменьшается на один.\n"
        "Создайте пистолет с тремя патронами и выстрелите из него пять раз. \n\n";

    int init = Tester::getInt("Введите начальное количество патронов (по умолчанию 5): ");
    if (init < 0) init = 0;
    Gun gun(init);
    int choice;
    do {
        std::cout << "Текущее состояние: ";
        gun.print();
        std::cout << "1. Выстрелить\n";
        std::cout << "2. Перезарядить (5 патронов)\n";
        std::cout << "3. Перезарядить (указать количество)\n";
        std::cout << "4. Выстрелить 5 раз подряд\n";
        std::cout << "0. Назад\n";
        choice = Tester::getInt("Выберите: ");
        switch (choice) {
        case 1: gun.shoot(); break;
        case 2: gun.reload(5); std::cout << "Перезаряжено (5 патронов)\n"; break;
        case 3: { int b = Tester::getInt("Сколько патронов: "); gun.reload(b); break; }
        case 4:
            std::cout << "1: "; gun.shoot();
            std::cout << "2: "; gun.shoot();
            std::cout << "3: "; gun.shoot();
            std::cout << "4: "; gun.shoot();
            std::cout << "5: "; gun.shoot();
            break;
        case 0: break;
        default: std::cout << "Неверный выбор\n";
        }
    } while (choice != 0);
}