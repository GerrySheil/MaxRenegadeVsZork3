#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <vector>
#include <QPixmap>

using namespace std;


class items
{
protected:
    string description;
    int value;
    QPixmap itemPicture;

public:
    items(string description, int value, QPixmap itemPicture);
    virtual ~items();
    virtual string getDescription();
    QPixmap getItemPicture();
    int getValue();
    void setDescription(string description);
    void setValue(int value);
};

#endif // ITEMS_H
