//--------------------------------------------------
// Name: Lee Sang Hyuk         
// Student Number: 129405171
// Email: givemesomefoodplz@gmail.com
// Section: SMM 
// Workshop: 4(Array)
//--------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Place your code below

#include <stdio.h>

int main(void)
{
	int i, NOD, ENOD, k;
	int Day[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; //we can prevent from accidental problem because the range of day starts from 3 to 10.
	int hv[10] = { 0 }, lv[10] = { 0 }; //As we decide all elements as a 0, we can add our value in array.
	int highest = 0, lowest = 0; //the reason why I initialized the value of higheset, lowest, avesum is to calculate average more comfortably.
	float aveday, avesum = 0, totalave;
	

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: "); //typed  value will be stored in the variable named NOD
	scanf("%d", &NOD);

	while (NOD < 3 || NOD > 10) // if the sequence is satisfied with one of these 'while loop' conditions, the code below will be executed.
	{
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &NOD);
	}

	printf("\n");

	for (i = 0; i < NOD; i++)  // As the int variable 'i' is increased, the Day array will be printed and the high, low value which i will type will be stored in hv,lv arrays respectively.
	{

		printf("Day %d - High: ", Day[i]);
		scanf("%d", &hv[i]);
		printf("Day %d - Low: ", Day[i]);
		scanf("%d", &lv[i]);


	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i < NOD; i++)
	{
		printf("%d    %d    %d\n", Day[i], hv[i], lv[i]); //As the code will execute, the value stored in arrays will be printed out in a sequence.

		if (hv[highest] < hv[i]) //If the one of the hv,lv arrays are satisfied the condition in if, highest and lowest will be decided.
		{
			highest = i;
		}
		if (lv[lowest] > lv[i])
		{
			lowest = i;
		}

	}

	printf("\nThe highest temperature was %d, on day %d\n", hv[highest], Day[highest]); //it will print out the value which has satisfied the conditions above.
	printf("The lowest temperature was %d, on day %d\n", lv[lowest], Day[lowest]);

	while (1) //if the condition in iteration is any constant, it will be true.
	{

		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", NOD);
		scanf("%d", &ENOD);

		if (ENOD < 0)
		{
			printf("\n");
			printf("Goodbye!\n");
			break;
		}

		if (ENOD > NOD)
		{
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", NOD);
			scanf("%d", &ENOD);
		}

		for (k = 0; k < ENOD; k++) { //As we decide the limit as a ENOD, not NOD, it will calculate specific day what we want.
			aveday = (float)(hv[k] + lv[k]) / 2;
			avesum += aveday;
			totalave = avesum / ENOD;

		}
		printf("\nThe average temperature up to day %d is: %.2f\n", ENOD, totalave);

		aveday = 0; //by putting this code, the compiler can calculate from the 0, not the value which is already calculated above so that we can get exactly what we want.
		avesum = 0;
		totalave = 0;



	}
	return 0;
}


