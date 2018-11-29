/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/23/2018
**********************************************************/
// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee) : Account::Account(balance) {
		if (transactionFee > 0) {
			m_transaction = transactionFee;
		}
		else {
			m_transaction = 0.0;
		}

		if (monthlyFee > 0) {
			m_monthly = monthlyFee;
		}
		else {
			m_monthly = 0.0;
		}
	} 



	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double credit) {
		if (Account::credit(credit) == true) {
			Account::debit(m_transaction);
			return true;
		}
		else {
			return false;
		}
	}



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double debit) {
		if (Account::debit(debit) == true) {
			Account::debit(m_transaction);
			return true;
		
		}
		else {
			return false;
		}
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		debit(m_monthly);
	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << Account::balance() << endl;
		os << "Per Transaction Fee: " << m_transaction << endl;
		os << "Monthly Fee: " << m_monthly << endl;
	}



}