// Lab1-2.cpp
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Header.h"

const char* allFileName = "allMedicine.dat";
const char* openedFileName = "openedMedicine.dat";


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int curYear, curDay, curHour, curMinute, curTimestamp, dayTimestamp;
    inputTimeDate(curMinute, curHour, curDay, curYear, curTimestamp, dayTimestamp);

    std::vector<Medicine*> m = readAllMedicine();
    std::cout << "\nСписок всіх ліків:\n";
    showAllMedicine(m);

    inputAllMedicine();
    m = readAllMedicine();

    std::vector<OpenedMedicine*> m2 = readOpenedMedicine();
    calculateExpirationDates(m, m2);
    std::cout << "\nСписок відкритих ліків:\n";
    showOpenedMedicine(m2);

    m = readAllMedicine();
    m2 = readOpenedMedicine();
    removeExpired(curTimestamp, m, m2);
    resaveMedicine(m, m2);

    inputOpenedMedicine(dayTimestamp);

    system("pause");
}