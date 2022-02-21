#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Header.h"

std::vector<Medicine*> readAllMedicine() {
    std::vector<Medicine*> allMedicine;

    std::ifstream file(allFileName, std::ios::binary | std::ios::out);
    if (!file) {
        std::cout << "Файл " << allFileName << " не знайдено!\n\n";
        return allMedicine;
    }


    int i = 0;
    while (file.peek() != EOF) {
        Medicine* m = new Medicine();
        file.read((char*)m, sizeof(Medicine));
        allMedicine.push_back(m);
        i++;
    }
    return allMedicine;
}

std::vector<OpenedMedicine*> readOpenedMedicine() {
    std::vector<OpenedMedicine*> openedMedicine;

    std::ifstream file(openedFileName, std::ios::binary | std::ios::out);
    if (!file) {
        std::cout << "Файл " << openedFileName << " не знайдено\n\n";
        return openedMedicine;
    }


    int i = 0;
    while (file.peek() != EOF) {
        OpenedMedicine* m = new OpenedMedicine();
        file.read((char*)m, sizeof(OpenedMedicine));
        openedMedicine.push_back(m);
        i++;
    }
    return openedMedicine;
}

void resaveMedicine(std::vector<Medicine*>& m, std::vector<OpenedMedicine*>& m2) {
    std::ofstream file(allFileName, std::ios::binary | std::ios::out);
    for (int i = 0; i < m.size(); i++) {
        file.write((char*)m[i], sizeof(Medicine));
    }
    file.close();
    std::ofstream file2(openedFileName, std::ios::binary | std::ios::out);
    for (int i = 0; i < m2.size(); i++) {
        file2.write((char*)m2[i], sizeof(OpenedMedicine));
    }
    file2.close();
}