/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 6/8/2018
**********************************************************/
// TODO: add file header comments here

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H



// TODO: declare your namespace here
namespace sict {
    // TODO: define the Passenger class here
	class Passenger {
		char Passenger_name[32];
		char Destination[32];

	public:
		Passenger();
		Passenger(const char* ,const char*);
		bool isEmpty() const;
		void display() const;

	};


}

#endif // PASSENGER_H

