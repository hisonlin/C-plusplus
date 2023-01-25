#pragma once

#include "balance.h"
#include <string>

class Account
{
public:
	enum AccountType
	{
		chequing,
		saving
	};

	//constructor:
	Account(std::string accountHolderName, DollarAmount initialBalance, AccountType theType) :
		name(accountHolderName), balance(initialBalance), type(theType)
	{

	}

	//setters:
	void setName(std::string theName)
	{
		name = theName;
	}

	void setBalance(DollarAmount newBalance)
	{
		balance = newBalance;
	}

	void setType(AccountType theType)
	{
		type = theType;
	}
	

	//getters:
	std::string getName()const
	{
		return name;
	}

	DollarAmount getBalance()const
	{
		return balance;
	}

	AccountType getType()const
	{
		return type;
	}

	//deposit:
	DollarAmount deposit(DollarAmount depo)
	{
		balance.add(depo);
		return balance;
	}
	//overload deposit
	DollarAmount deposit(unsigned int dollar, unsigned int cents)
	{
		balance.add(dollar, cents);
		return balance;

	}

	//withdraw
	DollarAmount withdraw(DollarAmount with)
	{
		balance.subtract(with);
		return balance;
	}

private:
	std::string name; //this is account holder full name
	DollarAmount balance; //balance in thsi account
	AccountType type;
};