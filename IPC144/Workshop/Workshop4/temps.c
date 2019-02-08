#include <stdio.h>

#define NUMS 3
int main(void)
{
	/*put value 0 for totalhigh,totallow,and sum for renewing the value from iteration structure and put low value in highest and high value in lowest to conduct coding without problem.*/
	int i, hv, lv, totalhigh = 0, totallow = 0, highest = 0, lowest = 0, highest_Day, lowest_Day;
	double sum = 0;
	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 1; i < NUMS + 2; i++) //if i is suitalbe for condition which is located between ; and ;, it will conduct the program below.
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

		if (hv > highest) //as i decided a value for highest and lowest above, highest and lowest value will be stayed until new value will get satisfaction. 
		{
			highest = hv;
			highest_Day = i;
		}
		if (lv < lowest)
		{
			lowest = lv;
			lowest_Day = i;
		}

		totalhigh += hv; //renewing totalhigh and totallow from program above.
		totallow += lv;
		sum += (float)(hv + lv) / 8; // because sum is double and hv and lv is integer, by putting float in front of the fomula, we can calculate exactly what we want as a value of float.
	}

	printf("\nThe average (mean) temperature was: %.2f\n", sum); //calculate variables based on the value that i decided.
	printf("The highest temperature was %d, on day %d\n", highest, highest_Day);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowest_Day);

	return 0;

}
