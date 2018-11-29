/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 8/09/2018
**********************************************************/
#ifndef AMA_PERISHABLE_H_
#define AMA_PERISHABLE_H_
#include <fstream>
#include "Product.h"
#include "Date.h"

namespace AMA {

	class Perishable : public Product {
		Date expiry_date;

	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const; // the default value of newLine is true.
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}
#endif