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
    std::cout << " ����� �" << i << ":\n";
    std::cout << "  ����� ������: " << radius << "\n";
    std::cout << "  ����� ������: ";
    base.showPos();
    std::cout << "  �������: ";
    top.showPos();
    std::cout << "  �����: " << calcTvirna() << "\n";
    std::cout << "\n";
}