#ifndef OOProject_SPORT_H_
#define OOProject_SPORT_H_
#include "listTool2B.h"
#include "exercise.h"


// The way the sport is scored
enum SportScore { SCORE, TIME };


 // Represents a sport with its score type
class Sport: public TextElement{

    // How this sport is scored
    SportScore score_type;

    // Linked list containing exercises done in this sport
    List* exercises;

public:
    // Constructor
    // Create a new sport with unique name -s
    Sport(std::string s);

    // Add exercise to exercises list
    void addExercise(Exercise* exercise);

    // Get exercise with ID -n in exercises list
    // -return the Exercise
    Exercise* getExercise(int n);

    // Remove exercise with ID -n form exercises list
    // -return the Exercise that was removed
    Exercise* removeExercise(int n);

    // Display this exercises data
    void display();

    // Returns unique name of sport
    std::string getName();

    // Set sport name
    void setSportName(std::string s);
};

#endif