#include "../include/main.h"
#include "../include/participants.h"
#include "../include/sports.h"
#include "../include/nation.h"
#include "../include/nations.h"
#include "../include/medals.h"
#include "../include/points.h"
#include "../include/utility.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
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
            n = getInt(1, 10000, 2, "Write unique id of participant ");
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
            n = getInt(1, 10000, 2, "Write unique id of participant ");
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
            cout << "\t\tChoose id 0 to search by name\n";
            n = getInt(1, 10000, 2, "Write unique id of participant ");
            if (n > 0) {
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
            // Get name of sport to be displayed
            getString(input, "Write name of sport : ", 2);
            sport = sports->getSport(input);
            // Make sure sport exists
            if (sport != nullptr) {
                sport->display();
            }
            else
                cout << "\t\tCouldn't find sport with corresponding name\n";
            break;
        }
    } while (input.at(0) != 'Q');
}

void exerciseSwitch() {
    // The users choice
    string input;
    // unique exercise id
    int exercise_id;
    // Temp exercise*
    Exercise* exercise = nullptr;
    // The sport* this exercise belongs to
    Sport* sport;

    // Loop until until input = 'Q'
    do {
        // Get sport and check that it exists
        getString(input, "Write name of sport: ", 1);
        sport = sports->getSport(input);

        if (sport != nullptr) {
            exercise_id = getInt(1, 1000, 1, "Found sport. Write exercise id: ");
            exercise = sport->getExercise(exercise_id);
            string exercise_name = "nullptr";
            if (exercise != nullptr)
                exercise_name = exercise->getName();
            cout << "\n\tExercise: \n\tN = New exercise\n\tE = Change exercise";
            cout << "\n\tF = Remove an exercise";
            cout << "\n\tA = Display all data for all exercises in specified sport";
            cout << "\n\tL = Modify participants of exercise: " << exercise_name;
            cout << "\n\tR = Modify results of exercise: " << exercise_name << "\n";
            getChar(input);
        }
        // Couldn't find sport. Returning to main menu.
        else {
            cout << "\tCouldn't find sport.\n";
            return;
        }

        switch (input.at(0)) {
            // Creates a new exercise. Asks user to write exercise name
        case 'N':
            if (exercise == nullptr) {
                exercise = new Exercise(exercise_id);
                sport->addExercise(exercise);
            }
            else {
                cout << "\tExercise with id " << exercise_id;
                cout << " already exists.\n";
            }
            break;
        case 'E':
            if (exercise != nullptr) {
                exercise->setName();
                exercise->setDate();
                exercise->setTime();
                cout << "\tExercise changed.\n";
            }
            else {
                cout << "\tExercise with id " << exercise_id;
                cout << " doesn't exist.\n";
            }
            break;
        case 'F':
            // TODO - There are memory-leaks here
            if (exercise != nullptr) {
                sport->removeExercise(exercise_id);
                cout << "\tExercise removed.\n";
            }
            else {
                cout << "\tExercise with id " << exercise_id;
                cout << " doesn't exist.\n";
            }
            break;
        case 'A':
            sport->display();
            break;
        case 'L':
            if (exercise != nullptr)
                exerciseSwitchParticipants(exercise);
            else {
                cout << "\tExercise with id " << exercise_id;
                cout << " doesn't exist.\n";
            }
            break;
        case 'R':
            if (exercise != nullptr)
                exerciseSwitchResults(exercise);
            else {
                cout << "\tExercise with id " << exercise_id;
                cout << " doesn't exist.\n";
            }
            break;
        }
    } while (input.at(0) != 'Q');
}

void exerciseSwitchParticipants(Exercise* exercise) {
    // The users choice
    string input;


    // Outputfilestream
    ofstream out;
    // Loop until until input = 'Q'
    do {
        cout << "\n\t\tParticipants for " << exercise->getName() << ": ";
        cout << "\n\t\tS = Display participants list";
        cout << "\n\t\tN = New participants list";
        cout << "\n\t\tE = Change participants list";
        cout << "\n\t\tF = Remove participants list\n";
        getChar(input);
        switch (input.at(0)) {
            // Read participant list from file and display
        case 'S':
            readParticipantsFromFile(exercise);
            break;
            // New participant list from user input
        case 'N': {
            // TODO - Move to its own function; writeParticipantsToFile(Excercise* exercise)
            int n;
            // Keep adding participants until user writes 0 to escape
            do {
                // Get the id of the participant the user wants to add
                n = getInt(0, 10000, 2, "Write id. 0 = Quit: ");
                // Make sure participant with id -n exists and that it isnt already in participants list
                if (participants->getParticipant(n) != nullptr) {
                    // Print error if already registered
                    if (!exercise->addParticipantID(n))
                        cout << "\t\tAlready exists in list.\n";
                }
                else
                    cout << "\t\tParticipant doesn't exist.\n";
            } while (n != 0);
            out = ofstream("participants.txt");
            // participants_id list
            List* participants_id = exercise->getParticipantsIDList();
            // Number of participants in participants_id
            int num = participants_id->noOfElements();
            // id of participant
            int id;
            // Num element with id that we remove
            NumElement* ne;
            // Write the amount of participants to file first
            out << num << ' ';
            // Debug
            cout << "Writing to file: " << participants_id->noOfElements() << endl;
            // Loops through all participants
            for (int i = 1; i <= num; i++) {
                participants_id = exercise->getParticipantsIDList();
                // Just remove the first element until list is empty
                ne = (NumElement*)participants_id->removeNo(1);
                id = ne->getNumber();
                // Finally we can write the id number of participant to file
                out << id << ' ';
            }
            out.close();
            break;
        }
              // If resultslist doesn't exist, user can change participant list
              // Read from file - Edit - Write to file
        case 'E':
            // TODO
            break;
            // If resultslist doesn't exist, user can remove participants list
        case 'F': {
            if (exercise->getResultsList()->noOfElements() == 0) {
                List* lst = exercise->getParticipantsIDList();
                for (int i = 0; i < lst->noOfElements(); i++)
                    lst->removeNo(1);
                cout << "\t\tParticipants list removed.\n";
            }
            else
                cout << "\t\tError. Results already exist. Not doing anything\n";
            break;
        }
        }
    } while (input.at(0) != 'Q');
}

void exerciseSwitchResults(Exercise* exercise) {
    // The users choice
    string input;

    // Loop until until input = 'Q'
    do {
        getChar(input);
        switch (input.at(0)) {
        case 'S':
            // TODO
            break;
        case 'N':
            // TODO
            break;
        case 'F':
            // TODO
            break;
        }
    } while (input.at(0) != 'Q');
}

void readParticipantsFromFile(Exercise* exercise) {
    // Inputfilestream
    ifstream in;
    in = ifstream("participants.txt");
    // Check if file exists
    if (!in.is_open())
        cout << "\t\tCouldn't find file\n";
    // Just return if participants list starts with a zero (zero participants)
    if (in.peek() == 0) {
        cout << "\t\tCouldn't find participants list.\n";
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
            if (!exercise->addParticipantID(n))
                cout << "\t\tAlready exists in list.\n";
        }
        else
            cout << "\t\tParticipant doesn't exist.\n";
    }
    exercise->displayParticipants();
}