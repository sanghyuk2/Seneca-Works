/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 6/4/2018
**********************************************************/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	class CRA_Account {
		char familyName_[max_name_length + 1];
		char givenName_[max_name_length + 1];
		int sin_;
		int year_[max_yrs];
		double balance_[max_yrs];
		int num_year;

	public:
		void set(const char*, const char*, int);
		void set(int, double);
		bool isEmpty() const;
		void display() const;
	};

}

#endif 

