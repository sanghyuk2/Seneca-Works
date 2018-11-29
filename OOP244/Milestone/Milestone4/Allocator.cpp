/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 8/1/2018
**********************************************************/
// Final Project Milestone 3 - iProduct Interface
// Version 3.3
// Allocator.cpp
// 2018-03-10
// Authors	Fardad Soleimanloo, Chris Szalwinski
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "MyProduct.h"

namespace AMA {

	iProduct* CreateProduct() {
		return new MyProduct("Product");
	}
	iProduct* CreatePerishable() {
		return new MyProduct("Perishable");
	}
}