#include "../include/utility.h"
#include <iostream>
using namespace std;

string getString(string& dst, string msg, int tabs) {
    for (int i = 0; i < tabs; i++)
        cout << '\t';
    cout << msg;
    cin >> dst;
    return dst;
}

int getNumber(int min, int max, int tabs) {
    int ret = 0;
    do {
        for (int i = 0; i < tabs; i++)
            cout << '\t';
        cout << "Write a number [" << min << "-" << max << "]: ";
        cin >> ret;
    } while (ret < min || ret > max);
    return ret;
}

void getChar(string& dst) {
    cout << "Make your choice: ";
    cin >> dst;
    // Convert first char to uppercase ready for switch
    dst = toupper(dst.at(0));
}

string getNationAbbreviation(int tabs) {
    string ret;
    // Keep asking for input until we have string with length 3
    do {
        for (int i = 0; i < tabs; i++)
            cout << '\t';
        cout << "Write nation abbreviation: ";
        cin >> ret;
    } while (ret.size() != 3);
    return ret;
}