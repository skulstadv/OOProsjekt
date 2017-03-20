#ifndef OOProject_MAIN_H_
#define OOProject_MAIN_H_
#include "../include/participants.h"
#include "../include/sports.h"
#include "../include/nations.h"
#include "../include/medals.h"
#include "../include/points.h"

// Global variables
extern Participants* participants;
extern Sports* sports;
extern Nations* nations;
extern Medals* medals;
extern Points* points;


// Prints helpmessage for main switch
void help();

// Switch for editing/creating nations
void nationSwitch();

// Switch for editing/creating sports
void participantSwitch();

// Switch for editing/creating participants
void sportSwitch();

// Switch for editing/creating exercises
void exerciseSwitch();

// Switch for editing/creating participant lists
void exerciseSwitchParticipants(Exercise* exercise);

// Switch for editing/creating results lists
void exerciseSwitchResults(Exercise* exercise);

// Creates a new participants list if no list exists
// Writes to file after creating
void newParticipantsList(Exercise* exercise);

// Creates a new results list if no list exists
void newResultsList(Exercise* exercise, int result_data_type);

// Remove participantslist
void removeParticipantsList(Exercise* exercise);

// Read nations from file
void readNationsFromFile();

// Read participants from file  
void readParticipantsFromFile();

// Read sports from file  
void readSportsFromFile();

// Write nations from file
void writeNationsToFile();

// Write participants to file
void writeParticipantsToFile();

// Write sports from file  
void writeSportsToFile();

// Display all medals of each nation
void displayMedals();

// Display all points of each nation
void displayPoints();
#endif