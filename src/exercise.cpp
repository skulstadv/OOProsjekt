#include "../include/main.h"
#include "../include/exercise.h"
#include "../include/result.h"
#include "../include/participant.h"
#include "../include/ListTool2B.h"
#include "../include/utility.h"
#include <iostream>
using namespace std;


Exercise::Exercise(int n, std::ifstream & in) : NumElement(n) {
    participants_id = new List(Sorted); 
    results = new List(Sorted);
    name = new string();               

    // Read name of exercise from file
    getline(in, *name);
    // Read time of day and date
    in >> time_of_day >> date;
    // Reading all participants of exercise
    readParticipantsFromFile();
    // Read results from file 
    readResultsFromFile();
}

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
    cout << "\t\t\tName of the excercise: " << *name << '\n';
    cout << "\t\t\tID of exercise: " << number << '\n';
    cout << "\t\t\tDate: " << date << '\n';
    cout << "\t\t\tTime: ";
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
    if (results->inList(n))
        // Return false if it already is in list
        return false;
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

string* Exercise::getName() {
    return name;
}

void Exercise::writeToFile(ofstream& out) {
    // Write participants to file
    writeParticipantsToFile();
    out << *name << endl;
    out << time_of_day << ' ' << date << endl;
    // Write results to file
    writeResultsToFile();
}

bool Exercise::readResultsFromFile() {
    string file_name = *name + "_results.txt";
    ifstream in = ifstream(file_name);
    // Check if file exists
    if (!in.is_open()) {
        cout << "\t\tCouldn't find results file\n";
        return false;
    }
    // Just return if results list starts with a zero (zero results)
    if (in.peek() == 0) {
        cout << "\t\tCouldn't find results list or is empty\n";
        return false;
    }
    // Amount of participants in file
    int sum;
    // The current participants result
    int res;
    // The participants id
    int id;
    in >> sum;
    for (int i = 0; i < sum; i++) {
        string data;
        in >> res;
        in >> id;
        // Ignore newline after id
        in.ignore();
        // Get the data
        getline(in, data);
        if (participants->getParticipant(id) != nullptr) {
            // Add to list but print error if already registered
            if (!results->add(new Result(res, id, data)))
            cout << "\t\tExercise: Result - Participant already exists in list.\n";
        }
        else
            cout << "\t\tExercise: Result - Participant doesn't exist.\n";
    }
    // Close file
    in.close();
    return true;
}

bool Exercise::writeResultsToFile() {
    string file_name = *name + "_results.txt";
    ofstream out = ofstream(file_name);
    // Number of results in results list
    int num = results->noOfElements();
    // Result of participant
    int r;
    // participant id of result
    int id;
    // Num element with id that we remove
    Result* res;
    // Write the amount of results to file first
    out << num << ' ';
    // Loops through all results
    for (int i = 1; i <= num; i++) {
        // Just remove the first element until list is empty
        res = (Result*)results->removeNo(i);
        r = res->getNumber();
        id = res->getParticipantID();
        // Finally we can write the result and participant id of result to file
        out << r << ' ' << id << endl;
        // Write data
        out << res->getData() << endl;
        // Put back in list
        results->add(res);
    }
    // Close file
    out.close();
    return true;
}

void Exercise::readParticipantsFromFile() {
    ifstream in = ifstream(*name + "_participants.txt");
    // Check if file exists
    if (!in.is_open()) {
        cout << "\t\tExercise: Couldn't find " << *name << "_id.txt file\n";
        return;
    }
    // Just return if participants list starts with a zero (zero participants)
    if (in.peek() == 0) {
        cout << "\t\tExercise: " << *name << "_participants.txt file is empty.\n";
        return;
    }
    // Amount of participants in file
    int sum;
    // The current participants unique id
    int n;
    in >> sum;
    for (int i = 0; i < sum; i++) {
        in >> n;
        if (participants->getParticipant(n) != nullptr) {
            // Add to list but print error if already registered
            if (!addParticipantID(n))
                cout << "\t\tExercise: Adding participant - Already exists in list.\n";
        }
        else
            cout << "\t\tExercise: Adding participant - Doesn't exist.\n";
    }
    // Close file
    in.close();
}

void Exercise::writeParticipantsToFile() {
    ofstream out = ofstream(*name + "_participants.txt");
    // participants_id list
    // Number of participants in participants_id
    int num = participants_id->noOfElements();
    // id of participant
    int id;
    // Num element with id that we remove
    NumElement* ne;
    // Write the amount of participants to file first
    out << num << ' ';
    // Loops through all participants
    for (int i = 1; i <= num; i++) {
        ne = (NumElement*)participants_id->removeNo(i);
        id = ne->getNumber();
        // Finally we can write the id number of participant to file
        out << id << ' ';
        // Put back in list
        participants_id->add(ne);
    }
    // Close file
    out.close();
}