// Name: Lee Sang Hyuk
// Student Number: 129405171
// Email: givemesomefoodplz@gmail.com
// Section: CPA
// Workshop: 3

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>

#define NUMS 3
int main(void)
{
	int i, hv, lv, totalhigh = 0, totallow = 0;
	double sum = 0; // put value 0 for totalhigh,totallow,and sum for renewing the value from iteration structure.
	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 1; i < NUMS + 1; i++) //if i is suitalbe for condition which is located between ; and ;, it will conduct the program below.
	{
		printf("\nEnter the high value for day %d: ", i);
		scanf("%d", &hv);
		printf("\nEnter the low value for day %d: ", i);
		scanf("%d", &lv);

		while (hv < lv || hv>40 || hv < -40 || lv>40 || lv < -40) //by using or(||), if one of the conditions are not match with it, it will conduct the program below until it will be corrected.
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\nEnter the high value for day %d: ", i);
			scanf("%d", &hv);
			printf("\nEnter the low value for day %d: ", i);
			scanf("%d", &lv);

		}
		totalhigh += hv; //renewing totalhigh and totallow from program above.
		totallow += lv;
		sum += (float)(hv + lv) / (2 * NUMS); // because sum is double and hv and lv is integer, by putting float in front of the fomula, we can calculate exactly what we want as a value of float.
	}
	
	printf("\nThe average (mean) temperature was: %.2f\n", sum);

	return 0;
	
}
