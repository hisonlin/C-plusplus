#include "account.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	//Create an account
	Account janeAccount("Jane dow", DollarAmount(100000), Account::AccountType::chequing);

	cout << "Account name is " << janeAccount.getName() << endl;
	
	DollarAmount val = janeAccount.getBalance();
	val.add(DollarAmount(50000));

	cout << "New balance on Jane is " << janeAccount.getBalance().toString() << endl;

	//janeAccount.deposit(100, 50);

	return 0;
}