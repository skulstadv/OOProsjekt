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

// Initializing global variables
Participants* participants = new Participants();
Sports* sports = new Sports();
Nations* nations = new Nations();
Medals* medals = new Medals();
Points* points = new Points();

int main() {
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
    // Stores the users choice of nation
    string nation;

    // Loop until until input = 'Q'
    do {
        cout << "\n\tNations: \n\tN = New nation\n\tE = Change nation";
        cout << "\n\tA = Display data about all nations";
        cout << "\n\tT = Display this nations participants";
        cout << "\n\tS = Display all data for specified nation ";
        cout << "(except participants)\n\t";
        getChar(input);
        switch (input.at(0)) {
            // Creates a new nation. Asks user to write nation abbreviation
        case 'N':
            if (nations->addNation(new Nation(*getNationAbbreviation(2))))
                cout << "\t\tSuccess!\n";
            else
                cout << "\t\tFailure. Nation id already taken\n";
            break;
            // Edit nation
            // Removes nation with abbreviation and creates new with same
        case 'E':
            getString(nation, "Write unique abbreviation: ", 2);
            // Make sure nation exists
            if (nations->getNation(nation) != nullptr) {
                // Removes old
                delete nations->removeNation(nation);
                cout << "\t\tType new info: \n";
                // Creates new with same name
                nations->addNation(new Nation(nation));
            }
            else
                cout << "\t\tThis nation doesnt exist\n";
            break;
            // Displays all participants of a nation
        case 'T':
            nation = *getNationAbbreviation(2);
            if (nations->getNation(nation) != nullptr) {
                nations->getNation(nation)->displayParticipants(); // THIS ONE IS FUCKED, FIX
            }
            break;
            // Displays all data about all nations
        case 'A':
            nations->display();
            break;

            // Get nation by name from global nations variable
        case 'S':
            // Make sure we found a nation; not nullptr
            string* nation_abbreviation = getNationAbbreviation(2);
            nations->display((*nation_abbreviation).c_str());
            // Delete unused string so we dont get any leaks
            delete nation_abbreviation;
            break;
        }
    } while (input.at(0) != 'Q');
}

void participantSwitch() {
    // The users choice
    string input;
    string input2;
    // Stores participant id in question
    int n;
    // Participant pointer for checking if name is unique
    Participant* participant;
    Participant* participant2;

    // Loop until until input = 'Q'
    do {
        cout << "\n\tParticipants: \n\tN = New participant\n\tE = Change participant";
        cout << "\n\tA = Display data about all participants";
        cout << "\n\tS = Display all data for specified participant\n\t";
        getChar(input);

        switch (input.at(0)) {

            // Creates a new participant. Asks user to write unique participant id 
        case 'N':
            n = getInt(0, 10000, 2, "Write unique id of participant ");
            participant = new Participant(n);
            if (nations->getNation(*participant->getNationName()) == nullptr) {
                cout << "\t\tThe nation specified doesnt exist";
                break;
            }
            // Make sure its unique
            if (participants->addParticipant(participant)) {
                cout << "\t\tSuccess!\n";
                // Add to participants list of nation
                nations->getNation(*participant->getNationName())->addParticipantID(n);
            }
            else
                cout << "\t\tParticipant id not unique" << endl;
            break;

            // Edit participant
            // Removes participant with id and creates new with same id
            // **  Sloppy deluxe  **
        case 'E':
            n = getInt(0, 10000, 2, "Write unique id of participant ");
            participant = participants->getParticipant(n);
            if (participant == nullptr) {
                cout << "\t\tThis participant doesn't exist.\n";
                break;
            }
            // Create new with same id
            participant2 = new Participant(n);
            if (nations->getNation(*participant2->getNationName()) == nullptr) {
                cout << "\t\tThe nation specified doesnt exist";
                // Add old one back again
                break;
            }
            // Remove old nation association for participant 
            // ** So long, should be refactored **
            // Also; rename removeParticipant to removeParticipantID
            nations->getNation((*participant->getNationName()).c_str())->removeParticipant(n);
            // Remove the old one and delete it before adding new
            delete participants->removeParticipant(n);
            if (!participants->addParticipant(participant2))
                cout << "Participant is already in this nations list.";
            nations->getNation(*participant2->getNationName())->addParticipantID(n);
            break;

            // Displays all data about all participants
        case 'A':
            participants->display();
            break;

            // Displays all data about participant with id
        case 'S':
            cout << "\t\tChoose id -1 to search by name\n";
            n = getInt(-1, 10000, 2, "Write unique id of participant ");
            if (n > -1) {
                if (participants->getParticipant(n) != nullptr)
                    participants->getParticipant(n)->display();
                break;
            }
            // Get string to match against participants from user
            getLine(input2, "Write name to search for: ", 2);
            participants->displayParticipant(input2);
            break;
        }
    } while (input.at(0) != 'Q');
}

void sportSwitch() {
    // The users choice
    string input;
    string input2;
    // Temp sport*
    Sport* sport;

    // Loop until until input = 'Q'
    do {
        cout << "\n\tSport: \n\tN = New sport\n\tE = Change sport";
        cout << "\n\tA = Display data about all sports";
        cout << "\n\tS = Display all data for specified sport\n\t";
        getChar(input);
        switch (input.at(0)) {
            // Creates a new sport. Asks user to write sport name
        case 'N':
            getString(input, "Write name of sport : ", 2);
            if (!sports->addSport(new Sport(input)))
                cout << "\t\tSport with this name already exists";
            else
                cout << "\t\tSuccess!\n";
            break;
            // Edit sport - Change name and keep everything else
            // Removes sport with name and creates new with different name
        case 'E':
            getString(input, "Write name of sport : ", 2);
            sport = sports->removeSport(input);
            if (sport != nullptr) {
                getString(input2, "Write new name of sport : ", 2);
                sport->setSportName(input2);
                // Remove and add sport to make sure its all sorted
                sports->addSport(sport);
            }
            else
                cout << "\t\tCouldn't find sport with corresponding name\n";
            break;
            // Displays all data about all sports
        case 'A':
            sports->display();
            break;
            // Get sport by name from global sports variable
        case 'S':
            // TODO
            break;
        }
    } while (input.at(0) != 'Q');
}

void exerciseSwitch() {
    cout << "Exercise switch\n";
}
