#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"

void fillFile(std::string name, std::string str) {
    std::ofstream file(name);
    if (!file) {
        std::cout << "�� ������� �������� � ���� " << name;
    } else {
        file << str;
        file.close();
    }
}