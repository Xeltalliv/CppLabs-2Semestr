#include <iostream>
#include <Windows.h>
#include <math.h>
#include "Header.h"
#include "Pos3D.h"
#include "Cone.h"
#include "ConeOperations.h"

const int coneCount = 20;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "����������� ������ 2\n\n";
    Cone cones[coneCount];
    randomizeCones(cones);
    displayCones(cones);

    int maxIndex  = findMax(cones);
    std::cout << "�������� ����� �� ����� �" << maxIndex;
}

double random(int a, int b) {
    return double(a + rand() % (b - a + 1));
}