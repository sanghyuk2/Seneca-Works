/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/20/2018
**********************************************************/
#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
#define interestR 0.05

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* account, double balance) {
		iAccount *NewAcc;
		if (account[0] == 'S') {
			NewAcc = new SavingsAccount(interestR, balance);
			return NewAcc;
		}
		else {
			return nullptr;
		}

	}







}
