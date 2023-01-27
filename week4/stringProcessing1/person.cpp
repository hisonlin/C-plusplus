#include "person.h"
#include <iostream>

Person::Person(std::string f, std::string l, int a) :
	first(f), last(l), age(a)
{
}

//setters
void Person::setFirstName(std::string name)
{
	if (name.length() <= 0)
	{
		std::cout << "setFirstName: emply name setting ignored\n";
		return;
	}
	first = name;
}

void Person::setLastNAme(std::string name)
{
	if (name.length() <= 0)
	{
		std::cout << "setLastName: emply name setting ignored\n";
		return;
	}
	last = name;
}

void Person::setAge(int a)
{
	if (a < 0)
	{
		std::cout << "setAge: negative age setting ignored\n";
	}
	age = a;
}

//getters
std::string Person::getFirstName() const
{
	return first;

}

std::string Person::getLastName() const
{
	return last;

}

int Person::getAge() const
{
	return age;

}

std::string Person::toString() const
{
	std::string result = "Person: " + first + last + ": age=" + std::to_string(age);
	return result;

}
