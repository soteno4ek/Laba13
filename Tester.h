#pragma once
#include <iostream>
#include <string>
#include <cctype>

class Tester {
public:
    static int getInt(const std::string& prompt) {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::cin >> input;
            bool valid = true;
            for (char c : input) {
                if (!std::isdigit(c) && c != '-') {
                    valid = false;
                    break;
                }
            }
            if (valid && !input.empty()) {
                return std::stoi(input);
            }
            std::cout << "Ошибка: введите целое число\n";
        }
    }

    static std::string getString(const std::string& prompt) {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::cin >> input;
            bool valid = true;
            for (char c : input) {
                if (!std::isalpha(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid && !input.empty()) {
                return input;
            }
            std::cout << "Ошибка: введите только буквы\n";
        }
    }
};