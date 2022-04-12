#include <iostream>
#include "Header.h"
#include "Pos3D.h"
#include "Cone.h"
#include "ConeOperations.h"

void randomizeCones(Cone* cones) {
    srand(static_cast<int>(time(0)));
    for (int i = 0; i < coneCount; i++) {
        cones[i].setRandom();
    }
}

void displayCones(Cone* cones) {
    std::cout << "Конуси:\n";
    for (int i = 0; i < coneCount; i++) {
        cones[i].showInfo(i);
    }
}

int findMax(Cone* cones) {
    double maxVal = 0;
    int maxIndex = -1;
    for (int i = 0; i < coneCount; i++) {
        double val = cones[i].calcTvirna();
        if (val > maxVal) {
            maxVal = val;
            maxIndex = i;
        }
    }
    return maxIndex;
}