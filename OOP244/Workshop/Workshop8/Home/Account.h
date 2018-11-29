/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/23/2018
**********************************************************/
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {

	class Account : public iAccount {

		double m_Balance;

	protected:
		double balance() const;


	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double account = 0.0);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);
	};

}
#endif
