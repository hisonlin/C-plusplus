#pragma once
#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>

#include "person.h"
//use virtual inheritance to fix the dreaded diamond problem when you need to use multiple inheritance
class BasketballPlayer : virtual public Person
{
public:
	BasketballPlayer(std::string f, std::string l, int a) : Person(f, l, a)
		, pointAveragePerGame(0.f)
		, assistAverage(0.f)
		, reboundAverage(0.f)

	{
		std::cout << "BasketballPlayer created\n";
	}

	// add getters:

	//add setters:
	void setGoalAssistAverage(float val)
	{
		pointAveragePerGame = val;
	}

	// overriding toString() from the base class
	std::string toString() const
	{
		std::stringstream ss{};
		ss << Person::toString() << ": pointAverage = " << std::setprecision(1) << pointAveragePerGame << ", assistAverage=" << assistAverage << std::endl;

		return ss.str();
	}

private:
	float pointAveragePerGame;
	float assistAverage;
	float reboundAverage;
};



