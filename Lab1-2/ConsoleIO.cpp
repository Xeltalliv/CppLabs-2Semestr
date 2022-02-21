#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <fstream>
#include "Header.h"

void inputAllMedicine() {
    std::cout << "������ R ��� ������������, �� ���� ���� ��� ��������: ";
    char mode;
    std::cin >> mode;
    std::ofstream file(allFileName, std::ios::binary | std::ios::out | ((mode == 'r' || mode == 'R') ? 0 : std::ios::app));

    bool inputLoop = true;
    while (inputLoop) {
        std::cout << "������ A ��� ������, �� ���� ���� ��� ����������: ";
        std::cin >> mode;

        if (mode == 'a' || mode == 'A') {
            while (getchar() != '\n') {}
            Medicine* m = new Medicine();
            std::cout << "  �����: ";
            std::getline(std::cin, m->name);

            std::string timeString;
            std::cout << "  ��� (��:��): ";
            std::getline(std::cin, timeString);
            int divider = timeString.find(':', 0);

            std::cout << "  ���� � ��������� ������: ";
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
        std::cout << "���� �������!";
    }
}

void showAllMedicine(std::vector<Medicine*> m) {
    std::cout << "ʳ������: " << m.size() << "\n\n";
    for (int i = 0; i < m.size(); i++) {
        std::cout << "  �����: " << m[i]->name << '\n';
        std::cout << "  ����� ���� ��������: " << m[i]->hours << '\n';
        std::cout << "  ������ ���� ��������: " << m[i]->minutes << '\n';
        std::cout << "  ���� � ��������� ������: " << m[i]->years << '\n';
        std::cout << '\n';
    }
}

void inputOpenedMedicine(int dayTimestamp) {
    std::cout << "������ R ��� ������������, �� ���� ���� ��� ��������: ";
    char mode;
    std::cin >> mode;
    std::ofstream file(openedFileName, std::ios::binary | std::ios::out | ((mode == 'r' || mode == 'R') ? 0 : std::ios::app));

    bool inputLoop = true;
    while (inputLoop) {
        std::cout << "������ A ��� ������, �� ���� ���� ��� ����������: ";
        std::cin >> mode;

        if (mode == 'a' || mode == 'A') {
            while (getchar() != '\n') {}
            OpenedMedicine* m = new OpenedMedicine();
            std::cout << "  �����: ";
            std::getline(std::cin, m->name);

            std::string timeString;
            std::cout << "  ��� (��:��): ";
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
        std::cout << "���� �������!";
    }
}

void showOpenedMedicine(std::vector<OpenedMedicine*> m) {
    std::cout << "ʳ������: " << m.size() << "\n\n";
    for (int i = 0; i < m.size(); i++) {
        std::cout << "  �����: " << m[i]->name << "\n";
        int timestamp1 = m[i]->openTimestamp;
        int minutes = timestamp1 % 60;
        int hours = (timestamp1 / 60) % 24;
        int day = (timestamp1 / 60 / 24) % 365;
        int year = (timestamp1 / 60 / 24 / 365) + 1970;
        std::cout << "  ³������ " << hours << ":" << minutes << " ���� " << day << " ���� " << year << "\n";

        int timestamp2 = m[i]->endTimestamp;
        minutes = timestamp2 % 60;
        hours = (timestamp2 / 60) % 24;
        day = (timestamp2 / 60 / 24) % 365;
        year = (timestamp2 / 60 / 24 / 365) + 1970;
        std::cout << "  ʳ���� ���������� " << hours << ":" << minutes << " ���� " << day << " ���� " << year << "\n";
        std::cout << '\n';
    }
}

void removeExpired(int curTimestamp, std::vector<Medicine*>& m, std::vector<OpenedMedicine*>& m2) {
    std::cout << "�������� ����������:\n";
    for (int i = 0; i < m.size(); i++) {
        int found = -1;
        for (int j = 0; j < m2.size(); j++) {
            if (m[i]->name == m2[j]->name) found = j;
        }

        if (found == -1) {
            std::cout << "  " << m[i]->name << " �� �������\n";
        } else {
            m2[found]->endTimestamp = m2[found]->openTimestamp + m[i]->minutes + m[i]->hours * 60;
            if (m2[found]->endTimestamp < curTimestamp) {
                std::cout << "  � " << m[i]->name << " �������� ���� ����������!\n";
                m.erase(m.begin() + i);
                m2.erase(m2.begin() + found);
                i--;
            } else {
                std::cout << "  " << m[i]->name << " �������\n";
            }
        }
    }
    std::cout << '\n';
}


void inputTimeDate(int& curMinute, int& curHour, int& curDay, int& curYear, int& curTimestamp, int& dayTimestamp) {
    std::cout << "������ �������� ���� � ���:\n";
    std::cout << "  г�: ";
    std::cin >> curYear;
    std::cout << "  ���� ����: ";
    std::cin >> curDay;
    std::cout << "  ������: ";
    std::cin >> curHour;
    std::cout << "  �������: ";
    std::cin >> curMinute;
    std::cout << "\n\n";
    curYear -= 1970;
    curTimestamp = curMinute + curHour * 60 + curDay * 60 * 24 + curYear * 60 * 24 * 365;
    dayTimestamp = curDay * 60 * 24 + curYear * 60 * 24 * 365;
}