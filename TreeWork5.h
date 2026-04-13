#pragma once
#include "BinaryTree.h"
#include "TreePrinter.h"
#include "Tester.h"

class TreeWork5 {
public:
    static void run() {
        int choice;
        do {
            std::cout << "\nTreeWork5. Дано бинарное дерево и указатель корень дерева P1. Необходимо вывести "
                "содержимое листьев дерева, перечисляя их справа налево\n\n";
            std::cout << "1. Ввести дерево вручную\n";
            std::cout << "2. Ввести дерево из файла\n";
            std::cout << "3. Сгенерировать случайное дерево\n";
            std::cout << "0. Назад\n";
            choice = Tester::getInt("Выберите способ ввода: ");

            if (choice == 0) break;

            Node* root = nullptr;

            if (choice == 1) {
                int n = Tester::getInt("Сколько элементов в дереве? ");
                std::cout << "Введите значения (уникальные):\n";
                for (int i = 0; i < n; ++i) {
                    int val = Tester::getInt("> ");
                    root = BinaryTree::insertBST(root, val);
                }
            }
            else if (choice == 2) {
                root = BinaryTree::buildFromFile();
            }
            else if (choice == 3) {
                int n = Tester::getInt("Сколько элементов сгенерировать? ");
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

            std::cout << "\nДерево до выполнения:\n";
            TreePrinter::print(root);

            std::cout << "Листья справа налево: ";
            printLeaves(root);
            std::cout << "\n";

            BinaryTree::clear(root);
        } while (choice != 0);
    }

private:
    static void printLeaves(Node* node) {
        if (!node) return;
        if (!node->left && !node->right) {
            std::cout << node->data << " ";
            return;
        }
        printLeaves(node->right);
        printLeaves(node->left);
    }
};