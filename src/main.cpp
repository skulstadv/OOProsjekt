#include "../include/main.h"
#include "../include/participants.h"
#include "../include/sports.h"
#include "../include/nation.h"
#include "../include/nations.h"
#include "../include/medals.h"
#include "../include/points.h"
#include "../include/utility.h"
#include <iostream>
using namespace std;


int main() {
    // Initializing global variables
    participants = new Participants();
    sports = new Sports();
    nations = new Nations();
    medals = new Medals();
    points = new Points();

    // The users choice
    string input;

    // Main program loop, ends when input = 'Q'
    do {
        // Prints help message for user 
        help();
        // Get a char for the switch
        getChar(input);
        // Main switch for choosing which object to change or create
        switch (input.at(0)) {
        case 'N':
            nationSwitch(); break;
        case 'D':
            participantSwitch(); break;
        case 'G':
            sportSwitch(); break;
        case 'O':
            exerciseSwitch(); break;
        }
    } while (input.at(0) != 'Q');
}


void help() {
    cout << "\nN = Nation\nD = Participant\nG = Sport\nO = Exercise";
    cout << "\nQ = Quit\n\n";
}

void nationSwitch() {
    // The users choice
    string input;
    // Loop until until input = 'Q'
    do {
        cout << "\n\tNations: \n\tN = New nation\n\tE = Change nation";
        cout << "\n\tA = Display all nations\n\tT = Display participants";
        cout << "\n\tS = Display all nations' data\n\t";
        getChar(input);

        // Nationswitch
        switch (input.at(0)) {
        case 'N':
            // Creates a new nation. Asks user to write nation abbreviation
            nations->addNation(new Nation(getNationAbbreviation(2))); break;
        case 'S':
            // Get nation by name from global nations variable
            string nation;
            getString(nation, "\t\tWrite name: ");
            // Make sure we found a nation; not nullptr
            if (nations->getNation(nation) != nullptr)
                nations->getNation(nation)->display();
        }


    } while (input.at(0) != 'Q');
}

void participantSwitch() {
    cout << "Participant switch\n";
}

void sportSwitch() {
    cout << "Sport switch\n";
}

void exerciseSwitch() {
    cout << "Exercise switch\n";
}
