/*
This app asks user to enter their grade for various courses one by one.
At the end the app computes the user average and prints the result.
user will enter -1 to indicate that the grades are finish*/
#include <iostream>
#include <string>
using namespace std;


int main()
{
	cout << "This application computes the average grade that user enters.\n";

	int sum = 0;
	int grade = 0;
	int numOfItem = 0;

	while (grade != -1)
	{
		cout << "Enter a grade(enter -1 to exit): \n";
		cin >> grade;

		if(grade != -1)
		{
			sum += grade;
			++numOfItem;
		}
	} 
	
	cout << "Your average grade is: " << sum / numOfItem << "\n";

	return 0;
}