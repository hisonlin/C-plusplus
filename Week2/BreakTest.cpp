// Fig. 5.13: BreakTest.cpp
// break statement exiting a for statement.
#include <iostream>
using namespace std;

int main() 
{
	int count = 1;
   for (count = 1; count <= 10; count += 2) 
   { // loop 10 times
      if (count == 5) {
         break; // terminates loop if count is 5
      }

      cout << count << " ";
   }

   cout << "\nBroke out of loop at count = " << count << endl;
   
   return 0;
} 

