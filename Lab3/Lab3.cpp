#include <Windows.h>
#include "Numeral_16.h"

std::ostream& operator<<(std::ostream&, Numeral_16&);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Numeral_16 N1(12);
    Numeral_16 N2("1f");
    Numeral_16 N3(std::string("A0"));
    std::cout << "������ �������� �������� �� 12, \"1f\" �� \"A0\"\n";
    std::cout << "N1: " << N1 << "\n";
    std::cout << "N2: " << N2 << "\n";
    std::cout << "N3: " << N3 << "\n";

    std::cout << "\nϳ��� N1++\n";
    N1++;
    std::cout << "N1: " << N1 << "\n";

    std::cout << "\nϳ��� N2+=4\n";
    N2 += 4;
    std::cout << "N2: " << N2 << "\n";

    std::cout << "\nϳ��� N3 = N1 + N2\n";
    N3 = N1 + N2;
    std::cout << "N3: " << N3 << "\n";
}