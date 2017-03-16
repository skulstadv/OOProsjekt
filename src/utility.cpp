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