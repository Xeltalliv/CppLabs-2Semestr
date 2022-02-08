// Lab1.cpp
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector>

void fillFile(std::string, std::string);
std::string enterFromKeyboard();
void fillOtherFiles(std::string, std::vector<std::string>&, std::vector<std::string>&);
std::string sortWords(std::vector<std::string>&);
std::string sortRows(std::vector<std::string>&);
void sort(std::vector<std::string>&);
std::string join(std::vector<std::string>&, std::string);

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

void fillFile(std::string name, std::string str) {
    std::ofstream file(name);
    if (!file) {
        std::cout << "Не вдалося записати в файл " << name;
    } else {
        file << str;
        file.close();
    }
}

std::string enterFromKeyboard() {
    std::cout << "Вводьте текст, а потім натисніть ESC:\n";
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

void fillOtherFiles(std::string str, std::vector<std::string> &fileA, std::vector<std::string> &fileB) {
    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    bool toA = true;
    while ((pos = str.find('\n', prev)) != std::string::npos) {
        if (toA) {
            fileA.push_back(str.substr(prev, pos - prev));
        } else {
            fileB.push_back(str.substr(prev, pos - prev));
        }
        prev = pos + 1;
        toA = !toA;
    }
    if (toA) {
        fileA.push_back(str.substr(prev, pos - prev));
    } else {
        fileB.push_back(str.substr(prev, pos - prev));
    }
}

std::string sortWords(std::vector<std::string>& arr) {
    std::string result = "";
    for (int i = 0; i < arr.size(); i++) {
        std::string str = arr[i];
        std::vector<std::string> words;
        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        while ((pos = str.find(' ', prev)) != std::string::npos) {
            words.push_back(str.substr(prev, pos - prev));
            prev = pos + 1;
        }
        words.push_back(str.substr(prev, pos - prev));

        sort(words);
        result += ((i > 0) ? "\n" : "") + join(words, " ");
    }
    return result;
}

void sort(std::vector<std::string>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int k = i;
        while(k > 0 && arr[k] < arr[k - 1]) {
            std::string tmp = arr[k];
            arr[k] = arr[k - 1];
            arr[k - 1] = tmp;
            k--;
        }
    }
}

std::string join(std::vector<std::string>& arr, std::string del) {
    std::string result = "";
    for (int i = 0; i < arr.size(); i++) {
        result += ((i > 0) ? del : "") + arr[i];
    }
    return result;
}

std::string sortRows(std::vector<std::string>& rows) {
    sort(rows);
    return join(rows, "\n");
}