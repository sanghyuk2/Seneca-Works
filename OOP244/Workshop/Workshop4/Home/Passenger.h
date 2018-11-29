/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 6/12/2018
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
		int Y_Departure;
		int M_Departure;
		int D_Departure;

	public:
		Passenger();
		Passenger(const char* ,const char*);
		Passenger(const char*, const char*, int, int, int);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};


}

#endif // PASSENGER_H

