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
    getLine(*name, "Enter name of the Excersise: ", 2);

    // Get the time of the excersise from the user
    int hour = getInt(0, 23, 2, "Enter the time of the excersise\n\t\tHour: ");
    int minute = getInt(0, 59, 2, "Minute: ");

    //Sets the time
    time_of_day = ((hour * 100) + minute);

    //gets the date from the user
    //loops while date is illegal
    do {
        day = getInt(1, 31, 2, "Enter the time of the excersise\n\t\tDay: ");
        month = getInt(1, 12, 2, "Month: ");
        year = getInt(2016, 2100, 2, "Year: ");
        if (checkdate(day, month, year) == 0) {
            cout << "Please enter a valid date!\n\n";
        }

    } while (checkdate(day, month, year) == 0);
    date = ((year * 10000) + (month * 100) + (day));
}

void Exercise::display() {
    cout << "Name of the Excersise: " << name << '\n';
    cout << "Date: " << date << '\n';
    cout << "Time: ";
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
    Participant* temp;
    //Gets number of elements in ist
    int i = participants_id->noOfElements();
    if (i != 0) {
        for (int j = 1; j <= i; j++) {
            temp = (Participant*)participants_id->removeNo(j);
            temp->display();
            participants_id->add(temp);
        }
    }
    else(cout << "There are no participants listed for this excersise!");
}

bool Exercise::addParticipantID(int n) {
    Participant* temp;
    if (!(participants_id->inList(n))) {
        temp = new Participant(n);
        participants_id->add(temp);
        return true;
    }
    return false;
}

bool Exercise::removeParticipantID(int n) {
    if ((participants_id->inList(n))) {
        participants_id->destroy(n);
        return true;
    }
    return false;
}

List * Exercise::getResultsList() {
    return results;
}
