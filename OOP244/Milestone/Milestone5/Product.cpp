/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/27/2018
**********************************************************/
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"

using namespace std;

namespace AMA {
	void Product::name(const char* Name) {
		if (Name != nullptr) {
			delete[] m_name;
			m_name = nullptr;

			m_name = new char[max_name_length + 1];
			strncpy(m_name, Name, max_name_length + 1);
			m_name[max_name_length] = '\0';
		}
		else
			m_name = nullptr;
	}

	const char* Product::name() const {
		if (m_name == nullptr)
			return nullptr;
		else
			return m_name;
	}

	const char* Product::sku() const {
		return m_sku;
	}

	const char* Product::unit() const {
		return m_unit;
	}

	bool Product::taxed() const {
		return m_taxable;
	}

	double Product::price() const {
		return m_beforeTax;
	}

	double Product::cost() const {
	    if(m_taxable == true)
	        return m_beforeTax + m_beforeTax*TAX_RATE;
	   else if(m_taxable == false)
	        return m_beforeTax;
	   return m_beforeTax;
	}

	void Product::message(const char* errorMessage) {
		m_errorstate.message(errorMessage);
	}

	bool Product::isClear() const {
		return m_errorstate.message() == '\0';
	}

	Product::Product(char type) {
		m_type = type;
		m_sku[0] = '\0';
		m_unit[0] = '\0';
		m_name = nullptr;
		m_current = 0;
		m_need = 0;
		m_beforeTax = 0;
		m_taxable = false; /*An rvalue of arithmetic, enumeration, pointer, or pointer to member type can be converted to an rvalue of type bool. 
						   A zero value, null pointer value, or null member pointer value is converted to false https://stackoverflow.com/questions/651361/is-it-acceptable-to-assign-null-to-a-boolean-datatype */
	} 

	Product::Product(const char* Sku, const char* Name, const char* Unit, int current, bool taxable, double beforeTax, int need) {
		bool valid = Sku != nullptr && Name != nullptr && Unit != nullptr; 
 
 
 		if (valid) 
 		{ 
 			m_name = new char[strlen(Name) + 1]; 
 
 
 			strncpy(m_name, Name, strlen(Name) + 1); 
 			strncpy(m_sku, Sku, strlen(Sku) + 1); 
 			strncpy(m_unit, Unit, strlen(Unit) + 1); 
 			m_current = current; 
 			m_taxable = taxable; 
 			m_beforeTax = beforeTax; 
 			m_need = need; 
 		} 
 		else 
 		{ 
 			*this = Product(); 
 		} 

	}

	Product::Product(const Product& src) {
		strncpy(m_sku, src.m_sku, max_sku_length + 1);
		m_sku[max_sku_length] = '\0';
		strncpy(m_unit, src.m_unit, max_unit_length + 1);
		m_unit[max_unit_length] = '\0';

		m_current = src.m_current;
		m_need = src.m_need;
		m_beforeTax = src.m_beforeTax;
		m_taxable = src.m_taxable;

		if (src.m_name != nullptr) {
			delete[] m_name;
			m_name = nullptr;
			m_name = new char[max_name_length + 1];
			strncpy(m_name, src.m_name, max_name_length + 1);
			m_name[max_name_length] = '\0';	
					}
		else 
			m_name = nullptr;
	}

	Product& Product::operator=(const Product& src) {
		if (this != &src) {
			strncpy(m_sku, src.m_sku, max_sku_length + 1);
			m_sku[max_sku_length] = '\0';
			strncpy(m_unit, src.m_unit, max_unit_length + 1);
			m_unit[max_unit_length] = '\0';

			m_current = src.m_current;
			m_need = src.m_need;
			m_beforeTax = src.m_beforeTax;
			m_taxable = src.m_taxable;

			if (src.m_name != nullptr) {
				delete[] m_name;
				m_name = nullptr;
				m_name = new char[max_name_length + 1];
				strncpy(m_name, src.m_name, max_name_length + 1);
				m_name[max_name_length] = '\0';
			}
			else 
				m_name = nullptr;
		}
		return *this;	
	}

	
	Product::~Product() {
		delete[] m_name;
		m_name = nullptr;
	}

	std::fstream& Product::store(std::fstream& file, bool newLine ) const {
        if (!isEmpty()) 
 		{ 
 			file << m_type << "," << m_sku << "," << m_name << "," << m_unit << "," << m_taxable << "," 
 				<< m_beforeTax << "," << m_current << "," << m_need; 
 
 
 			if (newLine) 
 			{ 
 				file << endl; 
 			} 
 		} 
        return file; 

	}
	
	std::fstream& Product::load(std::fstream& file) { 
 		char t_sku[max_sku_length + 1]; 
 		char t_name[max_name_length + 1]; 
 		char t_unit[max_unit_length + 1]; 
 		int t_hand; 
 		bool t_taxed; 
 		double t_price; 
 		int t_need; 
 
 
 		if (file.is_open()) 
 		{ 
 			
			file.getline(t_sku, max_sku_length, ',');  
 			file.getline(t_name, max_name_length, ','); 
 			file.getline(t_unit, max_unit_length, ','); 
 
 
 			file >> t_taxed; 
 			 
 			file.ignore(); 
 			file >> t_price; 
 			file.ignore(); 
 			file >> t_hand; 
 			file.ignore(); 
			file >> t_need; 
 			file.ignore();
 
 			*this = Product(t_sku, t_name, t_unit, t_hand, t_taxed, t_price, t_need); 
 
 
 		} 
 
 
 		return file; 
 
 
 	} 
 	
 	std::ostream& Product::write(std::ostream& os, bool linear) const { 
 
 
 		if (m_errorstate.isClear()) 
 		{ 
 			if (linear) 
 			{ 
 				os.width(max_sku_length); 
 				os.setf(ios::left); 
 				os << sku() << "|"; 
 				os.width(20); 
 				os << name() << "|"; 
 				os.width(7); 
 				os.unsetf(ios::left); 
 				os.setf(ios::fixed); 
 				os.precision(2); 
 				os << cost() << "|"; 
 				os.width(4); 
 				os << quantity() << "|"; 
 				os.width(10); 
				os.setf(ios::left); 
 				os << unit() << "|"; 
 				os.unsetf(ios::left); 
 				os.width(4); 
 				os << qtyNeeded() << "|"; 
 			} 
 			else 
 			{ 
 				if (taxed()) 
 				{ 
 					os << " Sku: " << sku() << endl; 
 					os << " Name (no spaces): " << name() << endl; 
 					os << " Price: " << price() << endl; 
					os << " Price after tax: " << cost() << endl; 
 					os << " Quantity on Hand: " << quantity() << " " << unit() << endl; 
 					os << " Quantity needed: " << qtyNeeded(); 
 					 
 					
 				} 
 				else 
 				{ 
 					os << " Sku: " << sku() << endl; 
 					os << " Name (no spaces): " << name() << endl; 
 					os << " Price: " << price() << endl; 
 					os << " Price after tax: " << "N/A" << endl; 
 					os << " Quantity on Hand: " << quantity() << " " << unit() << endl; 
 					os << " Quantity needed: " << qtyNeeded() << endl; 
 
 
 				} 
 			} 
 		} 
 		else 
 		{ 
 			cout << m_errorstate.message(); 
 		} 
 		return os; 

 	} 
 	
 	std::istream& Product::read(std::istream& is) {
		char sku[max_sku_length + 1];
		char name[max_name_length + 1];
		char unit[max_unit_length + 1];
		char taxed = '\0';
		double price;
		int handQty;
		int needQty;
		bool temp_taxable;

		cout << " Sku: ";
		is >> sku;
		cout << " Name (no spaces): ";
		is >> name;
		cout << " Unit: ";
		is >> unit;
		cout << " Taxed? (y/n): ";
		is >> taxed;
		if (taxed == 'Y' || taxed == 'y' || taxed == 'N' || taxed == 'n')
		{
			if (taxed == 'Y' || taxed == 'y')
			{
				temp_taxable = true;
			}
			else if (taxed == 'N' || taxed == 'n')
			{
				temp_taxable = false;
			}

			cout << " Price: ";
			is >> price;
			
			if (is.fail())
			{
				m_errorstate.message("Invalid Price Entry");
			}
			else
			{
				cout << " Quantity on hand: ";
				is >> handQty;
				if (is.fail())
				{
					m_errorstate.message("Invalid Quantity Entry");
				}
				else
				{
					cout << " Quantity needed: ";
					is >> needQty;
					if (is.fail())
					{
						m_errorstate.message("Invalid Quantity Needed Entry");
					}
					else
					{
						m_errorstate.clear();
					}

				}
			}

		}
		else 
		{
			m_errorstate.message("Only (Y)es or (N)o are acceptable");
			is.clear();
			is.setstate(std::ios::failbit);

		}


		Product temp(sku, name, unit, handQty, temp_taxable, price, needQty);
    
		*this = temp;
		is.ignore();
		return is;
	}
	
	bool Product::operator==(const char* str) const {
	    return strncmp(m_sku, str, strlen(m_sku) + 1) == 0;
	}
	
	double Product::total_cost() const {

		double total = 0;
        
		total = quantity() * cost();
      
            
		return total;
	}
	
	void Product::quantity(int current) {

		m_current = current;

	}
	
	bool Product::isEmpty() const {
        return m_sku[0] == '\0' && m_name == nullptr && m_unit[0] == '\0';
	}
    
    int Product::qtyNeeded() const {

		return m_need;

	}

	int Product::quantity() const {

		return m_current;
	}
	
	bool Product::operator>(const char* sku) const {
	    return strcmp(m_sku, sku) > 0;
	
	}
	
	bool Product::operator>(const iProduct& obj) const {
	    return strcmp(m_name, obj.name()) > 0;
	}
    
    int Product::operator+=(int nUnit) {

		if (nUnit > 0)
		{
			m_current += nUnit;
			return m_current;
		}

		return m_current;

	}
	
	std::ostream& operator<<(std::ostream& os, const iProduct& obj) {
		obj.write(os, true);
		return os;

	}

	std::istream& operator>>(std::istream& is, iProduct& obj) {
		obj.read(is);
		return is;
	}
	 
	double operator+=(double& add, const iProduct& obj) {

		add += obj.total_cost();
		return add;

	}
}
