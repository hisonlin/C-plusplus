#include<iostream>
#include<random>
#include<ctime>
#include<iomanip>//for formatting output
//This program rolls a dice o 6 sides, a number of tims and prints the probability fro each sid of the dice.

//This function roll a dice once and returns ths side up number (a number between 1 and 6)
int rollDise()
{
	int num = rand();
	return num % 6 + 1;
}

int mian(int argc, char** argv) 
{
	srand(time(0));
	int totalCount = 100;//total Number of rolling a dice
	int frequencyArry[6]{0, 0, 0, 0, 0, 0}; //using native C array, representing the number of times of each side face one

	for (int i = 0; i < totalCount; ++i)
	{
		int face = rollDise();
		frequencyArry[face-1]++;
		
	}

	std::cout << "Face" << std::setw(13) << "Frequency" << std::endl;
	std::cout << "   1" << std::setw(13) << frequencyArry[0] << std::endl
		<< "   2" << std::setw(13) << frequencyArry[1] << std::endl
		<< "   3" << std::setw(13) << frequencyArry[2] << std::endl
		<< "   4" << std::setw(13) << frequencyArry[3] << std::endl
		<< "   5" << std::setw(13) << frequencyArry[4] << std::endl
		<< "   6" << std::setw(13) << frequencyArry[5] << std::endl;
	
	return 0;

}