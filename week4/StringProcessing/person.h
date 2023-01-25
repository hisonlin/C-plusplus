#pragma once
#include <string>

class Person
{
private:
	std::string first;
	std::string last;
	int age;

public:
	//constructors
	Person() = delete;//disable default constructor for our application
	Person(std::string f, std::string l, int a);

	//operations:
	void setFirstName(std::string name);
	void setLastNAme(std::string name);
	void setAge(int a);

	std::string getFirstName() const;
	std::string getLastName() const;
	int getAge() const;
	std::string toString() const;
};