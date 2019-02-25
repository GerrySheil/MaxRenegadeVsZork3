#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<string.h>
#include <QMainWindow>
#include"Room.h"
#include "items.h"
#include <vector>
using namespace std;
using std::vector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void play();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showGameInfo(string gameSetUp);

    void on_northButton_clicked();

    void on_eastButton_clicked();

    void on_southButon_clicked();

    void on_westButton_clicked();

    void on_Select1_clicked();

    void on_Select2_clicked();

    void on_Select3_clicked();


    void on_Select4_clicked();

    void on_Select5_clicked();

    void on_useInventorySlot1_clicked();

    void on_smokeButton_clicked();

    void on_inventoryDescription_clicked();

    void on_drop_clicked();

    void on_map_clicked();

private:
    void createRooms();
    void printWelcome();
    void printHelp();
    string goRoom(string direction);
    string lookAtPOI(string poi);
    vector <items> inventory;
    void createItems();
    void displayItems();
    void takeItem();
    PointsOfInterest *currentPOI;
    Room *currentRoom;
    Ui::MainWindow *ui;
    string checkGameWin();

};

#endif // MAINWINDOW_H
