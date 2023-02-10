#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>

#include "person.h"

class SoccerPlayer : virtual public Person
{
public:
	SoccerPlayer(std::string f, std::string l, int a) : Person(f, l, a)
		, goalAveragePerGame(0.f)
		, goalAssistAverage(0.f)
	{
		std::cout << "SoccerPlayer created\n";
	}

	// add getters:

	//add setters:
	void setGoalAssistAverage(float val)
	{
		goalAssistAverage = val;
	}

	// overriding toString() from the base class
	std::string toString() const
	{
		std::stringstream ss{};
		ss << Person::toString() << ": goalAverage = " << std::setprecision(1) << goalAveragePerGame << ", assistAverage=" << goalAssistAverage << std::endl;

		return ss.str();
	}

	// over-loading example
	void setFirstName(std::string name, std::string club)
	{
		first = club + ":" + name;
	}

	// over-loading of setFirstName method in base class
	void setFirstName() {}

private:
	float goalAveragePerGame;
	float goalAssistAverage;
};



