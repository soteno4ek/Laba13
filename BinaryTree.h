#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    static void clear(Node* root) {
        if (!root) return;
        clear(root->left);
        clear(root->right);
        delete root;
    }

    static Node* insertBST(Node* root, int val) {
        if (!root) return new Node(val);
        if (val < root->data) root->left = insertBST(root->left, val);
        else root->right = insertBST(root->right, val);
        return root;
    }

    static Node* buildManual() {
        int val;
        std::cout << "Введите корень (-1 для выхода): ";
        std::cin >> val;
        if (val == -1) return nullptr;
        Node* root = new Node(val);
        buildRecursive(root);
        return root;
    }

    static Node* buildFromFile() {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        std::ifstream file(filename);
        if (!file.is_open()) return nullptr;
        Node* root = nullptr;
        int val;
        while (file >> val) root = insertBST(root, val);
        return root;
    }

    static Node* buildRandom(int n) {
        Node* root = nullptr;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(10, 99);
        for (int i = 0; i < n; ++i) root = insertBST(root, dis(gen));
        return root;
    }

private:
    static void buildRecursive(Node* node) {
        int lVal, rVal;
        std::cout << "Левый потомок для " << node->data << " (-1 если нет): ";
        std::cin >> lVal;
        if (lVal != -1) {
            node->left = new Node(lVal);
            buildRecursive(node->left);
        }
        std::cout << "Правый потомок для " << node->data << " (-1 если нет): ";
        std::cin >> rVal;
        if (rVal != -1) {
            node->right = new Node(rVal);
            buildRecursive(node->right);
        }
    }
};