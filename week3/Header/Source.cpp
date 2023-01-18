#include <iostream>
#include <string>
#include "myheader.h"
using namespace std;
//using namespace cstp1205;



//a simple function that receives a messafe from user and print it
//1. Pre-compilation stage
//2. compile object files (translation units)
//3. Linking(putting all obj files together and create exe file)


int main()
{
	cstp1205::getUserInfo();
	cstp1205::myPrint("1205");
	cstp1104::myPrint("1104");
	return 0;
}

