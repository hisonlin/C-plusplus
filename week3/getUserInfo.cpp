#include <iostream>
#include <string>
#include "myheader.h"
using namespace std;


namespace cstp1205 {

	void getUserInfo()
	{
		string firstName = "";
		string lastName = "";
		string id = "";
		cout << "Please enter your first name:\n";
		cin >> firstName;
		cout << endl;
		cout << "Please enter your last name:\n";
		cin >> lastName;
		cout << endl;
		cout << "Please enter your ID:\n";
		cin >> id;
		cout << endl;

		cout << "ID of " + firstName + " " + lastName + " is " + id << endl;

	}
}
