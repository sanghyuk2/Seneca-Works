/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/23/2018
**********************************************************/
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount  : public Account     {
		double m_transaction;
		double m_monthly;


		public:
			// TODO: constructor initializes account balance and transaction fee
			ChequingAccount(double, double, double);

			// TODDO: credit adds +ve amount to the balance
			bool credit(double);

			// TODO: debit subtracts a +ve amount from the balance
			bool debit(double);

			// TODO: month end
			void monthEnd();

			// TODO: display inserts the account information into an ostream
			void display(std::ostream&) const;

	};
}
#endif
