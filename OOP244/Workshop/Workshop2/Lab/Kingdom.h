/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 5/25/2018
**********************************************************/
/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards
#ifndef SICT_KINDOM_H
#define SICT_KINDOM_H



// TODO: sict namespace
namespace sict {
	struct Kingdom {
		char m_name[32];
		int m_population;
	};



	// TODO: define the structure Kingdom in the sict namespace

	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const Kingdom& kindomref);
}
#endif
