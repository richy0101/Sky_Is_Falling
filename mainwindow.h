#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "farmer.h"
#include "animal.h"
#include "turtle.h"
#include "donkey.h"
#include "fox.h"
#include "gazelle.h"
#include "cheetah.h"
#include "rabbit.h"
#include "wolf.h"

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
#include <fstream>

using namespace std;

/**
A class to represent the main application window where the game runs

@author rhphilli
*/

class MainWindow : public QWidget 
{
  Q_OBJECT

  public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLabel* createLabel(const QString &text);
  
  /**slots to link buttons to game actions*/
  public slots:
    void startGame();
    void pauseGame();
    void quitGame();
  /**signals to change scores on the board*/
  signals:
     void scoreChanged(int s);
     void highScoreChanged(int h);
     void levelChanged(int l);
     void livesChanged(int n);
  /**Events that happen when the timer increments or a key is pressed*/
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
    /**increments every 10 milliseconds*/
    int timerCount; 
    int rand;
    bool gameOver;
    bool gameStarted;
    bool paused;
    int lives;
    int level;
    int score;
    int highScore;
    QString farmPic;
    ofstream outfile;
    ifstream infile;
    /**all falling animals that are in a vector*/
    vector<Animal*> list;
    QPalette* palette;
    Farmer *farmer;
    QGridLayout *layout;
    QPushButton *sButton,*qButton,*pButton;
    QLCDNumber *scoreNum,*highScoreNum,*levelNum,*liveNum;
};

#endif
