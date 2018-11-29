/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/12/2018
**********************************************************/
// Final Project Milestone 1
//
// Version 1.0
// Date 
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name      Date          Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace AMA {

	#define NO_ERROR 0
	#define CIN_FAILED 1
	#define YEAR_ERROR 2
	#define MON_ERROR 3
	#define DAY_ERROR 4

	const int min_year = 2000;
	const int max_year = 2030;

  class Date {

	  int m_Year;
	  int m_Month;
	  int m_Day;
	  int Comparator;
	  int Error;
	   
     int mdays(int, int)const;
	 void errCode(int errorCode);

  public:
	  Date();
	  Date(int, int, int);
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	  
      bool isEmpty() const;    
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
 
  };

	std::istream& operator>>(std::istream&, Date&);
	std::ostream& operator<<(std::ostream&, const Date&);
}
#endif