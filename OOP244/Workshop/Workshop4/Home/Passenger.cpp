/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 6/12/2018
**********************************************************/
// TODO: add file header comments here
#define _CRT_SECURE_NO_WARNINGS
// TODO: add your headers here
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Passenger.h"

// TODO: continue your namespace here
using namespace std;

namespace sict {
    // TODO: implement the default constructor here
	Passenger::Passenger() {
		Passenger_name[0] = '\0';
		Destination[0] = '\0';
		Y_Departure = 0;
		M_Departure = 0;
		D_Departure = 0;
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination) {
		if (name != nullptr && destination != nullptr) {
			strncpy(Passenger_name, name, 32);
			Passenger_name[31] = '\0';
			strncpy(Destination, destination, 32);
			Destination[31] = '\0';
			Y_Departure = 2017;
			M_Departure = 7;
			D_Departure = 1;
		}
		else {
			Passenger();	
		}
	}
	
	Passenger::Passenger(const char* name, const char* destination, int YD, int MD, int DD) {
		if (name != nullptr && destination != nullptr && YD >= 2017 && YD <= 2020 && MD >= 1 && MD <= 12 && DD >= 1 && DD <= 31) {
			strncpy(Passenger_name, name, 32);
			Passenger_name[31] = '\0';
			strncpy(Destination, destination, 32);
			Destination[31] = '\0';
			Y_Departure = YD;
			M_Departure = MD;
			D_Departure = DD;
		}
			
		else {
			Passenger();		
		}
	}

			// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (Passenger_name[0] == '\0' || Destination[0] == '\0' || (Y_Departure < 2017 || Y_Departure > 2020) || (M_Departure < 1 || M_Departure > 12) || (D_Departure < 1 || D_Departure > 31))
			return true;
		else
			return false;
	}
			// TODO: implement display query here
	void Passenger::display() const {
		
		if (!isEmpty()) {
			cout << Passenger_name << " - " << Destination << " on " 
				<< Y_Departure <<  "/" << setw(2) << setfill('0') << M_Departure << "/" << setw(2) << setfill('0') << D_Departure << endl;
		}else
			cout << "No passenger!" << endl;
	}

	const char* Passenger::name() const {
		if (!isEmpty())
			return Passenger_name;
		else
			return "";
	}

	bool Passenger::canTravelWith(const Passenger& partner) const {
		return strcmp(partner.Destination, Destination) == 0 && partner.Y_Departure == Y_Departure && partner.M_Departure == M_Departure && partner.D_Departure == D_Departure;
	}

}

