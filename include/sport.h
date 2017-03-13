#pragma once
#ifndef OOProject_SPORT_H_
#define OOProject_SPORT_H_
#include <string>
#include "ListTool2B.h"
#include "exercise.h"
using namespace std;


// The way the sport is scored
enum SportScore { SCORE, TIME };


 // Represents a sport with its score type
class Sport: public TextElement{

protected:
    // How this sport is scored
    SportScore score_type;

    // Linked list containing exercises done in this sport
    List* exercises;


public:
    // Create a new sport with unique name @s
    Sport(string s);

    // Add exercise to exercises list
    void addExercise(Exercise);

    // Get exercise with ID @n in exercises list
    // @return the Exercise
    Exercise getExercise(int n);

    // Remove exercise with ID @n form exercises list
    // @return the Exercise that was removed
    Exercise removeExercise(int n);

    // Display this exercises data
    void display();
};

#endif