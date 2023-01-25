#include <iostream>//for reading/writing from/to std output/input
#include "person.h"
#include <string>
#include <fstream>//for reading and writing from/to a file
#include<sstream>//for reading from a string
#include <vector>//for containing person object
using namespace std;

//function declaration for computing average of th person in the vector
int computeAverageAge(vector<Person>& vec);

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cout << "Usage: stringProcessing filename\n";
		return 1;
	}
	else
		cout << "Processing input file " << argv[1] << endl;

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
	return 0;
}

//provide implementation computeAverageAge()below:
int computeAverageAge(vector<Person>& vec)
{
	int sumOfAge = 0;
	for (auto &i : vec)
	{
		sumOfAge += i.getAge();
	}
	return sumOfAge / vec.size();
}
