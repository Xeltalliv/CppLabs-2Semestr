#include <math.h>
#include <iostream>
#include "Header.h"
#include "Vector2.h"

Vector2::Vector2() {
	x = y = 0;
}

Vector2::Vector2(int n) {
	std::cout << "Введіть 2D вектор №" << n << ":\n";
	std::cout << " X: ";
	std::cin >> x;
	std::cout << " Y: ";
	std::cin >> y;
	std::cout << "\n";
}

double Vector2::getLength() {
	return sqrt(x * x + y * y);
}

bool Vector2::isParalellTo(TVector &other) {
	return fabs(normalizeAndDot(other) - 1.0) < EPSILON;
}

bool Vector2::isPerpendicularTo(TVector &other) {
	return fabs(normalizeAndDot(other)) < EPSILON;
}

double Vector2::normalizeAndDot(TVector &other) {
	double len1 = getLength();
	if (len1 == 0.0) len1 = 1.0; // Не ділити на 0
	double x1n = x / len1;
	double y1n = y / len1;

	double len2 = other.getLength();
	if (len2 == 0.0) len2 = 1.0; // Не ділити на 0
	double x2n = other.getElem(0) / len2;
	double y2n = other.getElem(1) / len2;

	return x1n * x2n + y1n * y2n;
}

double Vector2::getElem(int n) {
	if (n == 0) return x;
	if (n == 1) return y;
	return 0;
}

void Vector2::operator+=(TVector& other) {
	x += other.getElem(0);
	y += other.getElem(2);
}