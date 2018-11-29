/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 8/09/2018
**********************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include "Perishable.h"
#include "Date.h"
#include "ErrorState.h"
#include "Product.h"
#include "iProduct.h"

using namespace std;

namespace AMA {
	Perishable::Perishable() : Product::Product('P') { //passes the file record tag for a perishable product('P') to the base class constructor and sets the current object to a safe empty state.
		expiry_date = Date();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Product::store(file, !newLine); //because by default, the bool is true, if we put ! in front of bool, it changes into false.
		file << ",";
		file << expiry_date;
		if (newLine == true) {
			file << '\n';
		}

		return file;

	}

	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file); //call its base class version passing as an argument a reference to the fstream object.
		expiry_date.read(file);
		file.get(); //get() extracts a single character.
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);
		if (isClear() || isEmpty()) { //if the current object is not in an error or safe empty state, inserts the expiry date into ostream object.
			
			if (linear == true) { //if the linear is true, adds a expiry date on the same line for an outcome.
				expiry_date.write(os);
			}
			else {	
				
				os << " Expiry date: "; // it does not insert a newline after a expiry data in the case of linear output or the case of line-by-line output.
				expiry_date.write(os);
			}
		}

		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		Date temp;
		Product::read(is); //call its base class version passing as an argument a reference to the istream object.
		if (!is.fail()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			temp.read(is);
		}

		if (temp.bad()) {
			if (temp.errCode() == CIN_FAILED) {
				message("Invalid Date Entry");
				is.setstate(std::ios::failbit);
			}
			else if (temp.errCode() == YEAR_ERROR) {
				message("Invalid Year in Date Entry");
				is.setstate(std::ios::failbit);
			}
			else if (temp.errCode() == MON_ERROR) {
				message("Invalid Month in Date Entry");
				is.setstate(std::ios::failbit);
			}
			else if (temp.errCode() == DAY_ERROR) {
				message("Invalid Day in Date Entry");
				is.setstate(std::ios::failbit);
			}
		}
		
		if (!is.fail()) //if there is not in error state, copy assigns the temporary Date object to the instance Date object.
			expiry_date = temp;

		return is;
	}
		


	const Date& Perishable::expiry() const {
		return expiry_date;
	}
}