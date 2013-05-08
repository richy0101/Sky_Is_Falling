#include "mainwindow.h"
#include <QPainter>
#include <QApplication>
#include <vector>

using namespace std;

/**
Constructor that opens the files to read in, initializes the variables, and sets up the layout with widgets.

@pre inhereits QWidget's constructor
@post
@param a pointer to a widget
@return None
*/
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
  infile.open("highscore.txt", ios::in);
  if(!infile)
     highScore = 0;
  else
  {
     string tData;
     infile >> tData;
     highScore = atoi(tData.c_str());
  }
     
  rand = 0;
  velocity = 1;
  timerCount = 0;
  lives = 3;
  score = 0;
  level = 0;
  farmPic = "farm1.jpg";
  gameOver = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  farmer = new Farmer();
  palette = new QPalette();
  	
    scoreNum = new QLCDNumber(5);
    scoreNum->setSegmentStyle(QLCDNumber::Filled);
    scoreNum->setMode(QLCDNumber::Dec);
    highScoreNum = new QLCDNumber(5);
    highScoreNum->setSegmentStyle(QLCDNumber::Filled);
    highScoreNum->setMode(QLCDNumber::Dec);
    levelNum = new QLCDNumber(5);
    levelNum->setSegmentStyle(QLCDNumber::Filled);
    levelNum->setMode(QLCDNumber::Dec);
    liveNum = new QLCDNumber(5);
    liveNum->setSegmentStyle(QLCDNumber::Filled);
    
    sButton = new QPushButton("Start");
    sButton->setFocusPolicy(Qt::NoFocus);
    qButton = new QPushButton("Quit");
    qButton->setFocusPolicy(Qt::NoFocus);
    pButton = new QPushButton("Pause");
    pButton->setFocusPolicy(Qt::NoFocus);
    
    connect(sButton, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(pButton, SIGNAL(clicked()), this, SLOT(pauseGame()));
    connect(qButton , SIGNAL(clicked()), this, SLOT(quitGame()));
    
    connect(this, SIGNAL(scoreChanged(int)), scoreNum, SLOT(display(int)));
    connect(this, SIGNAL(highScoreChanged(int)), highScoreNum, SLOT(display(int)));
    connect(this, SIGNAL(levelChanged(int)), levelNum, SLOT(display(int)));
    connect(this, SIGNAL(livesChanged(int)), liveNum, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(createLabel(tr("LEVEL")), 1, 0, Qt::AlignLeft);
    layout->addWidget(levelNum, 2, 0, Qt::AlignLeft);
    layout->addWidget(createLabel(tr("SCORE")), 3, 0, Qt::AlignLeft);
    layout->addWidget(scoreNum, 4, 0,Qt::AlignLeft);
    layout->addWidget(createLabel(tr("HIGH SCORE")), 5, 0, Qt::AlignLeft);
    layout->addWidget(highScoreNum, 6, 0,Qt::AlignLeft);
    layout->addWidget(createLabel(tr("LIVES")), 7, 0, Qt::AlignLeft);
    layout->addWidget(liveNum, 8, 0, Qt::AlignLeft);
    
    layout->addWidget(sButton, 11, 0,Qt::AlignLeft);  
    layout->addWidget(pButton, 10, 0, Qt::AlignLeft);
    layout->addWidget(qButton, 9, 0, Qt::AlignLeft);
    
    //setLayout(layout);	

}

/**
Destructor that deletes the farmer and all the animals in the list

@pre farmer and >0 animals present
@post 
@param None
@return None
*/
MainWindow::~MainWindow() {
 delete farmer;
 for(unsigned int i = 0;i<list.size();i++)
     delete list[i];
}

/**
Paints the screen with the new updated event every time the timer increments 

@pre timer is on
@post
@param a pointer to a QPaintEvent
@return None
*/
void MainWindow::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  emit highScoreChanged(highScore);
  if (gameOver) {
    if(score == highScore)
    {
       outfile.open("highscore.txt");
       outfile << highScore << "\n";
       //std::cout << highScore << std::endl;
       outfile.close();
    }
  
    QFont font("Courier", 20, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Game Over");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Game Over");
    killTimer(timerId);
  }
  
  //std::cout<<farmPic.toStdString()<<std::endl;
  palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(farmPic)))));
  setPalette(*palette); 
  painter.drawImage(farmer->getRect(),farmer->getImage());
  for(unsigned int i=0;i<list.size();i++)
     painter.drawImage(list[i]->getRect(),list[i]->getImage());

}

/**
The method that changes all the moves, level, and score changes every time the timer increments.

@pre timer is on
@post
@param a pointer to a QTimerEvent
@return None
*/
void MainWindow::timerEvent(QTimerEvent *event)
{
  if(timerCount % 100 == 0)
  {
     if (velocity > 8)
     {
     	velocity +=2;
    	 level++;
    	 emit levelChanged(level);
  	}
 	 else
 	 {
 	    velocity +=1; 
 	    level++;
 	    emit levelChanged(level);
 	 }
  }
  
  if(level%3 == 1)
        farmPic = "farm1.jpg";
     if(level%3 == 2)
        farmPic = "farm2.jpg";
     if(level%3 == 0)
        farmPic = "farm3.jpg";
        
  if(timerCount%20 == 0 && velocity < 3)
  {
     randAnimal();
     /*for(unsigned int i=0;i<list.size();i++)
     {
        std::cout << "Animal " << i << "in list Y is: " << list[i]->y << std::endl;
     }*/
  }
  else if(timerCount%10 == 0 && velocity >= 3 && velocity < 6)
  {
     randAnimal();
  }
  else if(timerCount%4 == 0 && velocity >= 6 && velocity < 9)
  {
     randAnimal();
  }
  else if(timerCount%2 == 0 && velocity >= 9)
  {
     randAnimal();
  }
  for(unsigned int i=0;i<list.size();i++)
  {
     list[i]->speed = velocity;
     list[i]->move(farmer);
     if(list[i]->y >= 548)
     {
        if(list[i]->id == "turtle")
          score += 10;
        if(list[i]->id == "donkey")
          score += 20;
        if(list[i]->id == "fox")
          score += 30;
        if(list[i]->id == "gazelle")
          score += 40;
        if(list[i]->id == "cheetah")
          score += 50;
        if(list[i]->id == "rabbit")
          score += 60;
        if(list[i]->id == "wolf")
          score += 70;
        
        emit scoreChanged(score);
        
        delete list[i];
        list.erase(list.begin()+i);
        
        if(score > highScore)
    	  {
      	 highScore = score;
      	 emit scoreChanged(highScore);
        }
     
     }
  }
  
  checkCollision();
  repaint();
  timerCount++;
 // std::cout<< "This is how many 10 milliseconds has passed: " << timerCount << std::endl;
}

/**
A method that changes the x position of the farmer when a left or right arrow key is pressed.

@pre a key is pressed
@post
@param a pointer to a QKeyEvent
@return None
*/
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
       {  
         int x = farmer->getRect().x();
        for (int i=1; i<=10; i++)
          farmer->moveLeft(x--);
        break;
       }
    case Qt::Key_Right:
        { 
          int x = farmer->getRect().x();
          for (int i=1; i<=10; i++)
            farmer->moveRight(x++);
        }
        break;
  
    default:
        QWidget::keyPressEvent(event);
    }
}

/**
A method that starts the game by reseting the board

@pre game is off, timer is off
@post game is on, timer is on
@param None
@return None
*/
void MainWindow::startGame()
{ 
  if (!gameStarted) {
    farmer->resetState();

  //  gameOver = FALSE; 
 //   gameWon = FALSE; 
    gameStarted = TRUE;
    timerId = startTimer(100); 
  }
}

/**
A method that pauses the game by stopping the timer

@pre timer is on
@post timer is off
@param None
@return None
*/
void MainWindow::pauseGame()
{
  if (paused) {
    timerId = startTimer(100);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId); 
   }
}

/**
A method that quits the application

@pre
@post
@param None
@return None
*/
void MainWindow::quitGame()
{
  killTimer(timerId);    
  gameOver = TRUE;      
  gameStarted = FALSE;
  qApp->exit();
}

/**
A method that creates a random animal based on the level/time progression

@pre timer is running
@post
@param None
@return None
*/
void MainWindow::randAnimal()
{
  if(timerCount < 100) // 150 equals 15 seconds
     rand = 0;
  else if(timerCount >= 100 && timerCount < 200) // 300 equals 30 seconds
     rand = std::rand() % 2;
  else if(timerCount >= 200 && timerCount < 300) // 450 equals 45 seconds
     rand = std::rand() % 3;
  else if(timerCount >= 300 && timerCount < 400) // 600 equals 60 seconds
     rand = std::rand() % 4;
  else if(timerCount >= 400 && timerCount < 500) 
     rand = std::rand() % 5;
  else if(timerCount >= 500 && timerCount < 600) 
     rand = std::rand() % 6;
  else if(timerCount > 600) 
     rand = std::rand() % 7;
        
  switch(rand)
  {
     case 0: list.push_back(new Turtle());
     break;
     case 1: list.push_back(new Donkey());
     break;
     case 2: list.push_back(new Fox());
     break;
     case 3: list.push_back(new Gazelle());
     break;
     case 4: list.push_back(new Cheetah());
     break;
     case 5: list.push_back(new Rabbit());
     break;
     case 6: list.push_back(new Wolf());
     break;
  }
}

/**
A method that checks the collision of the farmer and animals and subtracts lives

@pre timer is on
@post 
@param None
@return None
*/
void MainWindow::checkCollision()
{
  for(unsigned int i=0;i<list.size();i++)
  {
    if (list[i]->getRect().intersects(farmer->getRect()) )
    {
       delete list[i];  
       list.erase(list.begin()+i);
       lives--;
       if(lives == 0)
          gameOver = TRUE; 
    }
  }
  emit livesChanged(lives);
}

QLabel *MainWindow::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
    return label;
}

