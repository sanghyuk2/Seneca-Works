/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/17/2018
**********************************************************/
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;

namespace sict {
	Hero::Hero() {
		m_Name[0] = '\0';
		m_health = 0;
		m_strength = 0;
	}

	Hero::Hero(const char* Name, int Health, int Strength) {
		if(Name[0] != '\0' && Health > 0 && Strength > 0) {
			strncpy(m_Name, Name, max_length);
			m_Name[max_length] = '\0';
			m_health = Health;
			m_strength = Strength;
		}else
			*this = Hero();
		
		
	}

	void Hero::operator-=(int attack) {
		if (attack > 0) {
			m_health = m_health - attack;
		}
		else if (m_health < 0) {
			m_health = 0;
		}
	}

	bool Hero::isAlive() const {
		return m_health > 0;

	}

	int Hero::attackStrength() const {
		return m_strength;

	}



	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (hero.m_Name[0] == '\0') {
			os << "No hero";
			return os;
		}
		else {
			os << hero.m_Name;
			return os;
		}
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero First = first;
		Hero Second = second;

		cout << "Ancient Battle! " << first << " vs " << second << " : ";
		int count = 0;

		while (First.isAlive() && Second.isAlive()) {
			First -= (Second.attackStrength());
			Second -= (First.attackStrength());
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






