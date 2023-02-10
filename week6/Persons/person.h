#pragma once
#include<iostream>
#include <string>

class Person
{
private:
	std::string last;
	
	int age;  // in years.
	
protected:
	std::string first;// it is now available to both this class and all classes which derive from this class.
	Person() : first("NoName "), last("None"), age(0)  // private construcor, means only accessible from inside the class
	{
		std::cout << "Person constructor called\n";
	}
	  

public:
	//constructors
	//Person() = delete;   // default constructor is not acceptable for our application here.
	explicit Person(std::string f, std::string l, int a);
	Person dummyPersonCreator()
	{
		Person adummy;  // using private constructor
		return adummy;
	}

	//Person(const Person& src) = delete;
	Person& operator=(Person const& src) = delete;   // assignment operator is disabled
	bool operator==(Person const& src)   // comparison operator
	{
		if (first == src.first && last == src.last && age == src.age)
			return true;
		return false;
	};


	//set operations:
	void setFirstName(std::string name);
	void setLastName(std::string name);
	void setAge(int a);

	// get operations:
	std::string getFirstName() const;
	std::string getLastName() const;
	int getAge() const;


	std::string toString() const;
};
