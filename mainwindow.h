#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "farmer.h"
#include "animal.h"
#include "turtle.h"
#include "donkey.h"
#include "fox.h"
#include "gazelle.h"
#include "cheetah.h"
#include <QWidget>
#include <QKeyEvent>
#include <vector>
#include <iostream>
#include <QTimer>
#include <QtGui>

#include <QFrame>
#include <QWidget>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>

using namespace std;

class MainWindow : public QWidget 
{
  Q_OBJECT

  public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLabel* createLabel(const QString &text);
    
  public slots:
    void startGame();
    void pauseGame();
    void quitGame();

  signals:
     void scoreChanged(int s);
     void levelChanged(int l);
     void livesChanged(int n);

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

    //void victory();
    void checkCollision();
    void randAnimal();
    

  private:
    int velocity;
    int timerId;
    int timerCount; //increments every 10 milliseconds
    int rand;
    bool gameOver;
    bool gameStarted;
    bool paused;
    int lives;
    int level;
    int score;
    vector<Animal*> list;
    QPalette* palette;
    Farmer *farmer;
    QGridLayout *layout;
    QPushButton *sButton,*qButton,*pButton;
    QLCDNumber *scoreNum,*levelNum,*liveNum;
};

#endif
