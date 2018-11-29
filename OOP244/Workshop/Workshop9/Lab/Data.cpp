/**********************************************************
* Name: SangHyuk Lee
* Student ID: 129405171
* Seneca email: slee395@myseneca.ca
* Date of Completion: 7/27/2018
**********************************************************/
#include <iostream>
#include <cstdlib>
#include "Data.h"

using namespace std;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is " << abs(population[0] - population[n - 1])/1000000.00 << " million" << endl;




		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		if (violentCrimeRate[n - 1] > violentCrimeRate[0])
			cout << "Violent Crime trend is up" << endl;
		else
			cout << "Violent Crime trend is down" << endl;





		// Q3 print the GTA number accurate to 0 decimal places
		cout << "There are " << average(grandTheftAuto, n) / 1000000.00 << " million Grand Theft Auto incidents on average a year" << endl;



		// Q4. Print the min and max violentCrime rates
		int Min = min(violentCrimeRate, n);
		int Max = max(violentCrimeRate, n);
		cout.precision(0);
		cout << "The Minimum Violent Crime rate was " << Min << endl;
		cout << "The Maximum Violent Crime rate was " << Max << endl;
		cout.unsetf(ios::fixed);


	}
}