/*
     Name:      <Lee Sang Hyuk> 
     Student#:  <129405171>
     Section:   <IPC144 CPA>
*/

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include <stdio.h> //print identifier

int main() //start program from here
{
	int a, b, c, d, e, GST, amountowing1, amountowing2, amountowing3, amountowing4, amountowing5; //set a, b, c, d, e as a int 
	double money, amountowing; //set money, c as a double


	printf("Please enter the amount to be paid: $");
	scanf("%lf", &money);

	GST = (money*.13 + .005)*100; //process of making fomula to caculate
	amountowing = (money*100) + GST;

	a = (amountowing / 100);
	amountowing1 = (int) amountowing % 100;
	b = (amountowing1 / 25);
	amountowing2 = amountowing1 % 25;
	c = (amountowing2 / 10);
	amountowing3 = amountowing2 % 10;
	d = (amountowing3 / 5);
	amountowing4 = amountowing3 % 5;
	e = (amountowing4 / 1);
	amountowing5 = amountowing4 % 1;

	printf("GST: %1.2lf\n", (float) GST / 100);
	printf("Balance owing: $%1.2lf\n", amountowing / 100);
	printf("Loonies required: %d, balance owing $%1.2lf\n", a, (float) amountowing1/100);
	printf("Quarters required: %d, balance owing $%1.2lf\n", b, (float) amountowing2/100);
	printf("Dimes required: %d, balance owing $%1.2lf\n", c, (float) amountowing3/100);
	printf("Nickels required: %d, balance owing $%1.2lf\n", d, (float) amountowing4/100);
	printf("Pennies required: %d, balance owing $%1.2lf\n", e, (float) amountowing5/100);


	return 0;

}