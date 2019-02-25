#include "puzzleitem.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
puzzleItem::puzzleItem(string description, int value, QPixmap itemPicture, string whereToUse) : items(description, value, itemPicture)
{
    this->whereToUse = whereToUse;
}

string puzzleItem::puzzleItemInfo()
{
    std::ostringstream strs1;
    strs1 << value;
    std::string svalue = strs1.str();
    return "The item is: " + description +  ".\n" + "It takes up " + svalue + " inventory slots.\n" + "It needs to be used in the " + whereToUse + ".\n";
}

string puzzleItem::getWhereToUse()
{
    return whereToUse;
}

string puzzleItem::getDescription()
{
    return "Puzzle Item: " + description;
}

puzzleItem::~puzzleItem()
{
    cout << "Puzzle Item destroyed" << endl;
}
