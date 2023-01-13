// Fig. 5.7: fig05_07.cpp
// do...while repetition statement.
#include <iostream>
using namespace std;

int main()
{
   unsigned int counter = 1; // initialize counter //unsigned means can not be negative

   do 
   {
      cout << counter << " "; // display counter
      ++counter; // increment counter
	  
	  if ( counter == 5)
	  {
		break;
	  }
	  
   } while ( counter <= 10 ); // end do...while 

   cout << endl; // output a newline
   
   return 0;
} // end main



