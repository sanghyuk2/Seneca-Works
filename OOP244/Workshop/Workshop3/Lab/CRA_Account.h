/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 6/1/2018
**********************************************************/
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {
		char familyName_[max_name_length + 1];
		char givenName_[max_name_length + 1];
		int sin_;
	

	public:
		void set(const char*, const char*, int);
		bool isEmpty() const;
		void display() const;
	};

}

#endif 
