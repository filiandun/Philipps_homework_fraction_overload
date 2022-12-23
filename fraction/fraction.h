#pragma once
#include <iostream>

#define SHORTEN_FRACTION // чтобы убрать сокращение дроби


class Fraction
{
public:
	Fraction();
	Fraction(int numerator, int denominator);

	~Fraction();

private:
	int numerator = 1;
	int denominator = 1;

	void shorten_fraction(Fraction& f);
public:

	Fraction operator+(const Fraction& f);
	Fraction operator-(const Fraction& f);
	Fraction operator*(const Fraction& f);
	Fraction operator/(const Fraction& f);

	friend std::ostream& operator<<(std::ostream &output, const Fraction& f);
};

