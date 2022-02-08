#include <iostream>
#include <conio.h>
#include <vector>
#include "Header.h"

std::string enterFromKeyboard() {
    std::cout << "¬водьте текст, а пот≥м натисн≥ть ESC:\n";
    std::string str = "";
    char ch;
    while ((ch = _getch()) != 27) {
        std::cout << ch;
        if (ch == '\r') {
            std::cout << '\n';
            str += '\n';
        } else if (ch == '\b') {
            std::cout << ' ' << '\b';
            str.pop_back();
        } else {
            str += ch;
        }
    }
    std::cout << "\n\n";
    return str;
}