#include "Numeral_16.h"

Numeral_16::Numeral_16(int newValue) {
	value = newValue;
}

Numeral_16::Numeral_16(char* newValue) {
	value = 0;
	int i = 0;
	while (newValue[i] != 0) {
		char c = newValue[i];
		int add = 0;
		if (c >= '0' && c <= '9') add = c - '0';
		if (c >= 'a' && c <= 'z') add = c - 'a' + 10;
		if (c >= 'A' && c <= 'Z') add = c - 'A' + 10;
		value = value * 16 + add;
		i++;
	}
}

Numeral_16::Numeral_16(std::string newValue) {
	value = 0;
	for(unsigned int i=0; i<newValue.size(); i++) {
		char c = newValue[i];
		int add = 0;
		if (c >= '0' && c <= '9') add = c - '0';
		if (c >= 'a' && c <= 'z') add = c - 'a' + 10;
		if (c >= 'A' && c <= 'Z') add = c - 'A' + 10;
		value = value * 16 + add;
	}
}

void Numeral_16::operator++(int a) {
	value++;
}

void Numeral_16::operator+=(int val) {
	value+=val;
}

Numeral_16 Numeral_16::operator+(Numeral_16 val) {
	return Numeral_16(value + val.toInt());
}

int Numeral_16::toInt() {
	return value;
}

std::string Numeral_16::toString() {
	const char* all = "0123456789ABCDEF";
	char str[9];
	int tempValue = value;
	for (int i = 7; i >= 0; i--) {
		str[i] = all[tempValue % 16];
		tempValue >>= 4;
	}
	str[8] = 0;
	return std::string(str);
}

std::ostream& operator<<(std::ostream& os, Numeral_16& n) {
	os << "0x" << n.toString();
	return os;
}