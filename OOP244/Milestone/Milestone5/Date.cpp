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
// Name   Date               Reason
/////////////////////////////////////////////////////////////////

#include <iostream>
#include "Date.h"

using namespace std;

namespace AMA {

	Date::Date() {
		m_Year = 0;
		m_Day = 0;
		m_Month = 0;
		Comparator = 0;
		Error = NO_ERROR;
	}

	Date::Date(int Year, int Month, int Day) {
		int Days = mdays(Month, Year);
		if ((Year >= min_year && Year <= max_year) && (Month >= 1 && Month <= 12) && (Day >= 1 && Day <= Days)) {
			m_Year = Year;
			m_Month = Month;
			m_Day = Day;
			Comparator = Year * 372 + Month * 13 + Day; 
			Error = NO_ERROR;

		}
		else if ((Year < min_year || Year > max_year) && (Month >= 1 && Month <= 12) && (Day >= 1 && Day <= Days)) {
		        *this = Date();
	    	     Error = YEAR_ERROR;
		    }
	    	 else if ((Month < 1 || Month > 12) && (Year >= min_year && Year <= max_year) && (Day >= 1 && Day <= Days)) {
	    	         *this = Date();
		              Error = MON_ERROR;
	    	    }
		         else if ((Day < 1 || Day > Days) && (Year >= min_year && Year <= max_year) && (Month >= 1 && Month <= 12)) {
		                *this = Date();
		                 Error = DAY_ERROR;
		            }
		             else if ((Year < min_year || Year > max_year) && (Month < 1 || Month > 12) && (Day < 1 || Day > Days)) {
		                    *this = Date();
		                     Comparator = 0;
    		             }
	
	}

  // number of days in month mon_ and year year_
  //
    int Date::mdays(int mon, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    void Date::errCode(int errorCode) {
      Error = errorCode;
    }
    
    bool Date::operator==(const Date& rhs) const {
        if(!isEmpty() && !rhs.isEmpty())
            return this->Comparator == rhs.Comparator;
        else
            return false;
    }
    
    bool Date::operator!=(const Date& rhs) const {
        if(!isEmpty() && !rhs.isEmpty())
            return this->Comparator != rhs.Comparator;
        else
            return false;
    }
    
    bool Date::operator<(const Date& rhs) const {
        if(!isEmpty() && !rhs.isEmpty())
            return this->Comparator < rhs.Comparator;
        else
            return false;
    }
    
    bool Date::operator>(const Date& rhs) const {
        if(!isEmpty() && !rhs.isEmpty())
            return this->Comparator > rhs.Comparator;
        else
            return false;
    }
    
    bool Date::operator<=(const Date& rhs) const {
        if(!isEmpty() && !rhs.isEmpty())
            return this->Comparator <= rhs.Comparator;
        else
            return false;
    }
    
    bool Date::operator>=(const Date& rhs) const {
        if(!isEmpty() && !rhs.isEmpty())
            return this->Comparator >= rhs.Comparator;
        else
            return false;
    }
    
    bool Date::isEmpty() const {
        return m_Year == 0 || m_Month == 0 || m_Day == 0;
    }
    
    int Date::errCode() const {
        return Error;
    }
    
    bool Date::bad() const {
        if(Error != NO_ERROR)
            return true;
        else 
            return false;
    }
    
    std::istream& Date::read(std::istream& istr) {
        char del;

        istr >> m_Year >> del >> m_Month >> del >> m_Day;
        int Days = mdays(m_Month, m_Year);
        if(istr.fail()){
            Error = CIN_FAILED;
        
        }
		else if (m_Year < min_year || m_Year > max_year) {
		        *this = Date();
	    	     Error = YEAR_ERROR;
		    }
	    	 else if (m_Month < 1 || m_Month > 12)  {
	    	         *this = Date();
		              Error = MON_ERROR;
	    	    }
		         else if (m_Day < 1 || m_Day > Days) {
		                *this = Date();
		                 Error = DAY_ERROR;
		            } else {
		                Error = NO_ERROR;
		            }

            return istr;
        
    }
    
    std::ostream& Date::write(std::ostream& ostr) const {
	
        char del = '/';
        ostr << m_Year << del;
        ostr.fill('0');
        ostr.width(2);
        ostr << m_Month << del;
	ostr.fill(' '); // to prevent from filling with 0 in other padding places, make the padding as a whitespace.
        ostr.width(2);
        ostr << m_Day;
    
            
        return ostr;
            
    }
    
    std::istream& operator>>(std::istream& istr, Date& Date_) {
        return Date_.read(istr);
    }
    
    std::ostream& operator<<(std::ostream& istr, const Date& Date_) {
        return Date_.write(istr);
    }



}
