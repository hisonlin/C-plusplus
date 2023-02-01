/*This ia a simple implementation of game of craps as a single player against the house(computor)*/
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

enum class Status {CONTINUE, WON, LOST};// ot be used to represent the status of the player
unsigned int rollDice();// declaration for the function which roll 2 dice and returns the sum of their face

// global variavle to be used in the random number generator:
default_random_engine theEngine(time(0));
uniform_int_distribution<unsigned int> theGenerator{ 1, 6 };

int main() 
{
	Status gameStatus{Status::CONTINUE}; // status of the player at the start is CONTINUE

	unsigned int thePoint{};

	//below we implement the logic of the game
	unsigned thePlay = rollDice();
	if (thePlay == 7 || thePlay == 11)
	{
		gameStatus = Status::WON;
		cout << "You Win!\n";
	}
		
		
	else if (thePlay == 2 || thePlay == 3 || thePlay == 12)
	{
		gameStatus = Status::LOST;
		cout << "You Loss!\n";
	}
		
	else if (thePlay == 4 || thePlay == 5 || thePlay == 6 || thePlay == 8 || thePlay == 9 || thePlay == 10)
	{
		gameStatus = Status::CONTINUE;
		thePoint = thePlay;
		cout << "Continue!\n";
		//continus play below try to "make the point". If 7 happens you lose
		unsigned int playAgain = 0;
		do
		{
			unsigned int playAgain = rollDice();
			thePoint += playAgain;
			cout << thePoint << endl;

		} while (playAgain != 7);


	}

	return 0;
}

unsigned int rollDice()
{
	cout << "To roll the dice type 'r': ";
	char response{};
	cin >> response;
	// call the generator 2 times to simulate rolling dice 2 times. Then result the total
	unsigned int firstRoll = theGenerator(theEngine);
	unsigned int secondRoll = theGenerator(theEngine);
	auto total = firstRoll + secondRoll;
	cout << "Total is " << total << endl;
	return firstRoll + secondRoll;
}




