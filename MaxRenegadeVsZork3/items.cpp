#include "items.h"
#include <string>
#include <iostream>
#include <QPixmap>

using namespace std;

items::items(string description, int value, QPixmap itemPicture)
{
    this->description = description;
    this->value = value;
    this->itemPicture = itemPicture;
}
string items::getDescription()
{
    return "Generic Item: " + description;
}
int items::getValue()
{
    return value;
}
void items::setDescription(string description)
{
    this->description = description;
}
void items::setValue(int value)
{
    this->value = value;
}
QPixmap items::getItemPicture()
{
    return itemPicture;
}

items::~items()
{
    cout << "Generic Item destroyed" << endl;
}
