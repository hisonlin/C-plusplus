# include <iostream>
#include <array>
#include<vector>
#include <algorithm>//use for sort and search
using namespace std;

const size_t arraySize = 7;
void printArray(array<string,arraySize>& arr)
{
	cout << "\nArr: ";
	for (auto& val : arr)
		cout << val << ", ";
	cout << endl;
}
bool stringLengthCompare(string str1, string str2)
{
	if (str1.length() == str2.length())
		return str1 < str2;
	return str1.length() < str2.length();
	/*
	if(str1.length() < str2.length())
		return true;
	else if(str1.length() == str2.length())
	{
		if(str1[0] < str2[0])
			return true;
	}
	return false;
	*/
}

template<typename T>
T square(T x) {

	return x * x;
}

//exercise: write a function called maximum that returns the max value among 3 value, use template
template<typename T>
T maximum(T a, T b, T c)
{
	T max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
	//return max(max(a, b), c);
}

string maximum1(string str1, string str2, string str3)
{
	string max = str1;
	if (str2.length() > max.length())
		max = str2;
	if (str3.length() > max.length())
		max = str3;
	return max;

}

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

	
	array < string, arraySize> colors = { "red", "orange", "yellow", "green", "blue", "indigo", "violet" };

	printArray(colors);
	//use sort to sort colors:
	sort(colors.begin(), colors.end(), stringLengthCompare);
	printArray(colors);

	auto it = find(colors.begin(), colors.end(), "blue");
	if (it != colors.end())
		cout << "Cyan was found\n" << *it << endl;
	else
		cout << "Cyan was not found\n";


	//learn and practice with template:
	cout << "square os 38 is " << square(38) << endl;
	cout << "square os 38.4 is " << square(38.4f) << endl;
	cout << "Max of 23, 91, 18 is " << maximum(23.0, 91.0, 91.8) << endl;
	cout << "Max of 34.893, 12.9, 88.04 is " << maximum(34.893, 12.9, 88.04) << endl;
	cout << maximum1("house", "dog", "cucumber") << endl;



		

	return 0;
}