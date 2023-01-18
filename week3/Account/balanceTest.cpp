#include <iostream>
#include "balance.h"
using namespace std;


int main()
{
	DollarAmount d1(12345);//$123.45
	DollarAmount d2(1506);//$15.06

	cout << "D1 is " << d1.toString() << endl;
	cout << "D2 is " << d2.toString() << endl;

	//add d2 to d1 and print d1's value using toString
	d1.add(d2);
	cout << d1.toString() << endl;

	//subtract d2 from d1 and print d1's value.
	d1.subtract(d2);
	cout << d2.toString() << endl;

	//testing to add 2.34% interest
	DollarAmount d3(1000000);
	cout << "initial balance of d3 is " << d3.toString() << endl;

	//now add 2.34% interest:
	d3.addInterest(234, 100*100);
	cout << "balance after 2.34% interest: " << d3.toString() << endl;


	//Write a function named compoundInterest(DollarAmount originalValue, int interestPerYear, int divisor, int numOfYear)
	//This function accumulate interest for numOfYear and return the result as DollarAmount
	
	//d3 = compoundInerest(d3, 255, 100,10);
	cout << "Compounded interest after 10 years with 2.55% interest is " << d3.toString() << endl;

	return 0;
}
