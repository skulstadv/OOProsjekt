#ifndef OOProject_MEDAL_H_
#define OOProject_MEDAL_H_
#include "utility.h"
#include "listTool2B.h"


class Medal : public TextElement {

// Gold medals won by nation with TextElement.text name
int gold;

// Silver medals won by nation with TextElement.text name
int silver;

// Bronze medals won by nation with TextElement.text name
int bronze;


public:
    Medal();

    // Constructor
    Medal(std::string s);

    // -return gold medals for nation
    int getGold();

    // -return silver medals for nation
    int getSiver();

    // -return bronze medals for nation
    int getBronze();
};

#endif



