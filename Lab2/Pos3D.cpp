#include <iostream>
#include <math.h>

#include "Pos3D.h"
#include "Header.h"

double Pos3D::distanceTo(Pos3D b) {
    double dx = x - b.x;
    double dy = y - b.y;
    double dz = z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void Pos3D::setRandom() {
    x = random(-50, 50);
    y = random(-50, 50);
    z = random(-50, 50);
}

void Pos3D::showPos() {
    std::cout << x << " " << y << " " << z << "\n";
}