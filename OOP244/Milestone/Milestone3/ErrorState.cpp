/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/27/2018
**********************************************************/
#include <iostream>
#include <cstring>
#include "ErrorState.h"

using namespace std;

namespace AMA {
	ErrorState::~ErrorState() {
		delete[] m_message;
		m_message = nullptr;
	}

	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage != nullptr) {
			delete[] m_message;
			m_message = nullptr;
			m_message = new char[strlen(errorMessage) + 1];
			strncpy(m_message, errorMessage, strlen(errorMessage) + 1);
			m_message[strlen(errorMessage) + 1] = '\0';
		}
		else {
			clear();
		}

	}

	//the functions deleted in header file do not affect in our cpp file therefore there is no need to define. 

	void ErrorState::clear() {
		m_message = nullptr;
	}

	bool ErrorState::isClear() const {
		return m_message == nullptr;
	}

	void ErrorState::message(const char* str) {
		delete[] m_message;
		m_message = nullptr;
		m_message = new char[strlen(str) + 1];
		strncpy(m_message, str, strlen(str) + 1);
		m_message[strlen(str) + 1] = '\0';

	}
	const char* ErrorState::message() const {
		return m_message;
	}

	std::ostream& operator<<(std::ostream& ostr, ErrorState& obj) {
		const char* temp = obj.message();
		if (!obj.isClear()) {
			ostr << temp;
		}
		return ostr;
	}


}