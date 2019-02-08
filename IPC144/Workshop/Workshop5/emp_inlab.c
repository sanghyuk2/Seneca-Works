/*
Name: Lee Sang Hyuk
Student number: 129405171
Email: givemesomefoodplz@gmail.com
Workshop: 5(Structures)
Section: SMM
Date: 2018/2/22
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 2      

// Declare Struct Employee
struct Employee
{
	int idnum, age;
	double salary;
};

/* main program */
int main(void) {

	int i = 0;
	int k = 0;
	int option = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements
	// and initialize all elements to zero

	struct Employee emp[SIZE] = {{0, 0, 0}, {0, 0, 0}}; //by initializing emp arrays as a 0, the code might accept our new typed text.

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:    // Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) //it will be executed as long as the condition get satisfaction.
			{
				while (emp[i].idnum > 0) //this is the condition to not show the information about employee if the value is 0.
				{
					printf("%6d%9d%11.2lf\n", emp[i].idnum, emp[i].age, emp[i].salary);
					break; //break comment helps to finish the code inside switch.
				}
			}
			printf("\n");
			// Use "%6d%9d%11.2lf" formatting in a 
			// printf statement to display
			// employee id, age and salary of
			// all  employees using a loop construct

			// The loop construct will be run for SIZE times
			// and will only display Employee data
			// where the EmployeeID is > 0

			break;
		case 2:    // Adding Employee
				   // @IN-LAB

				   //by adding new variable instead of 'i' it will not calculate the value that 'i' already calculated.
			printf("Adding Employee\n");
			printf("===============\n");
			if (k >= SIZE) //if the programmer typed much more than the size of the array it will be shown to you.
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
				printf("\n");
			}

			while (k < SIZE) //under the condition that you typed less than the size of the array, it will be shown.
			{
				printf("Enter Employee ID: ");
				scanf("%d", &emp[k].idnum);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[k].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[k].salary);
				k++;
				printf("\n");

				break; //break comment helps to finish the code inside switch.
			}


			// Check for limits on the array and add employee
			// data accordingly.



			break; //break comment helps to finish the code inside switch.

		default: //if nothing matches with cases the sequence below will show up.
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0); //if the option is not 0, the code will be executed.


	return 0;
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
   111       34   78980.88
   112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
