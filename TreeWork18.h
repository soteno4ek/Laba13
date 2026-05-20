#pragma once
#include "BinaryTree.h"
#include "TreePrinter.h"
#include "Tester.h"

class TreeWork18 {
public:
    static void run() {
        int choice;
        do {
            std::cout << "\nTreeWork18. Дано дерево поиска и указатель корень дерева P1. Необходимо вывести второе "
                "максимальное значение в дереве. Решение должно иметь сложность по времени исполнения "
                "T(n) = O(log n), где n - число вершин в дереве\n\n";
            std::cout << "1. Ввести дерево вручную\n";
            std::cout << "2. Ввести дерево из файла\n";
            std::cout << "3. Сгенерировать случайное дерево\n";
            std::cout << "0. Назад\n";
            choice = Tester::getInt("Выберите способ: ");

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
                if (!root) {
                    std::cout << "Не удалось прочитать файл\n";
                    continue;
                }
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

            TreePrinter::print(root);

            try {
                int result = findSecondMax(root);
                std::cout << "Второй максимум: " << result << "\n";
            }
            catch (...) {
                std::cout << "Второй максимум не найден (в дереве менее 2 элементов)\n";
            }

            BinaryTree::clear(root);
        } while (choice != 0);
    }

private:
    static int findSecondMax(Node* root) {
        if (!root || (!root->left && !root->right)) throw std::exception();
        Node* curr = root;
        Node* prev = nullptr;
        while (curr->right) {
            prev = curr;
            curr = curr->right;
        }
        if (curr->left) {
            curr = curr->left;
            while (curr->right) curr = curr->right;
            return curr->data;
        }
        return prev->data;
    }
};