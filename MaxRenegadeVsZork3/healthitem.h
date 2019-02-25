#ifndef HEALTHITEM_H
#define HEALTHITEM_H

#include <string>
#include "items.h"

using namespace std;


class healthItem: public items
{
public:
    healthItem(string description, int value, QPixmap itemPictures, float effectiveness);
    float getEffectiveness();
    string healthItemInfo();
    string getDescription();
    ~healthItem();

private:
    float effectiveness;
};

#endif // HEALTHITEM_H

