#pragma once
#include <cmath>
#include <string>

typedef long long int64_t;

class DollarAmount {

public:
	//constructor
	DollarAmount(int64_t value)
	{
		amount = value;
	}

	void add(DollarAmount val)
	{
		amount += val.amount;
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
