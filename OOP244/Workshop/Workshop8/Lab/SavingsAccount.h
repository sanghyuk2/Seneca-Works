/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/20/2018
**********************************************************/
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double m_Interest;

	public:
		// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

		// TODO: perform month end transactions
		void monthEnd();

		// TODO: display inserts the account information into an ostream			
		void display(std::ostream&) const;
	};
}
#endif
