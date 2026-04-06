#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Tester {
public:
    static int getInt(const std::string& str) {
        std::string value;
        while (true) {
            std::cout << str;
            std::cin >> value;

            bool letter = false;
            for (char c : value) {
                std::string digits = "1234567890";
                if (std::find(digits.begin(), digits.end(), c) != digits.end());
                else {
                    letter = true;
                    break;
                }
            }

            if (!letter) {
                return std::stoi(value);
            }

            std::cout << "Ошибка: введите целое число.\n";
        }
    }

    static std::string getString(const std::string& str) {
        std::string value;
        while (true) {
            std::cout << str;
            std::cin >> value;

            bool digit = false;
            for (char c : value) {
                std::string text = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
                if (std::find(text.begin(), text.end(), c) != text.end());
                else {
                    digit = true;
                    break;
                }
            }

            if (!digit) {
                return value;
            }

            std::cout << "Ошибка: введите слова (только строчные и заглавные анлийские буквы).\n";
        }
    }
};
