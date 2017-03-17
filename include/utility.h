#ifndef OOProject_UTILITY_H_
#define OOProject_UTILITY_H_
#include <string>

// Prints -msg to screen and reads word from keyboard into -dst
// Inserts -tabs '\t' chars before printing message
std::string getString(std::string& dst, std::string msg, int tabs);

// Prints -msg to screen and reads line from keyboard into -dst
// Inserts -tabs '\t' chars before printing message
std::string getLine(std::string& dst, std::string msg, int tabs);

// Gets a number in interval -min to -max inclusive
// Inserts -tabs '\t' chars before printing message
// -return the number [min-max]
int getInt(int min, int max, int tabs, std::string msg = "Write a number ");

// Gets a char from user, puts into -dst and converts to uppercase
void getChar(std::string& dst);

// Gets a nation abbreviation (string with length 3) from user 
// Inserts -tabs '\t' chars before printing message
std::string* getNationAbbreviation(int tabs);

// Checks for valid date, takes day, month and year as parameters
bool checkdate(int day, int month, int year);

// Checks given year for leapyear, takes year as parameter
bool leapYear(int year);

#endif