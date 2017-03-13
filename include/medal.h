#pragma once
#ifndef OOProject_MEDAL_H_
#define OOProject_MEDAL_H_
using namespace std;


class Medal {

private:
    // Gold medals won by nation with TextElement.text name
    int gold;

    // Silver medals won by nation with TextElement.text name
    int silver;
    
    // Bronze medals won by nation with TextElement.text name
    int bronze;


public:
    int getGold() {
        return gold;
    }
    int getSilver() {
        return silver;
    }
    int getBronze() {
        return bronze;
    }
};

#endif



