#include <iostream>
#include "fraction.h"

int main()
{
	setlocale(LC_ALL, "rus");

	Fraction first_fraction(4, 8);
	Fraction second_fraction(2, 6);

	std::cout << "Первая дробь: " << first_fraction;
	std::cout << "Вторая дробь: " << second_fraction << std::endl;

	std::cout << "Сложение: " << first_fraction + second_fraction;
	std::cout << "Вычитание: " << first_fraction - second_fraction;
	std::cout << "Умножение: " << first_fraction * second_fraction;
	std::cout << "Деление: " << first_fraction / second_fraction;

}
