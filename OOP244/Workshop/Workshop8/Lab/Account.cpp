/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/20/2018
**********************************************************/
#include "Account.h"

namespace sict {

	double Account::balance() const {
		return m_Balance;
	}

	Account::Account(double balance) {
		if (balance > 0) {
			m_Balance = balance;
		}
		else {
			m_Balance = 0.0;
		}

	}

	bool Account::credit(double credit) {
		if (credit > 0) {
			m_Balance += credit;
			return true;
		}
		else {
			return false;
		}
	}

	bool Account::debit(double debit) {
		if (debit > 0) {
			m_Balance -= debit;
			return true;
		}
		else {
			return false;
		}

	}

}