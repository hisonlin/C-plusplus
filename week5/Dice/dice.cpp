# include <iostream>
# include <random>
# include <ctime>
# include <array>
# include <iomanip>//for formatting output
# include <sstream>

using namespace std;

//This program rolls a dice o 6 sides, a number of tims and prints the probability fro each sid of the dice.

//This function roll a dice once and returns ths side up number (a number between 1 and 6)
int rollDise()
{
	int num = rand();
	return num % 6 + 1;
}

int main(int argc, char** argv)
{
	//for build
	if (argc < 2)
	{
		cout << "Usage: Dice totalCount (it is an integer)\n";
		return 1;
	}
	else
		cout << "totalcount: " << argv[1] << endl;

	//srand(time(0));
	default_random_engine engine(time(0));
	uniform_int_distribution<unsigned int> randomInt{ 0,5 };
	string countSt = argv[1];
	stringstream ss{ countSt };
	int totalCount = 100;//default value, total Number of rolling a dice
	ss >> totalCount;//reasign
	
	int frequencyArry[6]{ 0, 0, 0, 0, 0, 0 }; //using native C array, representing the number of times of each side face one

	for (int i = 0; i < totalCount; ++i)
	{
		int face = randomInt(engine);	//rollDise();
		frequencyArry[face]++;	//[face - 1]++;

	}

	cout << "Face" << setw(13) << "Frequency" << endl;
	
	cout << "   1" << setw(13) << frequencyArry[0] << endl
		<< "   2" << setw(13) << frequencyArry[1] << endl
		<< "   3" << setw(13) << frequencyArry[2] << endl
		<< "   4" << setw(13) << frequencyArry[3] << endl
		<< "   5" << setw(13) << frequencyArry[4] << endl
		<< "   6" << setw(13) << frequencyArry[5] << endl;
	
	
	return 0;

}