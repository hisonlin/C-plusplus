#include <iostream>
#include "linkedList.h"

using namespace std;
int main()
{
	LinkList<int> intlist;
	intlist.push_back(12);
	intlist.push_back(1);
	intlist.push_front(45);
	std::cout << intlist << std::endl;

	intlist.push_back(23);
	intlist.push_back(75);
	intlist.push_front(22);
	intlist.push_back(96);
	intlist.push_back(6);
	intlist.push_back(8);
	intlist.push_back(78);
	intlist.push_back(35);
	std::cout << intlist << std::endl;

	std::cout << "testing find:\n";
	std::cout << "list contains 12? " << intlist.find(12) << std::endl;
	std::cout << "list contains 22? " << intlist.find(22) << std::endl;
	std::cout << "list contains 8? " << intlist.find(8) << std::endl;

	intlist.pop_back();
	intlist.remove(6);
	std::cout << intlist << std::endl;

	intlist.pop_back();
	std::cout << intlist << std::endl;

	intlist.insertAfter(11, 22);
	std::cout << intlist << std::endl;

	//Ascending order
	intlist.bubblesort<std::less<int>>();
	std::cout << "after sorting" << intlist << std::endl;

	//Descending order
	intlist.bubblesort<std::greater<int>>();
	std::cout << "after sorting" << intlist << std::endl;

	return 0;

}

