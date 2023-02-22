#include <iostream>
#include <string>
#include <regex>
#include "phoneNumber.h"
using namespace std;
int main() {
    PhoneNumber pn;
    std::cin >> pn;
    std::cout << "You entered: " << pn << std::endl;
    return 0;
}