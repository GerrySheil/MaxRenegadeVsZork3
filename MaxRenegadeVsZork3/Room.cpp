#include "Room.h"
#include <ostream>
#include <sstream>
#include <QPixmap>

using namespace std;

Room::Room(string description, QPixmap pictures)
{
    this ->description = description;
    this->pictures = pictures;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west, Room *win) {
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
    if (win !=NULL)
        exits["win"] = win;

}
void Room::setPOI(PointsOfInterest *one, PointsOfInterest *two, PointsOfInterest *three, PointsOfInterest *four, PointsOfInterest *five)
{
    if (one != NULL)
        pois["one"] = one;
    if (two != NULL)
        pois["two"] = two;
    if (three != NULL)
        pois["three"] = three;
    if (four != NULL)
        pois["four"] = four;
    if (five != NULL)
        pois["five"] = five;
}

string Room::startDescription()
{
    return "Mary Ann: We're in the " + description + ". " + exitString() + "\n" + "Mary Ann: Use the numbered buttons to look around the room.";
}

string Room::longDescription()
{
    return "Mary Ann: Max! We're in the " + description + ".\n" + exitString() + "\n" + "Mary Ann: Use the numbered buttons to look around the room.";
}

string Room::exitString()
{
    string returnString = "We can get out from the following exits = ";
    for (map<string, Room*> ::iterator i = exits.begin(); i != exits.end(); i++)

        returnString += " " + i->first;
    return returnString;
}


Room* Room::nextRoom(string direction)
{
    map<string, Room*>::iterator next = exits.find(direction);
    if(next == exits.end())
        return NULL;
        return next->second;
}
PointsOfInterest* Room::choosePOI(string poi)
{
    map<string, PointsOfInterest*>::iterator next = pois.find(poi);
    if(next == pois.end())
            return NULL;
    else
        return next -> second;
}

QPixmap Room::getPictures()
{
    return pictures;
}
void Room::addItem(items *iItem)
{
    itemsInRoom.push_back(*iItem);
}
int Room::sizeOfItemsInVector()
{
    if(itemsInRoom.size()<3)
    {
        return 1;
    }
    else return 0;
}
string Room::getDescription()
{
    return description;
}
