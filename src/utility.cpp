#include "../include/utility.h"
#include <iostream>
using namespace std;

string getString(string& dst, string msg, int tabs) {
    for (int i = 0; i < tabs; i++)
        cout << '\t';
    cout << msg;
    cin >> dst;
    cin.ignore();
    return dst;
}

string getLine(std::string & dst, std::string msg, int tabs) {
    for (int i = 0; i < tabs; i++)
        cout << '\t';
    cout << msg;
    getline(cin, dst);
    return dst;
}

int getInt(int min, int max, int tabs, string msg) {
    int ret = 0;
    do {
        for (int i = 0; i < tabs; i++)
            cout << '\t';
        cout << msg << "[" << min << "-" << max << "]: ";
        cin >> ret;
        cin.ignore();
    } while (ret < min || ret > max);
    return ret;
}

void getChar(string& dst) {
    cout << "Make your choice: ";
    cin >> dst;
    cin.ignore();
    // Convert first char to uppercase ready for switch
    dst = toupper(dst.at(0));
}

string* getNationAbbreviation(int tabs) {
    string* ret = new string();
    // Keep asking for input until we have string with length 3
    do {
        for (int i = 0; i < tabs; i++)
            cout << '\t';
        cout << "Write nation abbreviation: ";
        cin >> *ret;
        cin.ignore();
    } while ((*ret).size() != 3);
    // To uppercase
    (*ret)[0] = toupper((*ret).at(0));
    (*ret)[1] = toupper((*ret).at(1));
    (*ret)[2] = toupper((*ret).at(2));
    return ret;
}

bool checkdate(int day, int month, int year) {

    //  Set date for day in given month
    //  Value for february is set later
    int daysPerMonth[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int totalDays, i;

    if (year < 2016 || year > 2100) return 0;    //  Illegal year.
    if (month < 1 || month > 12)   return 0;     //  illegal month.
                                                 //  Value for february is set  if leapyear
    daysPerMonth[1] = (leapYear(year)) ? 29 : 28;
    if (day < 1 || day > daysPerMonth[month - 1])  return 0;  // illegal day
                                                          // Guaranteed legal date
    totalDays = day;
    for (i = 0; i < month - 1; i++)              // calculate daynumber of day
        totalDays += daysPerMonth[i];

    if (totalDays)
        return true;
    else
        return false;
}

bool leapYear(int year) {

    //check if a given year is a leapyear
                      //  leapyear if abel to divide by 400 or 
                      //   able to divide by 4 but not 100
    return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100) != 0));
}