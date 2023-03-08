#pragma once
#include <iostream>
#include <string>

//This class represent a phone number in format of
//example 604-443-1380
//Create a class which save the above 3 numbers as strings
//Overload << and >> operators to print out the phone number
//like(604)443-1380. The input operator accepts data in format of dash separated like 604-443-1380
//If the input format is not correct, you must ask user to try agianfor put

class PhoneNumber {
private:
    std::string areaCode;
    std::string prefix;
    std::string lineNumber;

public:
    PhoneNumber() {}

    PhoneNumber(std::string ac, std::string pr, std::string ln) : areaCode(ac), prefix(pr), lineNumber(ln) {}

    friend std::ostream& operator<<(std::ostream& os, const PhoneNumber& pn) {
        os << "(" << pn.areaCode << ")" << pn.prefix << "-" << pn.lineNumber;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, PhoneNumber& pn) {
        std::string input;

        // Ask for input until a valid format is provided
        bool isValidFormat = false;
        do {
            std::cout << "Enter a phone number in the format 123-456-7890: ";
            std::getline(is, input);

            if (input.length() == 12 &&
                input[3] == '-' &&
                input[7] == '-') {
                bool isNumeric = true;
                for (int i = 0; i < 12; i++) {
                    if (i == 3 || i == 7) {
                        continue;
                    }
                    if (!std::isdigit(input[i])) {
                        isNumeric = false;
                        break;
                    }
                }
                if (isNumeric) {
                    isValidFormat = true;
                }
            }
        } while (!isValidFormat);

        // Extract area code, prefix, and line number from input
        pn.areaCode = input.substr(0, 3);
        pn.prefix = input.substr(4, 3);
        pn.lineNumber = input.substr(8, 4);

        return is;
    }
};
