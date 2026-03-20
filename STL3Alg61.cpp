//#include <iostream>
//#include <list>
//#include <deque>
//#include <string>
//#include <numeric>
//#include <algorithm>
//#include <iterator>
//#include <cstdlib>
//#include <ctime>
//
//void printList(const std::list<std::string>& l) {
//    std::cout << "Список L: ";
//    for (auto it = l.begin(); it != l.end(); ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << "\n";
//}
//
//void printDeque(const std::deque<std::string>& d) {
//    std::cout << "Дек D: ";
//    for (auto it = d.begin(); it != d.end(); ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << "\n";
//}
//
//void fillManually(std::list<std::string>& l) {
//    int n;
//    std::string word;
//    std::cout << "Введите количество слов (не менее 2): ";
//    std::cin >> n;
//    if (n < 2) {
//        std::cout << "Ошибка: нужно хотя бы два слова\n";
//        return;
//    }
//    l.clear();
//    for (int i = 0; i < n; ++i) {
//        std::cout << "Введите слово " << i + 1 << ": ";
//        std::cin >> word;
//        l.push_back(word);
//    }
//    std::cout << "Список заполнен\n";
//}
//
//void fillRandom(std::list<std::string>& l) {
//    int n;
//    std::cout << "Введите количество слов (не менее 2): ";
//    std::cin >> n;
//    if (n < 2) {
//        std::cout << "Ошибка: нужно хотя бы два слова\n";
//        return;
//    }
//    l.clear();
//    unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
//    std::srand(seed);
//    const char* words[] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX", "YZA" };
//    for (int i = 0; i < n; ++i) {
//        l.push_back(words[std::rand() % 9]);
//    }
//    std::cout << "Список заполнен случайными словами\n";
//}
//
//void solve(const std::list<std::string>& l, std::deque<std::string>& d) {
//    if (l.size() < 2) {
//        std::cout << "Список содержит менее двух слов\n";
//        return;
//    }
//
//    d.clear();
//
//    auto makePair = [](const std::string& a, const std::string& b) {
//        std::string res;
//        if (!a.empty() && !b.empty()) {
//            res.push_back(a.front());
//            res.push_back(b.back());
//        }
//        return res;
//        };
//
//    std::adjacent_difference(l.begin(), l.end(), std::back_inserter(d),
//        [&makePair](const std::string& a, const std::string& b) {
//            return makePair(a, b);
//        });
//
//    if (!d.empty()) {
//        d.erase(d.begin());
//    }
//
//    std::cout << "Дек построен\n";
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    std::list<std::string> l;
//    std::deque<std::string> d;
//    int choice;
//
//    do {
//        std::cout << "\nSTL3Alg61. Дан список L из английских слов.\n"
//            "Получить дек D, каждый элемент которого строится по паре соседних элементов L:\n"
//            "первая буква левого слова + последняя буква правого слова.\n"
//            "Использовать adjacent_difference с итератором вставки и функциональным объектом,\n"
//            "а также функцию-член erase для дека D.\n";
//
//        std::cout << "\nТекущее состояние:\n";
//        printList(l);
//        printDeque(d);
//
//        std::cout << "\n1. Заполнить список вручную\n";
//        std::cout << "2. Заполнить список случайными словами\n";
//        std::cout << "3. ВЫПОЛНИТЬ ЗАДАНИЕ\n";
//        std::cout << "4. Вывести список\n";
//        std::cout << "5. Вывести дек\n";
//        std::cout << "6. Очистить список и дек\n";
//        std::cout << "0. Выход\n";
//
//        std::cout << "Выберите действие: ";
//        std::cin >> choice;
//        std::cout << "\n";
//
//        switch (choice) {
//        case 1:
//            fillManually(l);
//            d.clear();
//            break;
//        case 2:
//            fillRandom(l);
//            d.clear();
//            break;
//        case 3:
//            solve(l, d);
//            break;
//        case 4:
//            printList(l);
//            break;
//        case 5:
//            printDeque(d);
//            break;
//        case 6:
//            l.clear();
//            d.clear();
//            std::cout << "Список и дек очищены\n";
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