/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/17/2018
**********************************************************/
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {
	class SuperHero : public Hero {
		
		int m_bonus;
		int m_defend;

	public:
		SuperHero();
		SuperHero(const char *, int, int, int, int);
		int attackStrength() const;
		int defend() const;
		bool isEmpty() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}


#endif