
#include <iostream>

#include "person.h"
#include "soccerPlayer.h"
#include"basketballPlayer.h"
#include"SoccerBasketPlayer.h"



int main()
{
	//Person anonymousPerson;

	Person person1("Adam", "Sandler", 45);

	Person mydummy = person1.dummyPersonCreator();

	std::cout << person1.getFirstName() << std::endl;

	SoccerPlayer ronaldo("Christiano", "Ronaldo", 37);

	std::cout << "Ronaldo's first name is " << ronaldo.getFirstName() << std::endl;

	ronaldo.setGoalAssistAverage(0.432f);

	std::cout << ronaldo.toString() << std::endl;

	// use soccerplayer class setFirst name to chang Ronaldo's first name to AlNasr:Christiano and then print the info using toString.
	ronaldo.setFirstName("Christiano", "ALNASR");
	std::cout << std::endl << ronaldo.toString() << std::endl;

	//testing soccerBasketPlayer:
	SoccerBasketPlayer ringo("Ringo", "James", 35);
	ringo.setSoccerPercent(0.3f);


	return 0;
}