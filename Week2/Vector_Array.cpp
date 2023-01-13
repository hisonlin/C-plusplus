#include <iostream>
#include <array>
#include <vector>

using namespace std;

//declaring a function
void printVector(vector<int> vec);

int main()
{
	/*	int count{};  // initializes count to default value for int
		std::cout<<"What is your name?\n";
		std::string myname{"NotSetYet"};
		std::string mylastname{"Notset"};
		//std::cin>>myfirstname>>mylastname;
		std::getline(myname);
		myprint(myname); // change myprint() to receive the string and print it.
	*/

	// arrays in c++:
	array<int, 5> my5Numbers{ 4, 5, 6 };
	my5Numbers[3] = 7;
	my5Numbers.at(4) = 8;
	for (int i = 0; i < my5Numbers.size(); ++i)
	{
		cout << "valu at " << i << " is " << my5Numbers.at(i) << endl;
	}
	
	my5Numbers[2] = 9;

	for (auto item : my5Numbers)
	{
		cout << "item = " << item << endl;
	}
	
	vector<int> myInts{};
	cout<<"Size of myInts: "<<myInts.size()<<endl;
	myInts.push_back(1);
	cout<<"Size of myInts: "<<myInts.size()<<endl;
	myInts.push_back(2);
	cout<<"Size of myInts: "<<myInts.size()<<endl;
	myInts.push_back(3);
	cout<<"Size of myInts: "<<myInts.size()<<endl;
	myInts.push_back(4);
	cout<<"Size of myInts: "<<myInts.size()<<endl;

	//print content of the vector myInts
	printVector(myInts);

	//let's add 4 more items: add double of first 4 item value
	for (auto item : myInts)
	{
		myInts.push_back(item * 2);

	}
	printVector(myInts);

	//removing 2 items from the back
	myInts.pop_back();
	myInts.pop_back();
	printVector(myInts);

	//printing a vector using iterators:
	for (auto it = myInts.begin(); it < myInts.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//insert three 22 at index 2
	auto index2It = myInts.begin() + 2;
	myInts.insert(index2It, 3, 22);

	cout << "Print after insert: \n";

	printVector(myInts);

	//myInts[2] = 9;

	//Create a vector have hundred 10
	vector<int> secondVec(100, 10);
	for(auto item : secondVec)
		cout<<"secondVec item : "<<item<<endl;
	
	//create an array of 5 strings and put "str0", "str1", ..."str4" in it and print it.
	array <string,5> testArr{"str1","str2","str3","str4","str5"};
    for (auto& item : testArr)	
		cout << item << endl;

	//a utility function to print a vector:
	void printVector(vector<int> vec)
	{
		for (auto item : vec)
		{
			cout << item << " ";

		}
		cout << "\n";
	}
	
	return 0;
}


