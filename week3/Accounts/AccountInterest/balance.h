#pragma once
#include <cmath>
#include <string>
#include <iostream>


//long long is integer with 8 byte
typedef long long int64_t;

//a class has special methods: constructor, destructor, copy constructor, assignment operator
class DollarAmount {

public:
	//constructor
	DollarAmount(int64_t value)
	{
		amount = value;
	}
	//same here
	//DollarAmount(int64_t value) : amount(value)
/*
	//default constructor
	DollarAmount()
	{
		amount = 0;
	}
	*/
	//same here
	//DollarAmount() : amount(0)
	/*
	//copy constructor
	DollarAmount(const DollarAmount& src) : amount(src.amount)
	{
		//std::cout << "\nCopy constructor called\n";
	}

	//assignment operator:
	DollarAmount& operator = (const DollarAmount& src)
	{
		//std::cout << "\nAssignment operator called\n";
		amount = src.amount;
		return *this;
	}
	*/
	//if we do not use & , we just use the value of the parameter
	void add(const DollarAmount& val)
	{
		amount += val.amount;
		//val.amount = 0;
	}

	void add(unsigned int dollar, unsigned int cents)
	{
		amount = amount + int64_t(dollar) * 100 + cents;
	}

	//if using & (reference), the parameter will be modified
	void addr(DollarAmount& val)
	{
		amount += val.amount;
		//val.amount = 0;
	}

	void subtract(DollarAmount val)
	{
		amount -= val.amount;
	}

	//return a string representing the dollar amount of this object
	std::string toString()
	{
		std::string dollarsStr = std::to_string(amount / 100);//to_string does this: 19 -->"19"
		std::string centsStr = std::to_string(amount % 100);//220 cents --> 2dollars and 20 cents
		return dollarsStr + "." + (centsStr.size() == 1 ? "0":"") + centsStr;
	}

	//add interest using int rate. It means for exmaple for rate of 2.345% we are going to use 2345 and provide a divider 1000
	void addInterest(int rate, int divisor)
	{
		//first compute the interest then add to the amount
		DollarAmount interest((amount * rate) / divisor);
		add(interest);//amount = amount + interest.amount

	}

private:
	int64_t amount; //64 bit integer. This is the balance on an account. It is pennies.

};