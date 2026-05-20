#pragma once
#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

class TreePrinter {
public:
    static void print(Node* root) {
        if (!root) {
            std::cout << "Дерево пустое\n";
            return;
        }

        int height = getHeight(root);
        int width = (1 << height) * 4;
        std::vector<std::string> canvas(height * 2, std::string(width, ' '));

        drawNode(root, canvas, 0, width / 2, height);

        std::cout << "\n";
        for (const auto& line : canvas) {
            std::string trimmed = line;
            size_t last = trimmed.find_last_not_of(' ');
            if (last != std::string::npos) {
                std::cout << trimmed.substr(0, last + 1) << "\n";
            }
        }
        std::cout << "\n";
    }

private:
    static int getHeight(Node* node) {
        if (!node) return 0;
        return 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    static void drawNode(Node* node, std::vector<std::string>& canvas, int row, int col, int maxDepth) {
        if (!node || row >= (int)canvas.size()) return;

        std::string val = std::to_string(node->data);
        int valLen = val.length();
        int startX = col - valLen / 2;

        for (int i = 0; i < valLen; ++i) {
            if (startX + i >= 0 && startX + i < (int)canvas[row].length()) {
                canvas[row][startX + i] = val[i];
            }
        }

        if (row + 1 < (int)canvas.size() && (node->left || node->right)) {
            int currentDepth = row / 2;
            int offset = std::max(1, (int)pow(2, maxDepth - currentDepth - 2));

            if (node->left) {
                int childCol = col - offset;
                if (childCol >= 0) {
                    canvas[row + 1][(col + childCol) / 2] = '/';
                    drawNode(node->left, canvas, row + 2, childCol, maxDepth);
                }
            }

            if (node->right) {
                int childCol = col + offset;
                if (childCol < (int)canvas[row].length()) {
                    canvas[row + 1][(col + childCol) / 2] = '\\';
                    drawNode(node->right, canvas, row + 2, childCol, maxDepth);
                }
            }
        }
    }
};