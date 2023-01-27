# include <iostream>
using namespace std;

int main()
{
	//let's create a native int array:
	int scores[]{84, 92, 75, 88, 79, 80};
	int numScores = size(scores);

	//let's find the max score:
	int max = 0;
	for (auto item : scores)
	{
		if (item > max)
			max = item;
	}

	cout << "Max Scores is " << max << ".\n";

	//2d array:
	int TwoDArr[3][2]{ {4, 8}, {21, 7}, {43, 2} };
	int total = 0;
	for (int i = 0; i < 3; ++i)
	{ 
		for (int j = 0; j < 2; ++j)
		{
			total += TwoDArr[i][j];
		}
	}
	cout << "total = " << total << endl;

		

	return 0;
}