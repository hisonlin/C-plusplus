#include <iostream>
using namespace std;

class NUM {
	int val;
public:
	NUM(int n) : val(n) {
		cout << "NUM created: " << val << endl;
	}
	~NUM() {
		cout << "~NUM called: " << val << endl;
	}
	NUM(const NUM& rhs) {
		cout << "copy constructor called\n";
		val = rhs.val;
	}

	NUM& operator=(const NUM & rhs ) {
		cout << "assignment operator called\n";
		if (&rhs != this)
		{
			val = rhs.val;
		}
		return *this;
	}

	int getVal() const {
		return val;
	}
};

int main()
{
	shared_ptr<NUM> a { new NUM(10) }; //we create a shared pointer called a that point to NUM(10)
	shared_ptr<NUM> b{ make_shared<NUM>(20) };//similar to new, more efficient

	//use_count(): returns the number of shared_ptr objects that are currently sharing ownership of the managed object.
	cout << "reference count for a = " << a.use_count() <<endl;//1
	cout << "\nreference count for b = " << b.use_count() << endl;//1

	//use -> when you are in pointer
	cout << "\nvalue of Num in a is " << a -> getVal() <<endl;//10

	shared_ptr<NUM> c = a;
	cout << "\nreference count for a = " << a.use_count() << endl;//2
	cout << "\nreference count for c = " << c.use_count() << endl;//2

	return 0;
}