#pragma once
#include "BinaryTree.h"
#include "TreePrinter.h"
#include "Tester.h"

class TreeWork16 {
public:
    static void run() {
        int choice;
        do {
            std::cout << "\nTreeWork16. Дано число N (> 0) и набор из N чисел. Отсортировать исходный набор чисел, "
                "создав для него дерево поиска. Вывести указатель P1 на корень полученного дерева, а также "
                "отсортированный набор чисел (для вывода набора чисел выполнить перебор вершин дерева в "
                "инфиксном порядке)\n\n";
            std::cout << "1. Ввести числа вручную\n";
            std::cout << "2. Прочитать числа из файла\n";
            std::cout << "3. Сгенерировать случайный набор\n";
            std::cout << "0. Назад\n";
            choice = Tester::getInt("Выберите способ: ");

            if (choice == 0) break;

            Node* root = nullptr;

            if (choice == 1) {
                int n = Tester::getInt("Введите количество чисел N: ");
                std::cout << "Введите числа:\n";
                for (int i = 0; i < n; ++i) {
                    int val = Tester::getInt("> ");
                    root = BinaryTree::insertBST(root, val);
                }
            }
            else if (choice == 2) {
                root = BinaryTree::buildFromFile();
                if (!root) {
                    std::cout << "Не удалось прочитать файл\n";
                    continue;
                }
            }
            else if (choice == 3) {
                int n = Tester::getInt("Введите количество чисел N: ");
                root = BinaryTree::buildRandom(n);
            }
            else {
                std::cout << "Неверный выбор\n";
                continue;
            }

            if (!root) {
                std::cout << "Дерево пусто\n";
                continue;
            }

            std::cout << "\nУказатель P1: " << root << "\n";
            std::cout << "Структура дерева:\n";
            TreePrinter::print(root);

            std::cout << "Отсортированный набор: ";
            inorder(root);
            std::cout << "\n";

            BinaryTree::clear(root);
        } while (choice != 0);
    }

private:
    static void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
};