#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"

void fillFile(std::string name, std::string str) {
    std::ofstream file(name);
    if (!file) {
        std::cout << "Не вдалося записати в файл " << name;
    } else {
        file << str;
        file.close();
    }
}