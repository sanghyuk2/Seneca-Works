/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 6/8/2018
**********************************************************/
// TODO: add file header comments here
#define _CRT_SECURE_NO_WARNINGS
// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;

namespace sict {
    // TODO: implement the default constructor here
	Passenger::Passenger() {
		Passenger_name[0] = '\0';
		Destination[0] = '\0';
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name != nullptr && destination != nullptr) {
			strncpy(Passenger_name, name, 32);
			Passenger_name[31] = '\0';
			strncpy(Destination, destination, 32);
			Destination[31] = '\0';
		}
		else {
			Passenger_name[0] = '\0';
			Destination[0] = '\0';
		}
	}
	
			// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (Passenger_name[0] == '\0' || Destination[0] == '\0')
			return true;
		else
			return false;
	}
			// TODO: implement display query here
	void Passenger::display() const {
		
		if (!isEmpty()) {
			cout << Passenger_name << " - " << Destination << endl;
		}else
			cout << "No passenger!" << endl;
	}

	

}

