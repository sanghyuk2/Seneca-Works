/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 6/20/2018
**********************************************************/
// TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;

namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		Numerator = 0;
		Denominator = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator) {
		if (numerator >= 0 && denominator > 0) {
			Numerator = numerator;
			Denominator = denominator;
			reduce();
		}
		else
			*this = Fraction();
	}
	// TODO: implement the max query
	int Fraction::max() const {
		if (Numerator > Denominator) {
			return Numerator;
		}
		else
			return Denominator;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		if (Numerator > Denominator) {
			return Denominator;
		}
		else
			return Numerator;

	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int temp = gcd();
		Numerator = Numerator / temp;
		Denominator = Denominator / temp;
	}

	// TODO: implement the display query
	void Fraction::display() const {
		if (!isEmpty()) {
			if (Denominator == 1)
				cout << Numerator;
			else
				cout << Numerator << "/" << Denominator;
		}
		else
			cout << "no fraction stored";


	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		return Numerator == 0 && Denominator == 0;
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction sum;
		if (!isEmpty() || !rhs.isEmpty()) {
			sum.Denominator = Denominator * rhs.Denominator;
			sum.Numerator = (Numerator * rhs.Denominator) + (Denominator * rhs.Numerator);
		}
		return sum;

	}
	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction multiply;
		if (!isEmpty() && !rhs.isEmpty()) {
			multiply.Denominator = Denominator * rhs.Denominator;
			multiply.Numerator = Numerator * rhs.Numerator;
			multiply.reduce();
			return multiply;
		}
		else
			return multiply;
	}

	bool Fraction::operator==(const Fraction& rhs) const {
		if (!isEmpty() && !rhs.isEmpty()) {
			if ((Denominator == rhs.Denominator) && (Numerator == rhs.Numerator)) 
				return true;
			else
				return false;
		}
		else
			return false;
		
	}

	bool Fraction::operator!=(const Fraction& rhs) const {
		if (!isEmpty() && !rhs.isEmpty()) {
			if ((Denominator != rhs.Denominator) && (Numerator != rhs.Numerator))
				return true;
			else
				return false;
		}
		else
			return false;
	}

	Fraction Fraction::operator+=(const Fraction& rhs) { 
		if (!isEmpty() && !rhs.isEmpty()) {
			*this = *this + rhs;
			return *this;
		}
		else {
			*this = Fraction();
			 return *this;
		}
	}
}