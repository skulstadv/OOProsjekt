#include "../include/main.h"
#include "../include/participants.h"
#include "../include/sports.h"
#include "../include/nation.h"
#include "../include/nations.h"
#include "../include/medals.h"
#include "../include/points.h"
#include "../include/utility.h"
#include "../include/result.h"
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
ofstream out;
ifstream in;

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

    // Read from file first
    readNationsFromFile();
    // Loop until until input = 'Q'
    do {
        cout << "\n\tNations: \n\tN = New nation\n\tE = Change nation";
        cout << "\n\tA = Display data about all nations";
        cout << "\n\tT = Display this nations participants";
        cout << "\n\tS = Display all data for specified nation ";
        cout << "(except participants)\n\t";
        getChar(input);
        switch (input.at(0)) {
        case 'N':  // Creates a new nation. Asks user to write nation abbreviation
            if (nations->addNation(new Nation(*getNationAbbreviation(2))))
                cout << "\t\tSuccess!\n";
            else
                cout << "\t\tFailure. Nation id already taken\n";
            break;
        case 'E':  // Edit nation
            // Removes nation with abbreviation and creates new with same
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
        case 'T':  // Displays all participants of a nation
            nation = *getNationAbbreviation(2);
            if (nations->getNation(nation) != nullptr) {
                nations->getNation(nation)->displayParticipants(); // THIS ONE IS FUCKED, FIX
            }
            break;
        case 'A':  // Displays all data about all nations
            readNationsFromFile();
            nations->display();
            break;

        case 'S':  // Get nation by name from global nations variable
        {
            // Make sure we found a nation; not nullptr
            string* nation_abbreviation = getNationAbbreviation(2);
            nations->display((*nation_abbreviation).c_str());
            // Delete unused string so we dont get any leaks
            delete nation_abbreviation;
            break;
        }
        }
        // Write changes to file
        writeNationsToFile();
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

        case 'N':  // Creates a new participant. Asks user to write unique participant id 

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

        case 'E':  // Edit participant
            // Removes participant with id and creates new with same id
            // **  Sloppy deluxe  **
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

        case 'A':  // Displays all data about all participants

            participants->display();
            break;

        case 'S':  // Displays all data about participant with id
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
        case 'N':
            // Creates a new sport. Asks user to write sport name
            getString(input, "Write name of sport : ", 2);
            if (!sports->addSport(new Sport(input)))
                cout << "\t\tSport with this name already exists";
            else
                cout << "\t\tSuccess!\n";
            break;
        case 'E':  // Edit sport - Change name and keep everything else
            // Removes sport with name and creates new with different name
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
        case 'A':  // Displays all data about all sports
            sports->display();
            break;
        case 'S':  // Get sport by name from global sports variable
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
            cout << "\n\tR = Modify results of exercise: " << exercise_name << "\n\t";
            getChar(input);
        }
        // Couldn't find sport. Returning to main menu.
        else {
            cout << "\tCouldn't find sport.\n";
            return;
        }

        switch (input.at(0)) {
        case 'N':  // Creates a new exercise. Asks user to write exercise name
            if (exercise == nullptr) {
                exercise = new Exercise(exercise_id);
                sport->addExercise(exercise);
            }
            else {
                cout << "\tExercise with id " << exercise_id;
                cout << " already exists.\n";
            }
            break;
        case 'E':  // Change participant 
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
        case 'F':  // TODO - There are memory-leaks here
            if (exercise != nullptr) {
                sport->removeExercise(exercise_id);
                cout << "\tExercise removed.\n";
            }
            else {
                cout << "\tExercise with id " << exercise_id;
                cout << " doesn't exist.\n";
            }
            break;
        case 'A':  // Write all data about all exercises in this sport
            sport->display();
            break;
        case 'L': // All operations regarding participants in exercise
            if (exercise != nullptr)
                exerciseSwitchParticipants(exercise);
            else {
                cout << "\tExercise with id " << exercise_id;
                cout << " doesn't exist.\n";
            }
            break;
        case 'R': // All operations regarding results of exercise
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

    // Loop until until input = 'Q'
    do {
        cout << "\n\t\tParticipants for " << exercise->getName() << ": ";
        cout << "\n\t\tS = Display participants list";
        cout << "\n\t\tN = New participants list";
        cout << "\n\t\tE = Change participants list";
        cout << "\n\t\tF = Remove participants list\n";
        getChar(input);
        switch (input.at(0)) {
        case 'S':  // Read participant list from file and display
            if (exercise->getResultsList()->noOfElements() == 0) {
                removeParticipantsList(exercise);
                readParticipantsFromFile(exercise);
            }
            else
                cout << "\t\tCan't change participants list. Results exist.\n";
            break;
        case 'N':  // New participant list from user input
            {
            newParticipantsList(exercise);
            break;
        }
        case 'E':  // Change participants list
        {
            // If resultslist doesn't exist, user can change participant list
            // Read from file - Edit - Write to file
            if (exercise->getResultsList()->noOfElements() == 0) {
                int inp = getInt(0, 1, 2, "0 = Add id\t1 = Delete id: ");
                // Get the id of the participant the user wants to add
                int n = getInt(0, 10000, 2, "Write id. 0 = Quit: ");
                // Make sure participant with id -n exists 
                if (participants->getParticipant(n) != nullptr) {
                    // Print error if already registered
                    if (!inp) {
                        if (!exercise->addParticipantID(n))
                            cout << "\t\tAlready exists in list.\n";
                    }
                    else if (!exercise->removeParticipantID(n))
                            cout << "\t\tParticipant isn't in list.\n";
                }
                else
                    cout << "\t\tParticipant doesn't exist.\n";
                    }
            else
                cout << "\t\tCan't change participants list. Result exist.\n";
            // Write our changes to file
            writeParticipantsToFile(exercise);
            break;
        }
        case 'F':  // If resultslist doesn't exist, user can remove participants list
        {
            if (exercise->getResultsList()->noOfElements() == 0) {
                if (remove("exercise_participants.txt") != 0)
                    cout << "\t\tError deleting file\n";
                else
                    cout << "\t\tDeleted exercise_participants.txt\n";
                removeParticipantsList(exercise);
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

    // Loop until input = 'Q'
    do {
        cout << "\n\t\tResults for " << exercise->getName() << ": ";
        cout << "\n\t\tS = Display results list";
        cout << "\n\t\tN = New resuls list";
        cout << "\n\t\tF = Remove results list\n";
        getChar(input);
        switch (input.at(0)) {
        case 'S':  // Read results list and display
            // Only display if it is successfully read from file
            if (readResultsFromFile(exercise))
                exercise->getResultsList()->displayList();
            break;
        case 'N': // If results are empty ask user to input a new results list
            if (exercise->getResultsList()->noOfElements() == 0) {
                newResultsList(exercise);
            }
            else
                cout << "\t\tResults list already exists.\n";
            break;
        case 'F':
        {
            if (remove("exercise_results.txt") != 0)
                cout << "\t\tError deleting file\n";
            else
                cout << "\t\tDeleted exercise_results.txt\n";
            List* lst = exercise->getResultsList();
            for (int i = 0; i < lst->noOfElements(); i++)
                lst->removeNo(1);
            cout << "\t\tResults list removed.\n";
            break;
        }
        }
    } while (input.at(0) != 'Q');
}

void readParticipantsFromFile(Exercise* exercise) {
    in = ifstream("exercise_participants.txt");
    // Check if file exists
    if (!in.is_open()) {
        cout << "\t\tCouldn't find file\n";
        return;
    }
    // Just return if participants list starts with a zero (zero participants)
    if (in.peek() == 0) {
        cout << "\t\tCouldn't find participants list or is empty.\n";
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
    // Close file
    in.close();
    exercise->displayParticipants();
}

void newParticipantsList(Exercise* exercise) {
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
    writeParticipantsToFile(exercise);
}

void writeParticipantsToFile(Exercise* exercise) {
    out = ofstream("exercise_participants.txt");
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
    cout << "Writing participants to file: " << participants_id->noOfElements() << endl;
    // Loops through all participants
    for (int i = 1; i <= num; i++) {
        // Just remove the first element until list is empty
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

void removeParticipantsList(Exercise* exercise) {
    // Loops through all participants and remove first in list until list is empty
    for (int i = 0; i < exercise->getParticipantsIDList()->noOfElements(); i++)
        exercise->getParticipantsIDList()->removeNo(1);
    if (!exercise->getParticipantsIDList()->noOfElements() == 0)
        cout << "debug1";
}

void readNationsFromFile() {
    in = ifstream("nations.txt");
    nations->readFromFile(in);
    in.close();
}

void readParticipantsFromFile() {
    in = ifstream("participants.txt");
    participants->readFromFile(in);
    in.close();
}

void readSportsFromFile() {
    in = ifstream("sports.txt");
    sports->readFromFile(in);
    in.close();
}

void writeNationsToFile() {
    out = ofstream("nations.txt");
    nations->writeToFile(out);
    out.close();
}

void writeParticipantsToFile()
{
    out = ofstream("participants.txt");
    participants->writeToFile(out);
    out.close();
}

void writeSportsToFile()
{
    out = ofstream("sports.txt");
    sports->writeToFile(out);
    out.close();
}

void newResultsList(Exercise* exercise) {
    int n;
    int res;
    List* results;
    // Keep adding results until user writes 0 to escape
    do {
        // Get the id of the result the user wants to register result for
        n = getInt(0, 10000, 2, "Write id. 0 = Quit: ");
        // The results list of this exercise
        results = exercise->getResultsList();
        bool inList = false;
        Result* result_temp;
        // Loops through results list and checks that id isnt in it already
        for (int i = 1; i <= results->noOfElements(); i++) {
            result_temp = (Result*)results->removeNo(i);
            if (result_temp->getParticipantID() == n) {
                inList = true;
                cout << "\t\tParticipant ID found in results list already. Ignoring\n";
            }
            // Adding back the elemnt we removed
            results->add(result_temp);
        }
        // Make sure results with id -n exists and that it isnt already in results list
        if (participants->getParticipant(n) != nullptr && !inList) {
            res = getInt(0, 7, 2, "Write result (valid input: [7,5,4,3,2,1,0]): ");
            // 6 is not valid input
            if (res == 6) {
                cout << "\t\tInvalid input.\n";
            }
            else {
                if (results->inList(res))
                    cout << "\t\tThis participants results already exists";
                else
                    results->add(new Result(res, n));
            }
        // Display error if result for this participant id exists already
        }
        else
            cout << "\t\tParticipant doesn't exist or is already in results list\n";
    } while (n != 0);
    writeResultsToFile(exercise);
}

void writeResultsToFile(Exercise* exercise) {
    out = ofstream("exercise_results.txt");
    // results_id list
    List* results = exercise->getResultsList();
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
    // Debug
    cout << "Writing results to file: " << num << endl;
    // Loops through all results
    for (int i = 1; i <= num; i++) {
        // Just remove the first element until list is empty
        res = (Result*)results->removeNo(i);
        r = res->getNumber();
        id = res->getParticipantID();
        // Finally we can write the result and participant id of result to file
        out << r << ' ' << id << ' ';
        // Put back in list
        results->add(res);
    }
    // Close file
    out.close();
}

bool readResultsFromFile(Exercise* exercise) {
    in = ifstream("exercise_results.txt");
    List* results = exercise->getResultsList();
    // Check if file exists
    if (!in.is_open()) {
        cout << "\t\tCouldn't find file\n";
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
        in >> res;
        in >> id;
        if (participants->getParticipant(res) != nullptr) {
            // Add to list but print error if already registered
            if (!results->add(new Result(res, id)))
                cout << "\t\tAlready exists in list.\n";
        }
        else
            cout << "\t\tParticipant doesn't exist.\n";
    }
    // Close file
    in.close();
    exercise->displayParticipants();
    return true;
}
