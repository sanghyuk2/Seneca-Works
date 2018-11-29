/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/07/2018
**********************************************************/
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#include <iostream>
using namespace std;

namespace sict {
	class Contact {
		char m_name[20];
		long long *m_phone;
		double m_Nphone;

	public:
		Contact();
		Contact(const char*, const long long*, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}
#endif // !SICT_CONTACT_H

