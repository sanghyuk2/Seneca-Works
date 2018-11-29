/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 5/28/2018
**********************************************************/
/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"

using namespace std;

// TODO: the sict namespace
namespace sict {
	// TODO:definition for display(...) 
	void display(const Kingdom& kingdomref) {
		cout << kingdomref.m_name << ", population " << kingdomref.m_population << endl;
	}
	int total = 0;
	void display(const Kingdom *kingdomarr, int count) {
		cout << "------------------------------\n"
			<< "Kingdoms of SICT\n"
			<< "------------------------------" << endl;
		for (int i = 0; i < count; i++) {
			cout << i + 1 << ". ";
			display(kingdomarr[i]);
			total += kingdomarr[i].m_population;
		}

		cout << "------------------------------\n"
			<< "Total population of SICT: " << total << endl;

	}

}