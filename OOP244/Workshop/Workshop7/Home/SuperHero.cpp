/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/17/2018
**********************************************************/
#include <iostream>
#include <cstring>
#include "SuperHero.h"

using namespace std;
namespace sict {

	SuperHero::SuperHero() : Hero() {
		m_bonus = 0;
		m_defend = 0;

	}

	SuperHero::SuperHero(const char *Name, int health, int attack, int bonus, int defend) : Hero(Name, health, attack) {
		//Hero::Hero(Name, health, attack); - is it different??
		m_bonus = bonus;
		m_defend = defend;

	}

	int SuperHero::attackStrength() const {
		return isEmpty() ? 0 : Hero::attackStrength() + m_bonus;
	}

	int SuperHero::defend() const {
		return isEmpty() ? 0 : m_defend;
	}

	bool SuperHero::isEmpty() const {
		return m_bonus == 0 || m_defend == 0;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		SuperHero First = first;
		SuperHero Second = second;

		cout << "Super Fight! " << first << " vs " << second << " : ";
		int count = 0;

		while (First.isAlive() && Second.isAlive()) {
			First -= Second.attackStrength() - First.defend();
			Second -= First.attackStrength() - Second.defend();
			count++;
		}

		if (First.isAlive()) {

			cout << "Winner is " << First << " in " << count << " rounds." << endl;
			return first;

		}
		else {
			cout << "Winner is " << Second << " in " << count << " rounds." << endl;
			return second;
		}
	}

}