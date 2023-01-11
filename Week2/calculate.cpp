#include <iostream>
using namespace std;

//Create an app that calculated Power of a number.
//a^b
//ask user for a and b and then calls a function named power(a,b). This function computes and return the result.

int power(int base, int exponent)
{
	int result = 1;
	//we do calculation here
	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	//result = pow(base, exponent);

	return result;
}

int main()
{
	cout << "Enter base as an integer: ";
	int base = 0;
	cin >> base;

	cout << "\nEnter exponent as an integer: ";
	int exponent = 0;
	cin >> exponent;

	int result = power(base, exponent);

	cout << "Result of base^(exp) = " << result << "\n";
	
	return 0;
}
