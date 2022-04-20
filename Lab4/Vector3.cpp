#include <math.h>
#include <iostream>
#include "Header.h"
#include "Vector3.h"

Vector3::Vector3() {
	x = y = z = 0;
}

Vector3::Vector3(int n) {
	std::cout << "Введіть 3D вектор №" << n << ":\n";
	std::cout << " X: ";
	std::cin >> x;
	std::cout << " Y: ";
	std::cin >> y;
	std::cout << " Z: ";
	std::cin >> z;
	std::cout << "\n";
}

double Vector3::getLength() {
	return sqrt(x * x + y * y + z * z);
}

bool Vector3::isParalellTo(TVector &other) {
	return fabs(normalizeAndDot(other) - 1.0) < EPSILON;
}

bool Vector3::isPerpendicularTo(TVector &other) {
	return fabs(normalizeAndDot(other)) < EPSILON;
}

double Vector3::normalizeAndDot(TVector &other) {
	double len1 = getLength();
	if (len1 == 0.0) len1 = 1.0; // Не ділити на 0
	double x1n = x / len1;
	double y1n = y / len1;
	double z1n = z / len1;

	double len2 = other.getLength();
	if (len2 == 0.0) len2 = 1.0; // Не ділити на 0
	double x2n = other.getElem(0) / len2;
	double y2n = other.getElem(1) / len2;
	double z2n = other.getElem(2) / len2;

	return x1n * x2n + y1n * y2n + z1n * z2n;
}

double Vector3::getElem(int n) {
	if (n == 0) return x;
	if (n == 1) return y;
	if (n == 2) return z;
	return 0;
}

void Vector3::operator+=(TVector& other) {
	x += other.getElem(0);
	y += other.getElem(1);
	z += other.getElem(2);
}

std::ostream& operator<<(std::ostream& os, Vector3& n) {
	os << n.getElem(0) << " " << n.getElem(1) << " " << n.getElem(2);
	return os;
}