#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <string>
#include <vector>
#include <QPixmap>
#include "pointofinterest.h"
#include "items.h"
using namespace std;
using std::vector;

class Room
{
public:
    Room(string description, QPixmap pictures);
    void setExits(Room *north, Room *east, Room *south, Room *west, Room *win);
    string longDescription();
    string startDescription();
    string getDescription();
    Room* nextRoom(string direction);
    PointsOfInterest* choosePOI(string poi);
    QPixmap getPictures();
    void setPOI(PointsOfInterest *one, PointsOfInterest *two, PointsOfInterest *three ,PointsOfInterest *four,PointsOfInterest *five);
    void addItem(items *iItem);
    int sizeOfItemsInVector();



private:
   map<string, Room*> exits;
   map<string, PointsOfInterest*> pois;
   vector<items> itemsInRoom;
   string description;
   string exitString();
   QPixmap pictures;

   };
#endif // ROOM_H
