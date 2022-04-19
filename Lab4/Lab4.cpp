#include <iostream>
#include <Windows.h>

#include "Header.h"
#include "Vector2.h"
#include "Vector3.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "ЛАБОРАТОРНА РОБОТА 4\n\n";

    Vector2 vec2A(1);
    Vector2 vec2B(2);
    Vector2 vec2C(3);

    Vector3 vec3A(1);
    Vector3 vec3B(2);
    Vector3 vec3C(3);
    Vector3 vec3D(4);

    double sum1 = 0;
    if (vec2B.isParalellTo(vec2A)) sum1 += vec2B.getLength();
    if (vec2C.isParalellTo(vec2A)) sum1 += vec2C.getLength();
    if (vec3A.isParalellTo(vec2A)) sum1 += vec3A.getLength();
    if (vec3B.isParalellTo(vec2A)) sum1 += vec3B.getLength();
    if (vec3C.isParalellTo(vec2A)) sum1 += vec3C.getLength();
    if (vec3D.isParalellTo(vec2A)) sum1 += vec3D.getLength();

    std::cout << "Сумма довжин векторів що паралельні першому 2Д вектору: " << sum1 << "\n";

    Vector3 sum2;
    if (vec2A.isPerpendicularTo(vec3A)) sum2 += vec2A;
    if (vec2B.isPerpendicularTo(vec3A)) sum2 += vec2B;
    if (vec2C.isPerpendicularTo(vec3A)) sum2 += vec2C;
    if (vec3B.isPerpendicularTo(vec3A)) sum2 += vec3B;
    if (vec3C.isPerpendicularTo(vec3A)) sum2 += vec3C;
    if (vec3D.isPerpendicularTo(vec3A)) sum2 += vec3D;
    
    std::cout << "Сумма векторів що перпендикулярні першому 3Д вектору: " << sum2 << "\n";
}