// Lab1.cpp
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Header.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str = enterFromKeyboard();

    std::cout << "�������� ����:\n" << str << "\n\n\n";

    std::vector<std::string> fileA;
    std::vector<std::string> fileB;
    fillOtherFiles(str, fileA, fileB);

    std::cout << "������������ �������� ����:\n" << join(fileA, "\n") << "\n\n\n";
    std::cout << "������������ ������ ����:\n" << join(fileB, "\n") << "\n\n\n";

    std::string fileAjoined = sortWords(fileA);
    std::cout << "�������� ���� � ������������� ������� � ������� �����: \n" << fileAjoined << "\n\n\n";

    std::string fileBjoined = sortRows(fileB);
    std::cout << "������ ���� � ������������� �������: \n" << fileBjoined << "\n\n\n";

    fillFile("main.txt", str);
    fillFile("odd.txt", fileAjoined);
    fillFile("even.txt", fileBjoined);
}