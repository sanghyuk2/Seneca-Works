/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/27/2018
**********************************************************/
#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include<iostream>
#include<fstream>
#include "ErrorState.h"

namespace AMA {
#define max_sku_length 7
#define max_name_length 10
#define max_unit_length 75
#define TAX_RATE 0.13

	class Product : public ErrorState {
		char m_type;
		char m_sku[max_sku_length];
		char m_unit[max_unit_length];
		char* m_name;
		int m_current;
		int m_need;
		double m_beforeTax;
		bool m_taxable;
		ErrorState m_errorstate;

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;

	public:
		Product(char type = 'N');
		Product(const char*, const char*, const char*, int current = 0, bool taxable = 0, double beforeTax = 0, int need = 0);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		int operator+=(int);
	};
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
}
#endif
