#ifndef OOProject_POINT_H_
#define OOProject_POINT_H_
#include "listTool2B.h"
#include <string>


// Represents the point for a given nation
class Point : public TextElement {

private:
    // Total points won by nation TextElement.text
    int num_points;

public:
    // Constructor
    Point(std::string s);

    // return points of this nation
    int getPoints();
};

#endif


