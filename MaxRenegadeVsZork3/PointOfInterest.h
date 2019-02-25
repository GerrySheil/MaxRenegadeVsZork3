#ifndef POINTOFINTEREST
#define POINTOFINTEREST

#include <map>
#include <string>
#include <vector>
#include "items.h"
#include "weapon.h"
#include "puzzleitem.h"
#include "healthitem.h"

using namespace std;
using std::vector;


class PointsOfInterest
{
public:
    int numberOfItems();
    PointsOfInterest(string description);
    string getDescription();
    void addItem(items *iItem);
    //void addItem(weapon *wItem);
    //void addItem(healthItem *hItem);
    //void addItem(puzzleItem *pItem);
    items takeItem();


private:
    string description;
    vector <items> itemsInPOI;
};

#endif // POINTOFINTEREST

