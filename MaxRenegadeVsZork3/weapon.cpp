#include <QPixmap>
#include "weapon.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

weapon::weapon(string description, int value, QPixmap itemPicture, int power, int breakRate) : items(description, value, itemPicture)
{
    this->power = power;
    this->breakRate = breakRate;
}
string weapon::weaponInfo()
{
    std::ostringstream strs1;
    std::ostringstream strs2;
    strs1 << value;
    std::string svalue = strs1.str();
    strs2 << power;
    std::string spower = strs2.str();
    return "The item is: " + description +  ".\n" + "It takes up " + svalue + " inventory slots.\n" + "It does " + spower + " damage.";
}
int weapon::getBreakRate()
{
    return breakRate;
}
int weapon::getPower()
{
    return power;
}

string weapon::getDescription()
{
    return "Weapon: " + description;
}

weapon::~weapon()
{
    cout << "Weapon destroyed." << endl;
}
