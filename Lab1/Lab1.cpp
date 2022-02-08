// Lab1.cpp
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Header.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str = enterFromKeyboard();

    std::cout << "Вихідний файл:\n" << str << "\n\n\n";

    std::vector<std::string> fileA;
    std::vector<std::string> fileB;
    fillOtherFiles(str, fileA, fileB);

    std::cout << "Необроблений непарний файл:\n" << join(fileA, "\n") << "\n\n\n";
    std::cout << "Необроблений парний файл:\n" << join(fileB, "\n") << "\n\n\n";

    std::string fileAjoined = sortWords(fileA);
    std::cout << "Непарний файл з відсортованими словами в кожному рядку: \n" << fileAjoined << "\n\n\n";

    std::string fileBjoined = sortRows(fileB);
    std::cout << "Парний файл з відсортованими рядками: \n" << fileBjoined << "\n\n\n";

    fillFile("main.txt", str);
    fillFile("odd.txt", fileAjoined);
    fillFile("even.txt", fileBjoined);
}