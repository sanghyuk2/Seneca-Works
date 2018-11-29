/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 6/4/2018
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
	// set stores a family name, given name and SIN, validating first,
	// in the current object
	//
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		// assume sin is invalid, then check if valid
		familyName_[0] = '\0';
		givenName_[0] = '\0';
		sin_ = 0;
		int SIN = sin;
		/* because we cannot assign the value in class directly, by using new variable, we can get a value for member in class indirectly. */
		if (SIN >= min_sin && SIN <= max_sin && familyName[0] != '\0' && givenName[0] != '\0') {
			int sum = 0;
			for (int i = 0; i < 5; i++)
			{
				int check = SIN % 100;
				/* If I put a sin as 123456789, it will get the last 2 digits. */
				int even = (check / 10) + (check / 10);
				/* As in instruction, we need to add a digit into itself */
				sum += check % 10 + even / 10 + even % 10;
				/* From the last 2 digits that I got from above, we need to add a alternates and digits of each sum */
				SIN /= 100; // to get the next last 2 digits.
			}
			if (sum % 10 == 0) {
				sin_ = sin;
				strncpy(familyName_, familyName, max_name_length + 1);
				familyName_[max_name_length] = '\0';
				strncpy(givenName_, givenName, max_name_length + 1);
				givenName_[max_name_length] = '\0';
			}
		}

		num_year = 0;
	}

	// set adds a year and balanace to the return records for the
	// current object
	//
	void CRA_Account::set(int a, double b)
	{
		if (!isEmpty() && num_year < max_yrs) {
			year_[num_year] = a;
			balance_[num_year] = b;
			num_year++;
		}
	}

	// display inserts the current object's data into the output stream
	//
	void CRA_Account::display() const
	{
		if (!isEmpty()) {
			cout << "Family Name: " << familyName_ << endl;
			cout << "Given Name : " << givenName_ << endl;
			cout << "CRA Account: " << sin_ << endl;
			cout.setf(ios::fixed);
			 cout.precision(2);
			for (int i = 0; i < num_year; ++i) {
				cout << "Year (" << year_[i] << ") ";
				if (balance_[i] > 2.00) {
					cout << "balance owing: " << balance_[i] << endl;
				}
				else if (balance_[i] < -2.00) {
					cout << "refund due: " << -balance_[i] << endl;
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	// isEmpty returns the empty status of the current object
	//
	bool CRA_Account::isEmpty() const
	{
		if (sin_ < min_sin || sin_ > max_sin)
			return true;
		else
			return false;
	}
}
