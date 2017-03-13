#ifndef OOProject_POINTS_H_
#define OOProject_POINTS_H_
#include <string>
#include "ListTool2B.h"
#include "point.h"
using namespace std;


// Containter class for points
class Points { 

private:
    // All the points won by text (nation abbreviation) in the olympic games
    List* points;


public:
    // Add point to linked list
    void addPoint(Point);

    // Get point by its unique string @s
    Point getpoint(string s);

    // Removes point for nation with name @s
    Point removepoint(string s);
};

#endif





