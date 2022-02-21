#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>
#include "Header.h"

void inputAllMedicine() {
    std::cout << "Введіть R щоб перезаписати, чи щось інше щоб дописати: ";
    char mode;
    std::cin >> mode;
    std::ofstream file(allFileName, std::ios::binary | std::ios::out | ((mode == 'r' || mode == 'R') ? 0 : std::ios::app));

    bool inputLoop = true;
    while (inputLoop) {
        std::cout << "Введіть A щоб додати, чи щось інше щоб продовжити: ";
        std::cin >> mode;

        if (mode == 'a' || mode == 'A') {
            while (getchar() != '\n') {}
            Medicine* m = new Medicine();
            std::cout << "  Назва: ";
            std::getline(std::cin, m->name);

            std::string timeString;
            std::cout << "  Час (ГГ:ХХ): ";
            std::getline(std::cin, timeString);
            int divider = timeString.find(':', 0);

            std::cout << "  Років у закритому вигляді: ";
            std::cin >> m->years;

            m->hours = std::stoi(timeString.substr(0, divider));
            m->minutes = std::stoi(timeString.substr(divider + 1));
            file.write((char*)m, sizeof(Medicine));
            delete m;
        } else {
            inputLoop = false;
        }
    }
    file.close();
    if (!file.good()) {
        std::cout << "Були помилки!";
    }
}

void showAllMedicine(std::vector<Medicine*> m) {
    std::cout << "Кількість: " << m.size() << "\n\n";
    for (int i = 0; i < m.size(); i++) {
        std::cout << "  Назва: " << m[i]->name << '\n';
        std::cout << "  Годин після відкриття: " << m[i]->hours << '\n';
        std::cout << "  Хвилин після відкриття: " << m[i]->minutes << '\n';
        std::cout << "  Років в закритому вигляді: " << m[i]->years << '\n';
        std::cout << '\n';
    }
}

void inputOpenedMedicine(int dayTimestamp) {
    std::cout << "Введіть R щоб перезаписати, чи щось інше щоб дописати: ";
    char mode;
    std::cin >> mode;
    std::ofstream file(openedFileName, std::ios::binary | std::ios::out | ((mode == 'r' || mode == 'R') ? 0 : std::ios::app));

    bool inputLoop = true;
    while (inputLoop) {
        std::cout << "Введіть A щоб додати, чи щось інше щоб продовжити: ";
        std::cin >> mode;

        if (mode == 'a' || mode == 'A') {
            while (getchar() != '\n') {}
            OpenedMedicine* m = new OpenedMedicine();
            std::cout << "  Назва: ";
            std::getline(std::cin, m->name);

            std::string timeString;
            std::cout << "  Час (ГГ:ХХ): ";
            std::getline(std::cin, timeString);
            int divider = timeString.find(':', 0);
            m->openTimestamp = dayTimestamp + std::stoi(timeString.substr(0, divider)) * 60 + std::stoi(timeString.substr(divider + 1));

            file.write((char*)m, sizeof(OpenedMedicine));
            delete m;
        } else {
            inputLoop = false;
        }
    }
    file.close();
    if (!file.good()) {
        std::cout << "Були помилки!";
    }
}

void showOpenedMedicine(std::vector<OpenedMedicine*> m) {
    std::cout << "Кількість: " << m.size() << "\n\n";
    for (int i = 0; i < m.size(); i++) {
        std::cout << "  Назва: " << m[i]->name << "\n";
        int timestamp1 = m[i]->openTimestamp;
        int minutes = timestamp1 % 60;
        int hours = (timestamp1 / 60) % 24;
        int day = (timestamp1 / 60 / 24) % 365;
        int year = (timestamp1 / 60 / 24 / 365) + 1970;
        std::cout << "  Відкрито " << hours << ":" << minutes << " день " << day << " року " << year << "\n";

        int timestamp2 = m[i]->endTimestamp;
        minutes = timestamp2 % 60;
        hours = (timestamp2 / 60) % 24;
        day = (timestamp2 / 60 / 24) % 365;
        year = (timestamp2 / 60 / 24 / 365) + 1970;
        std::cout << "  Кінець придатності " << hours << ":" << minutes << " день " << day << " року " << year << "\n";
        std::cout << '\n';
    }
}

void removeExpired(int curTimestamp, std::vector<Medicine*>& m, std::vector<OpenedMedicine*>& m2) {
    std::cout << "Перевірка придатності:\n";
    for (int i = 0; i < m.size(); i++) {
        int found = -1;
        for (int j = 0; j < m2.size(); j++) {
            if (m[i]->name == m2[j]->name) found = j;
        }

        if (found == -1) {
            std::cout << "  " << m[i]->name << " не відкрито\n";
        } else {
            m2[found]->endTimestamp = m2[found]->openTimestamp + m[i]->minutes + m[i]->hours * 60;
            if (m2[found]->endTimestamp < curTimestamp) {
                std::cout << "  У " << m[i]->name << " скінчився срок придатності!\n";
                m.erase(m.begin() + i);
                m2.erase(m2.begin() + found);
                i--;
            } else {
                std::cout << "  " << m[i]->name << " відкрито\n";
            }
        }
    }
    std::cout << '\n';
}


void inputTimeDate(int& curMinute, int& curHour, int& curDay, int& curYear, int& curTimestamp, int& dayTimestamp) {
    std::cout << "Введіть теперішню дату і час:\n";
    std::cout << "  Рік: ";
    std::cin >> curYear;
    std::cout << "  День року: ";
    std::cin >> curDay;
    std::cout << "  Година: ";
    std::cin >> curHour;
    std::cout << "  Хвилина: ";
    std::cin >> curMinute;
    std::cout << "\n\n";
    curYear -= 1970;
    curTimestamp = curMinute + curHour * 60 + curDay * 60 * 24 + curYear * 60 * 24 * 365;
    dayTimestamp = curDay * 60 * 24 + curYear * 60 * 24 * 365;
}