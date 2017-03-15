#ifndef OOProject_UTILITY_H_
#define OOProject_UTILITY_H_
#include <string>

// Prints -msg to screen and reads from keyboard into -dst
std::string getString(std::string& dst, std::string msg);

// Gets a number in interval -min to -max inclusive
// Inserts -tabs '\t' chars before printing message
// -return the number [min-max]
int getNumber(int min, int max, int tabs);

// Gets a char from user, puts into -dst and converts to uppercase
void getChar(std::string& dst);

// Gets a nation abbreviation (string with length 3) from user 
// Inserts -tabs '\t' chars before printing message
std::string getNationAbbreviation(int tabs);


#endif