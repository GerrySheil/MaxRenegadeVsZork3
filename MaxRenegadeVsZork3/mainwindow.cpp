//gui tutorials from Programming knowledge and Qt documentation
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string.h>
#include "Smoke.h"
#include "items.h"
#include "Room.h"
#include "healthitem.h"
#include "weapon.h"
#include "puzzleitem.h"
#include "PointOfInterest.h"
#include <QString>
#include <QPixmap>
#include <vector>
using namespace std;
vector<items> carVector;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createRooms();
    play();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showGameInfo(string gameSetUp)
{
    ui -> display -> setPixmap(currentRoom->getPictures().scaled(401,221));
    QString qWelcome = QString::fromStdString(gameSetUp);
    ui -> textEdit -> append(qWelcome);
}

void MainWindow::createRooms()
{
    Room *MainHall, *Study, *LivingRoom, *Kitchen, *Backgarden, *Bathroom, *Cellar, *HiddenRoom, *Car, *winRoom;

    PointsOfInterest *Staircase, *Painting, *Pillar, *Carpet, *HoleInWall, *Bookcase, *Drawer, *Desk, *Globe, *Shower,
                     *Toilet, *Mirror, *ShiningLight, *Doghouse;

    items *RightfrontTyre, *LeftfrontTyre, *RightbackTyre, *LeftbackTyre;

    weapon *knife, *testweapon;
    healthItem *testHealthItem;
    puzzleItem *testPuzzle;
    knife = new weapon("Combat Knife", 2, QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Knife.jpg"), 20, 20);
    testweapon = new weapon("just a tester", 2, QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg"), 1, 1);
    testHealthItem = new healthItem("another tester", 2, QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg"), 20);
    testPuzzle = new puzzleItem("final tester", 2, QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg"), "Never used");

    delete testweapon;
    delete testHealthItem;
    delete testPuzzle;

      MainHall = new Room("MainHall", QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/MainHAll.jpg"));
      Study = new Room("Study", QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Study.jpg"));
      LivingRoom = new Room("Living Room", QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Living-Room.JPG"));
      Kitchen = new Room("Kitchen", QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Kitchen.jpg"));
      Backgarden = new Room("Backgarden", QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Bakgarden.jpg"));
      Bathroom = new Room("Bathroom",QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Bathroom.jpg"));
      Cellar = new Room ("Cellar",QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Cellar.jpg"));
      HiddenRoom = new Room("HiddenRoom",QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Hidden-Room.png"));
      Car = new Room("Car", QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Car.png"));
      winRoom = new Room("winRoom", QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/EndOfGame.jpg"));


        Staircase = new PointsOfInterest("Max: Hmmm this staircase doesn't look steady. Better Leave it alone");
        Painting = new PointsOfInterest("Mary Ann: The colours are so vivid. It has held up much better than this mansion");
        Pillar = new PointsOfInterest("Max: This pillar looks like its going to collapse. Better leave it alone");
        Carpet = new PointsOfInterest("Max: There seems to be footprints leading to the bathroom");
        HoleInWall = new PointsOfInterest("Max: Looks like something burrowed in here. It's too dark to see if anything is in there though! Here goes nothing \nMax:YES! One of the tires");

        Drawer = new PointsOfInterest("Max: There's a knife in this drawer. That'll come in handy!\nMary Ann: No it won't, theres nobody else here.\nMax Renegade: Really? Oh that's anti climatic. might as well drop it then by pressing the drop button.");
        Desk = new PointsOfInterest("Max: There's a note stained with blood on the desk. It's illegible. What happened here?");
        Globe = new PointsOfInterest("Mary Ann: Wow this is a Priceless antique! Once we get the car running we could come back and...\n Max: HIYAH!!! *crash* Max: Sorry mary ann what were you saying? \n Mary Ann: Nevermind");
        Bookcase = new PointsOfInterest("Theres a note here...");

        Shower = new PointsOfInterest("Max: I think this shower would make you dirtier. what's going on in this house?");
        Toilet = new PointsOfInterest("Max: Hey one of my tires!!");
        Mirror = new PointsOfInterest("Max: Hey I look good!");

        ShiningLight = new PointsOfInterest("Max: The light is blinding, I can't see in! Is that one of my tires?");
        Doghouse = new PointsOfInterest("Max: One of my tyres. That dog is lucky he's not around.");



    RightfrontTyre = new items("a tyre", 4.0, QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/CarWheel.jpg"));
    LeftfrontTyre = new items("a tyre", 4.0, QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/CarWheel.jpg"));
    RightbackTyre = new items("a tyre", 4.0, QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/CarWheel.jpg"));
    LeftbackTyre = new items("a tyre", 4.0, QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/CarWheel.jpg"));


                            //             (N, E, S, W, win)
    MainHall -> setExits(Bathroom, Study, Car, LivingRoom, NULL);
    Study -> setExits(HiddenRoom, NULL, NULL, MainHall, NULL);
    LivingRoom -> setExits(Kitchen, MainHall, NULL, NULL, NULL);
    Kitchen -> setExits(Backgarden, NULL, LivingRoom, NULL, NULL);
    Backgarden -> setExits(NULL, NULL, Kitchen, Cellar, NULL);
    Bathroom -> setExits(NULL, NULL, MainHall, NULL, NULL);
    Cellar -> setExits(NULL, Backgarden, NULL, NULL, NULL);
    HiddenRoom -> setExits(NULL, NULL, Study, NULL, NULL);
    Car ->setExits(MainHall, NULL, NULL, NULL, winRoom);
    winRoom -> setExits(NULL, NULL, NULL, NULL, NULL);
                          //      (one, two, three, four, five)
    MainHall -> setPOI(Staircase, Painting, Pillar, Carpet, HoleInWall);
              HoleInWall->addItem(LeftfrontTyre);
    Study -> setPOI(Drawer, Desk, Globe, Bookcase, NULL);
              Drawer->addItem(knife);
              cout << knife->getDescription() << endl;
    Bathroom -> setPOI(NULL, Shower, Toilet, NULL, Mirror);
              Toilet->addItem(RightfrontTyre);
    Kitchen -> setPOI(NULL, NULL, NULL, NULL, NULL);
    Backgarden -> setPOI(NULL, NULL, Doghouse, NULL, NULL);
              Doghouse->addItem(LeftbackTyre);
    Cellar -> setPOI(NULL, NULL, NULL, NULL, NULL);
    HiddenRoom -> setPOI(ShiningLight, NULL, NULL, NULL, NULL);
                  ShiningLight->addItem(RightbackTyre);

          currentRoom = MainHall;
          currentPOI = Staircase;

}

void MainWindow::play()
{
    string description = "Mary Ann: Max! You we're out cold. A masked man jumped us while you were taking a leak. The car is outside but the wheels are gone.\n"
                         "I've tracked the wheels to this old house but the interference in here is too high. Get the wheels and let's get out of here.\n"
                         "" + currentRoom->startDescription();
    showGameInfo(description);

}


void MainWindow::on_northButton_clicked()
{
    string d = "north";
    string northInfo;
    northInfo = goRoom(d);
    showGameInfo(northInfo);
}

void MainWindow::on_eastButton_clicked()
{
    string d = "east";
    string eastInfo;
    eastInfo = goRoom(d);
    showGameInfo(eastInfo);
}

void MainWindow::on_southButon_clicked()
{
    string d = "south";
    static string southInfo;
    southInfo = goRoom(d);
    showGameInfo(southInfo);
}

void MainWindow::on_westButton_clicked()
{
    string d = "west";
    static string westInfo;
    westInfo = goRoom(d);
    showGameInfo(westInfo);
}

string MainWindow::goRoom(string direction)
{
    Room* nextRoom = currentRoom->nextRoom(direction);
    if(nextRoom == NULL)
    {
        string moveErrorMessage = "Max there's no door there. Were you not Listeming?\n";
        return moveErrorMessage;
    }
    else
    {
        currentRoom = nextRoom;
    }
    return currentRoom->longDescription();
}

string MainWindow::lookAtPOI(string poi)
{
    PointsOfInterest* choosePOI = currentRoom->choosePOI(poi);
    if(choosePOI == NULL)
    {
        string noPOIMessage = "Nothing Interesting here max. Come On! You're wasting time!!\n";
        return noPOIMessage;
    }
    currentPOI = choosePOI;
    return choosePOI->getDescription();
}

void MainWindow::on_Select1_clicked()
{
    string poi = "one";
    string poiDescription;
    poiDescription =  lookAtPOI(poi);
    showGameInfo(poiDescription);
    takeItem();
}

void MainWindow::on_Select2_clicked()
{
    string poi = "two";
    string poiDescription;
    poiDescription =  lookAtPOI(poi);
    showGameInfo(poiDescription);
    takeItem();
}

void MainWindow::on_Select3_clicked()
{
    string poi = "three";
    string poiDescription;
    poiDescription =  lookAtPOI(poi);
    showGameInfo(poiDescription);
    takeItem();
}



void MainWindow::on_Select4_clicked()
{
    string poi = "four";
    string poiDescription;
    poiDescription =  lookAtPOI(poi);
    showGameInfo(poiDescription);
    takeItem();
}

void MainWindow::on_Select5_clicked()
{
    string poi = "five";
    string poiDescription;
    poiDescription =  lookAtPOI(poi);
    showGameInfo(poiDescription);
    takeItem();
}

void MainWindow::takeItem()
{
    string itemMessage;
    if(currentPOI->numberOfItems()<1)
    {
        itemMessage = "Mary Ann: There's no items here max.\n";
    }
    else
    {
        items thisItem = currentPOI->takeItem();
        inventory.push_back(thisItem);
        itemMessage = "Mary Ann: Max we just picked up " + thisItem.getDescription();
        switch(inventory.size())
        {
        case 1:
            ui -> inventoryDisplay1 -> setPixmap(thisItem.getItemPicture().scaled(75,60));
            break;
        case 2:
            ui -> inventoryDisplay2 -> setPixmap(thisItem.getItemPicture().scaled(75,60));
            break;
        case 3:
            ui -> inventoryDisplay3 -> setPixmap(thisItem.getItemPicture().scaled(75,60));
            break;
        case 4:
            ui -> inventoryDisplay4 -> setPixmap(thisItem.getItemPicture().scaled(75,60));
            break;
        }

    }
    showGameInfo(itemMessage);
}

void MainWindow::on_useInventorySlot1_clicked()
{
    string results;
    if(currentRoom -> getDescription() == "Car")
    {
        {
        carVector.push_back(inventory.back());
        inventory.pop_back();
        switch(inventory.size())
        {
        case 0:
            ui -> inventoryDisplay1 -> setPixmap(QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg").scaled(75,60));
            break;
        case 1:
            ui -> inventoryDisplay2 -> setPixmap(QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg").scaled(75,60));
            break;
        case 2:
            ui -> inventoryDisplay3 -> setPixmap(QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg").scaled(75,60));
            break;
        case 3:
            ui -> inventoryDisplay4 -> setPixmap(QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg").scaled(75,60));
            break;
        }
        results = checkGameWin();
        }
    }
    else
    {
        results = "You cant do that max!";
    }
    showGameInfo(results);
}

string MainWindow::checkGameWin()
{
    string checkMessage;
    int won = carVector.size();
    if(won == 4)
    {
         string win = "win";
         Room* nextRoom;
         checkMessage = "Mary Ann: Finally max, we got all the tyres. Let's get to the pentagon for that meeting with the President!\n\n\n\nThanks For Playing!!\n\nGameMadeBy: Gerry Sheil\n\nId: 14172593";
         nextRoom = currentRoom->nextRoom(win);
         currentRoom = nextRoom;
    }
    else
        checkMessage = "Mary Ann: we need more tyres max. Let's keep serching";

    return checkMessage;
}

void MainWindow::on_smokeButton_clicked()
{
    Smoke smoking = Smoke("Max: Ah that's better....\nMary Ann: Max.\nMax: Yeah yeah, back to work.");
    string s = smoking.smokingDescription();
    QString qSmoke = QString::fromStdString(s);
    ui -> textEdit -> append(qSmoke);

}

void MainWindow::on_inventoryDescription_clicked()
{

    for (int j = 0; j < inventory.size(); j++)
    {
        items item = inventory[j];
        string differentDescriptions;
        differentDescriptions =  item.getDescription();
        showGameInfo(differentDescriptions);
     }
}


void MainWindow::on_drop_clicked()
{
    inventory.pop_back();
    switch(inventory.size())
    {
    case 0:
        ui->textEdit->append("Mary Ann: You dropped an item max");
        ui -> inventoryDisplay1 -> setPixmap(QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg").scaled(75,60));
        break;
    case 1:
        ui->textEdit->append("Mary Ann: You dropped an item max");
        ui -> inventoryDisplay2 -> setPixmap(QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg").scaled(75,60));
        break;
    case 2:
        ui->textEdit->append("Mary Ann: You dropped an item max");
        ui -> inventoryDisplay3 -> setPixmap(QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg").scaled(75,60));
        break;
    case 3:
        ui->textEdit->append("Mary Ann: You dropped an item max");
        ui -> inventoryDisplay4 -> setPixmap(QPixmap("C:/Users/Gerry/Documents/MaxRenegadeVsZork3/MRZPictures/Empty.jpg").scaled(75,60));
        break;
    }
}

void MainWindow::on_map_clicked()
{
    ui->textEdit->append("MAP: ");
    ui->textEdit->append("[Cellar] ---[Backgarden]");
    ui->textEdit->append("              |                                       ");
    ui->textEdit->append("          [Kitchen]       [Bathroom]   [Hidden Room]  ");
    ui->textEdit->append("              |                      |                         |   ");
    ui->textEdit->append("        [Living Room] --- [Main Hall] --- [Study]     ");
    ui->textEdit->append("                                      |                   ");
    ui->textEdit->append("                                     [Car]                 ");

}
