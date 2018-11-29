/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/17/2018
**********************************************************/
#ifndef SICT_HERO_H
#define SICT_HERO_H


namespace sict {

	const int max_rounds = 100;
	const int max_length = 41;

	class Hero {

		char m_Name[max_length];
		int m_health;
		int m_strength;

	public:
		Hero();
		Hero(const char*, int, int);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !SICT_HERO_H

