#include "fraction.h"


Fraction::Fraction()
{
	this->numerator = 1;
	this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	if (denominator != 0) // на ноль делить нельзя
	{
		this->denominator = denominator;
	}
	else
	{
		this->denominator = 1;
	}
}

Fraction::~Fraction() {}



void Fraction::shorten_fraction(Fraction& f)
{
	for (int i = 1; i <= f.numerator && i <= f.denominator; ++i)
	{
		if ((f.numerator % i == 0) && (f.denominator % i == 0))
		{
			f.numerator /= i;
			f.denominator /= i;
		}
	}
}


Fraction Fraction::operator+(const Fraction& f)
{
	Fraction addition;

	addition.numerator = this->numerator * f.denominator + f.numerator * this->denominator;
	addition.denominator = this->denominator * f.denominator;

	shorten_fraction(addition);

	#ifdef SHORTEN_FRACTION 
		shorten_fraction(addition); // сокращение дроби
	#endif

	return addition;
}


Fraction Fraction::operator-(const Fraction& f)
{
	Fraction substraction;

	substraction.numerator = this->numerator * f.denominator - f.numerator * this->denominator;
	substraction.denominator = this->denominator * f.denominator;

	#ifdef SHORTEN_FRACTION 
		shorten_fraction(substraction); // сокращение дроби
	#endif

	return substraction;
}


Fraction Fraction::operator*(const Fraction& f)
{
	Fraction multiplication;

	multiplication.numerator = this->numerator * f.numerator;
	multiplication.denominator = this->denominator * f.denominator;

	#ifdef SHORTEN_FRACTION 
		shorten_fraction(multiplication); // сокращение дроби
	#endif

	return multiplication;
}


Fraction Fraction::operator/(const Fraction& f)
{
	Fraction division;

	division.numerator = this->numerator * f.denominator;
	division.denominator = this->denominator * f.numerator;
	
	#ifdef SHORTEN_FRACTION 
		shorten_fraction(division); // сокращение дроби
	#endif


	return division;
}


std::ostream& operator<<(std::ostream& output, const Fraction& f)
{
	output << f.numerator << "/" << f.denominator << std::endl;

	return output;
}
