/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/23/2018
**********************************************************/
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//
#define interestR 0.05
#define transactionF 0.50
#define monthlyF 2.00

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* account, double balance) {
		iAccount *NewAcc;
		if (account[0] == 'S') {
			NewAcc = new SavingsAccount(interestR, balance);
			return NewAcc;
		}
		else if (account[0] == 'C') {
			NewAcc = new ChequingAccount(balance, transactionF, monthlyF);
			return NewAcc;
		}
		else {
			return nullptr;
		}

	}







}
