//#include <iostream>
//#include <deque>
//#include <algorithm>
//#include <cstdlib>
//#include <ctime>
//
//void printDeque(const std::deque<int>& d) {
//    std::cout << "Дек: ";
//    for (auto it = d.begin(); it != d.end(); ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << "\n";
//}
//
//void fillManually(std::deque<int>& d) {
//    int n, x;
//    std::cout << "Введите количество элементов: ";
//    std::cin >> n;
//    d.clear();
//    for (int i = 0; i < n; ++i) {
//        std::cout << "Введите элемент " << i + 1 << ": ";
//        std::cin >> x;
//        d.push_back(x);
//    }
//    std::cout << "Дек заполнен\n";
//}
//
//void fillRandom(std::deque<int>& d) {
//    int n;
//    std::cout << "Введите количество элементов: ";
//    std::cin >> n;
//    d.clear();
//    srand(time(0));
//    for (int i = 0; i < n; ++i) {
//        d.push_back(rand() % 10);
//    }
//    std::cout << "Дек заполнен случайными числами\n";
//}
//
//void solve(std::deque<int>& d) {
//    auto rit = std::find(d.rbegin(), d.rend(), 0);
//    if (rit == d.rend()) {
//        std::cout << "Нулевых элементов нет. Дек не изменён\n";
//        return;
//    }
//    auto it = (++rit).base();
//    d.erase(it);
//    std::cout << "Последний нулевой элемент удалён\n";
//    std::cout << "Дек после удаления: ";
//    for (auto x : d) std::cout << x << " ";
//    std::cout << "\n";
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    std::deque<int> d;
//    int choice;
//
//    do {
//        std::cout << "\nSTL3Alg2. Удалить последний нулевой элемент дека.\n"
//            "Использовать find с обратными итераторами и erase.\n";
//
//        std::cout << "\nТекущее состояние:\n";
//        printDeque(d);
//
//        std::cout << "\n1. Заполнить дек вручную\n";
//        std::cout << "2. Заполнить дек случайными числами\n";
//        std::cout << "3. ВЫПОЛНИТЬ ЗАДАНИЕ\n";
//        std::cout << "4. Вывести дек\n";
//        std::cout << "5. Очистить дек\n";
//        std::cout << "0. Выход\n";
//
//        std::cout << "Выберите действие: ";
//        std::cin >> choice;
//        std::cout << "\n";
//
//        switch (choice) {
//        case 1:
//            fillManually(d);
//            break;
//        case 2:
//            fillRandom(d);
//            break;
//        case 3:
//            solve(d);
//            break;
//        case 4:
//            printDeque(d);
//            break;
//        case 5:
//            d.clear();
//            std::cout << "Дек очищен\n";
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