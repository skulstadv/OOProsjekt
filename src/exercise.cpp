#include "../include/main.h"
#include "../include/exercise.h"
#include "../include/participant.h"
#include "../include/ListTool2B.h"
#include "../include/utility.h"
#include <iostream>
using namespace std;


Exercise::Exercise(int n) : NumElement(n) {
    participants_id = new List(Sorted); //define participants and results list
    results = new List(Sorted);
    name = new string();                //define name
    int day, month, year;
    // Get name of participant from user
    getLine(*name, "Enter name of the Excercise: ", 2);

    // Get the time of the excercise from the user
    int hour = getInt(0, 23, 2, "Enter the time of the excercise\n\t\tHour: ");
    int minute = getInt(0, 59, 2, "Minute: ");

    //Sets the time
    time_of_day = ((hour * 100) + minute);

    //gets the date from the user
    //loops while date is illegal
    do {
        day = getInt(1, 31, 2, "Enter the time of the excercise\n\t\tDay: ");
        month = getInt(1, 12, 2, "Month: ");
        year = getInt(2016, 2100, 2, "Year: ");
        if (checkdate(day, month, year) == 0) {
            cout << "Please enter a valid date!\n\n";
        }

    } while (checkdate(day, month, year) == 0);
    date = ((year * 10000) + (month * 100) + (day));
}

void Exercise::display() {
    cout << "\t\tName of the excercise: " << *name << '\n';
    cout << "\t\tDate: " << date << '\n';
    cout << "\t\tTime: ";
    //cout additional zero if hour is between 00 and 12
    if ((time_of_day % 10000) < 1000) {
        cout << "0";
    }
    //cout aditional zero if hour is 00;
    if (((time_of_day % 10000) % 1000) < 100) {
        cout << "0";
    }
    cout << time_of_day << '\n';
}


void Exercise::displayParticipants() {
    int id;
    // participants_id list exists of NumElements. Temp for our ne
    NumElement* ne;
    // Listtool origin index = 1 (!)
    for (int i = 1; i <= participants_id->noOfElements(); i++) {
        ne = (NumElement*)participants_id->removeNo(i);
        id = ne->getNumber();
        participants->getParticipant(id)->display();
        participants_id->add(ne);
    }
}

bool Exercise::addParticipantID(int n) {
    NumElement* temp;
    temp = new NumElement(n);
    return participants_id->add(temp);
}

bool Exercise::removeParticipantID(int n) {
    return (participants_id->remove(n) != nullptr);
}

List* Exercise::getResultsList() {
    return results;
}

List* Exercise::getParticipantsIDList() {
    return participants_id;
}

void Exercise::setName() {
    getLine(*name, "Enter name of the Excercise: ", 2);
}

void Exercise::setDate() {
    int day, month, year;
    do {
        day = getInt(1, 31, 2, "Enter the date of the excercise\n\t\tDay: ");
        month = getInt(1, 12, 2, "Month: ");
        year = getInt(2016, 2100, 2, "Year: ");
        if (checkdate(day, month, year) == 0) {
            cout << "Please enter a valid date!\n\n";
        }

    } while (checkdate(day, month, year) == 0);
    date = ((year * 10000) + (month * 100) + (day));
}

void Exercise::setTime() {
    // Get the time of the excercise from the user
    int hour = getInt(0, 23, 2, "Enter the time of the excercise\n\t\tHour: ");
    int minute = getInt(0, 59, 2, "Minute: ");

    //Sets the time
    time_of_day = ((hour * 100) + minute);
}

string Exercise::getName() {
    return *name;
}