#include <iostream>

class Numeral_16 {
	int value;
public:
	Numeral_16(int);
	Numeral_16(char*);
	Numeral_16(std::string);
	void operator++(int);
	void operator+=(int);
	Numeral_16 operator+(Numeral_16);
	int toInt();
	std::string toString();
};