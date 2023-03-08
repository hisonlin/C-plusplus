#include <iostream>
#include <memory>
#include "bookAuthor.h"

using namespace std;

int main()
{
	shared_ptr<Book> cplusplusBookPtr = make_shared<Book>("C++ How to program");
	shared_ptr<Author> authorPtr = make_shared<Author>("Deitel & Deitel");
	authorPtr->setBook(cplusplusBookPtr);
	cplusplusBookPtr->setAuthor(authorPtr);

	//print out reference count
	cout << authorPtr.use_count() << endl;
	cout << cplusplusBookPtr.use_count() << endl;
	authorPtr->printBookTitle();
	return 0;
}