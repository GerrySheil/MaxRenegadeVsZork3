#include "healthitem.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;





healthItem::healthItem(string description, int value, QPixmap itemPicture, float effectiveness) : items(description,value, itemPicture)
{
    this->effectiveness = effectiveness;
}

string healthItem::healthItemInfo()
{
    ostringstream strs1;
    ostringstream strs2;
    strs1 << value;
    string svalue = strs1.str();
    strs2 << effectiveness;
    string seffectiveness = strs2.str();
    return "The item is: " + description +  ".\n" + "It takes up " + svalue + " inventory slots.\n" + "It restores " + seffectiveness + "amount of hp.";
}
float healthItem::getEffectiveness()
{
    return effectiveness;
}
string healthItem::getDescription()
{
    return "Health Item: " + description;
}

healthItem::~healthItem()
{
    cout << "Health item destroyed" << endl;
}
