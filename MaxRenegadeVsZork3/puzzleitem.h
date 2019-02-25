
#ifndef PUZZLEITEM_H
#define PUZZLEITEM_H

#include <string>
#include "items.h"

using namespace std;

class puzzleItem: public items
{
public:
    puzzleItem(string description, int value, QPixmap itemPicture, string whereToUse);
    string getWhereToUse();
    string puzzleItemInfo();
    string getDescription();
    ~puzzleItem();

private:
    string whereToUse;
};

#endif // PUZZLEITEM_H
