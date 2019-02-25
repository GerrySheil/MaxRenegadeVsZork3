#include "PointOfInterest.h"

PointsOfInterest::PointsOfInterest(string inDescription)
{
    description = inDescription;
}

string PointsOfInterest::getDescription()
{
    return description + "\n";
}
void PointsOfInterest::addItem(items *iItem)
{
    itemsInPOI.push_back(*iItem);
}

/*void PointsOfInterest::addItem(weapon *wItem)
{
    itemsInPOI.push_back(*wItem);
}*/
/*void PointsOfInterest::addItem(healthItem *hItem)
{
    itemsInPOI.push_back(*hItem);
}*/
/*void PointsOfInterest::addItem(puzzleItem *pItem)
{
    itemsInPOI.push_back(*pItem);
}*/
items PointsOfInterest::takeItem()
{
    items temp = itemsInPOI[0];
    itemsInPOI.pop_back();
    return temp;
}
int PointsOfInterest::numberOfItems() {
    return itemsInPOI.size();
}

