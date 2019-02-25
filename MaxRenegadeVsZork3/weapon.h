#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include"items.h"

using namespace std;


class weapon: public items
{
public:
    weapon(string description, int value, QPixmap itemPicture, int power, int breakRate);
    int getPower();
    int getBreakRate();
    string weaponInfo();
    string getDescription();
    ~weapon();

private:
    int power;
    int breakRate;
};

#endif // WEAPON_H

