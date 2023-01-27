#include <iostream>//for reading/writing from/to std output/input
#include "person.h"
#include <string>
#include <fstream>//for reading and writing from/to a file
#include<sstream>//for reading from a string
#include <vector>//for containing person object
#include <array>
using namespace std;

//function declaration for computing average of th person in the vector
int computeAverageAge(vector<Person>const& vec);

//function to print vec
void printVec(vector<Person>const& vec);

//function declaration for splitting Person Verctor in 2:
void splitPersonVecBasedOnAge(vector<Person>const& perVec, vector<Person>& youngerThanAvg, vector<Person>& olderThanAvg);

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << "Usage: stringProcessing filename\n";
		return 1;
	}
	else
		cout << "Processing input file " << argv[1] << endl;
/*
	//what is a char *?
	char myChar = 'a';
	char* pMyChar = &myChar;
	cout << "myChar =  " << myChar;
	cout << "\npMyChar = " << pMyChar;
	cout << "\ncontent of what pMyChar is pointing to is = " << *pMyChar << endl;
	array<int, 5> myArr = { 21, 22, 23, 24, 25 };
	//same here
	//int myArr[5] = { 21, 22, 23, 24, 25 };
	cout << "adding all ints in myArr: " << (myArr[0] + myArr[1] + myArr[2] + myArr[3] + myArr[4]) << endl;


	//lets print the argv:
	for (int i = 0; i < argc; ++i)
		cout << "arg[" << i << "]= " << argv[i] << endl;
	return 0;
*/

	//opening input file for processing:

	//input file
	ifstream fs(argv[1]);
	vector<Person>personVec{};
	string aline{};

	while (getline(fs, aline))
	{
		cout << "Line read: " << aline << endl;
		string first, last;
		int age = 0;
		//create a string stream:
		stringstream ss(aline);
		ss >> first >> last >> age;
		cout << "first=" << first << " , last =" << last << " , age=" << age << endl;
		personVec.push_back(Person(first, last, age));

	}
	fs.close();
	cout << "Person counts is " << personVec.size() << endl;

	//student work in class:
	auto averageAge = computeAverageAge(personVec);
	cout << "Average age of Persons in personVec is " << averageAge << endl;

	vector<Person> youngerThanAvg{};//currently empty. To be filled by the function below
	vector<Person> olderThanAvg{};//currently empty. To be filled by the function below
	splitPersonVecBasedOnAge(personVec, youngerThanAvg, olderThanAvg);

	//print the 2 vectors by created function:
	cout << "Younger than average person are: \n";
	printVec(youngerThanAvg);
	cout << "\nOlder than average person are: \n";
	printVec(olderThanAvg);

	return 0;
}
void printVec(vector<Person>const& vec)
{
	for (auto& item : vec)
		cout << item.toString() << endl;
}

//provide implementation computeAverageAge()below:
int computeAverageAge(vector<Person>const& vec)
{
	int sumOfAge = 0;
	for (auto& item : vec)
	{
		sumOfAge += item.getAge();
	}
	return sumOfAge / vec.size();
}

void splitPersonVecBasedOnAge(vector<Person>const& perVec, vector<Person>& youngerThanAvg, vector<Person>& olderThanAvg)
{
	auto averageAge = computeAverageAge(perVec);
	for (auto const& item : perVec)
	{
		if (item.getAge() < averageAge)
			youngerThanAvg.push_back(item);
		else if (item.getAge() > averageAge)
			olderThanAvg.push_back(item);
	}

}
