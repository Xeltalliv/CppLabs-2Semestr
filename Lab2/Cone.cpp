#include <iostream>

#include "Pos3D.h"
#include "Cone.h"
#include "Header.h"

void Cone::setRandom() {
    base.setRandom();
    top.setRandom();
    radius = random(1, 5);
}

double Cone::calcTvirna() {
    return sqrt(base.distanceTo(top));
}

void Cone::showInfo(int i) {
    std::cout << " Конус №" << i << ":\n";
    std::cout << "  Радіус основи: " << radius << "\n";
    std::cout << "  Центр основи: ";
    base.showPos();
    std::cout << "  Вершина: ";
    top.showPos();
    std::cout << "  Твірна: " << calcTvirna() << "\n";
    std::cout << "\n";
}