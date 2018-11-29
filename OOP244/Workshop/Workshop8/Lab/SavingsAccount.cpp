/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/20/2018
**********************************************************/
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;

namespace sict {
	SavingsAccount::SavingsAccount(double interest, double balance) : Account(balance) {
		if (interest > 0) {
			m_Interest = interest;
		}
		else {
			m_Interest = 0.0;
		}
	}

	void SavingsAccount::monthEnd() {
		Account::credit(Account::balance()*m_Interest);
	}

	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << std::endl;
		os.setf(ios::fixed);
		os.precision(2);
		os << "Balance: $" << Account::balance() << std::endl;
		os << "Interest Rate (%): " << m_Interest*100 << std::endl;
	}
}

