#include <iostream>
#include <array>
class Base {
public:
	int basenum;
	virtual void print() { std::cout << "Base\n"; }

};

class Derived1 : public virtual Base {
public:
	int derive1;
	virtual void print() { std::cout << "Derive1\n"; }
};

class Derived2 : public virtual Base {
public:
	int derive2;
	virtual void print() { std::cout << "Derive2\n"; }
};

class Diamond : public Derived1, public Derived2 {
public:
	int diamond;
	virtual void print() { std::cout << "Diamond\n"; }
};

int main()
{
	Base base1;
	Derived1 d1;
	Derived2 d2;
	Diamond di;
	base1.print();
	d1.print();
	d2.print();
	di.print();
	return 0;

	std::array<Base*, 4> myobjects;
	myobjects[0] = &base1;
	myobjects[1] = &d1;//casts d1 to Base
	myobjects[2] = &d2;//casts d2 to Base
	myobjects[3] = &di;//casts di to Base

	for (int i = 0; i < myobjects.size(); ++i)
	{
		myobjects[i].print();
	}
}