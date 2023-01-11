/*
This app asks user to enter their grade for various courses one by one.
At the end the app computes the user average and prints the result.
user will enter -1 to indicate that the grades are finish*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float computeAverage(vector<int>items)

{
	float sum = 0.f;
	for (int i = 0; i < items.size(); ++i)
	{
		sum += items.at(i);

	}
	float average = sum / items.size();

	return average;
}

float computeStanardDeviation(vector<int>items)
{
	//1- compute the average by calling computeAverage()
	float average = computeAverage(items);
	
	//2- use a for loop to accumulate (item.at(i) - average)^2 into total
	float top = 0.f;
	float stanardDeviation = 0.f;

	//for(auto item : items)
	for (int i = 0; i < items.size(); ++i)
	{
		
		top += pow ((items.at(i) - average), 2);

	}

	//3- divide total by items.size()
	//4- take sqrt and return the result
	stanardDeviation = sqrtf(top / items.size());

	return stanardDeviation;

}

int main()
{
	cout << "This application computes the average grade that user enters.\n";

	int sum = 0;
	int grade = 0;

	//something like array
	vector<int> gradesVec;

	while (grade != -1)
	{
		cout << "Enter a grade(enter -1 to exit): \n";
		cin >> grade;

		if (grade != -1)
		{
			gradesVec.push_back(grade);
		}
	}

	
	int average = sum / gradesVec.size();
	cout << "Your average grade is " << computeAverage(gradesVec) << "\n";
	cout << "Standard deciation of the grades is " << computeStanardDeviation(gradesVec) << "\n";

	return 0;
}
