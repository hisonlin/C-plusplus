#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>

#include "person.h"
#include "soccerPlayer.h"
#include "basketballPlayer.h"


class SoccerBasketPlayer : public SoccerPlayer, public BasketballPlayer
{
public:
	SoccerBasketPlayer(std::string f, std::string l, int a) : SoccerPlayer(f, l, a), BasketballPlayer(f, l, a), soccerPercent(0.f)
	{
		std::cout << "SoccerBasketPlayer created\n";
	}
	float getSoccerPercent()const
	{
		return soccerPercent;
	}

	void setSoccerPercent(float f)
	{
		if (f > 1.f || f < 0.f)
		{
			std::cerr << "setSoccerPercent: invalue value. It should be between 0 and 1: " << f << std::endl;
			return;
		}
		soccerPercent = f;
	}
private:
	float soccerPercent;//represents percentage of time playing each sport
};