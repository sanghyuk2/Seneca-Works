#include <iostream>
/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/07/2018
**********************************************************/
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {
	Contact::Contact() {
		m_name[0] = '\0';
		m_phone = nullptr;
		m_Nphone = 0;
	}

	Contact::~Contact() {
		delete[] m_phone;
		m_phone = nullptr;
	}

	Contact::Contact(const char *Name, const long long* Phone, int Nphone) {
		if (Name != nullptr) {
				strncpy(m_name, Name, 20);
				m_name[19] = '\0';
				m_Nphone = Nphone;

				//TODO allocate dynamic memory
				if (m_Nphone > 0) {
					long long *Phone_Num;
					Phone_Num = new long long[Nphone];
					for (int i = 0; i < m_Nphone; i++) {
						Phone_Num[i] = Phone[i];
					}
					m_phone = Phone_Num;
				}
				else {
					m_phone = nullptr;
				}
		}else 
			*this = Contact();
	}

	bool Contact::isEmpty() const {

		if (m_name[0] == '\0'&&m_phone == nullptr)
			return true;
		else return false;
	}


	void Contact::display() const {
		if (!isEmpty()) {
			cout << m_name << endl;
			for (int i = 0; i < m_Nphone; i++) {
				long long a = m_phone[i];
				long long PhoneNumbers;
				int last;
				int b = 10000000;
				int c = int(a / b);
				int Country_Code, Area_Code;
				if (c > 1001 && c < 99999) {
					Area_Code = c % 1000;
					Country_Code = c / 1000;
					PhoneNumbers = a % 1000000;
					int temp = a / 10000;
					int first = temp % 1000;
					last = PhoneNumbers % 10000;
					cout << "(+" << Country_Code << ")" << " " << Area_Code << " " << first
						<< "-" << last << endl;
				}
			}
		}
		else 
			cout << "Empty contact!" << endl;
		
	}
}
