//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//#include <cstdlib>
//#include <ctime>
//
//void printVector(const std::vector<int>& v) {
//    std::cout << "Вектор: ";
//    for (size_t i = 0; i < v.size(); ++i) {
//        std::cout << v[i] << " ";
//    }
//    std::cout << "\n";
//}
//
//void fillManually(std::vector<int>& v) {
//    int n, x;
//    std::cout << "Введите количество элементов (чётное): ";
//    std::cin >> n;
//    if (n % 2 != 0) {
//        std::cout << "Ошибка: количество должно быть чётным\n";
//        return;
//    }
//    v.clear();
//    for (int i = 0; i < n; ++i) {
//        std::cout << "Введите элемент " << i + 1 << ": ";
//        std::cin >> x;
//        v.push_back(x);
//    }
//    std::cout << "Вектор заполнен\n";
//}
//
//void fillRandom(std::vector<int>& v) {
//    int n;
//    std::cout << "Введите количество элементов (чётное): ";
//    std::cin >> n;
//    if (n % 2 != 0) {
//        std::cout << "Ошибка: количество должно быть чётным\n";
//        return;
//    }
//    v.clear();
//    srand(time(0));
//    for (int i = 0; i < n; ++i) {
//        v.push_back(rand() % 100 - 50);
//    }
//    std::cout << "Вектор заполнен случайными числами\n";
//}
//
//void solve(std::vector<int>& v) {
//    if (v.empty() || v.size() % 2 != 0) {
//        std::cout << "Вектор пуст или имеет нечётное количество элементов\n";
//        return;
//    }
//
//    std::vector<int> v0(v.begin() + v.size() / 2, v.end());
//
//    v.clear();
//    std::remove_copy_if(v0.begin(), v0.end(), std::back_inserter(v),
//        [](int x) { return x <= 0; });
//
//    std::cout << "Готово\n";
//    std::cout << "Результат: ";
//    for (size_t i = 0; i < v.size(); ++i) {
//        std::cout << v[i] << " ";
//    }
//    std::cout << "\n";
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    std::vector<int> v;
//    int choice;
//
//    do {
//        std::cout << "\nSTL3Alg29. Дан вектор V с чётным количеством элементов.\n"
//            "Скопировать в начало все положительные элементы из второй половины,\n"
//            "сохранив их порядок. Использовать вспомогательный вектор V0 и алгоритм remove_copy_if.\n";
//
//        std::cout << "\nТекущее состояние:\n";
//        printVector(v);
//
//        std::cout << "\n1. Заполнить вектор вручную\n";
//        std::cout << "2. Заполнить вектор случайными числами\n";
//        std::cout << "3. ВЫПОЛНИТЬ ЗАДАНИЕ\n";
//        std::cout << "4. Вывести вектор\n";
//        std::cout << "5. Очистить вектор\n";
//        std::cout << "0. Выход\n";
//
//        std::cout << "Выберите действие: ";
//        std::cin >> choice;
//        std::cout << "\n";
//
//        switch (choice) {
//        case 1:
//            fillManually(v);
//            break;
//        case 2:
//            fillRandom(v);
//            break;
//        case 3:
//            solve(v);
//            break;
//        case 4:
//            printVector(v);
//            break;
//        case 5:
//            v.clear();
//            std::cout << "Вектор очищен\n";
//            break;
//        case 0:
//            std::cout << "Программа завершена\n";
//            break;
//        default:
//            std::cout << "Неверный выбор\n";
//        }
//    } while (choice != 0);
//
//    return 0;
//}