#include "mainwindow.h"
#include <QPainter>
#include <QApplication>
#include <vector>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
  rand = 0;
  velocity = 1;
  timerCount = 0;
  lives = 3;
  score = 0;
  level = 0;
  gameOver = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  farmer = new Farmer();
  palette = new QPalette();
  	
    scoreNum = new QLCDNumber(5);
    scoreNum->setSegmentStyle(QLCDNumber::Filled);
    scoreNum->setMode(QLCDNumber::Dec);
    levelNum = new QLCDNumber(2);
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
    connect(this, SIGNAL(levelChanged(int)), levelNum, SLOT(display(int)));
    connect(this, SIGNAL(livesChanged(int)), liveNum, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(createLabel(tr("LEVEL")), 1, 0, Qt::AlignLeft);
    layout->addWidget(levelNum, 2, 0, Qt::AlignLeft);
    layout->addWidget(createLabel(tr("SCORE")), 3, 0, Qt::AlignLeft);
    layout->addWidget(scoreNum, 4, 0,Qt::AlignLeft);
    layout->addWidget(createLabel(tr("LIVES")), 5, 0, Qt::AlignLeft);
    layout->addWidget(liveNum, 6, 0, Qt::AlignLeft);
    
    layout->addWidget(sButton, 9, 0,Qt::AlignLeft);  
    layout->addWidget(pButton, 8, 0, Qt::AlignLeft);
    layout->addWidget(qButton, 7, 0, Qt::AlignLeft);
    
    //setLayout(layout);	

}

MainWindow::~MainWindow() {
 delete farmer;
 for(int i = 0;i<5;i++)
     delete list[i];
}

void MainWindow::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

  if (gameOver) {
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
  palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("farm.jpg")))));
 	setPalette(*palette); 
  painter.drawImage(farmer->getRect(),farmer->getImage());
  for(unsigned int i=0;i<list.size();i++)
     painter.drawImage(list[i]->getRect(),list[i]->getImage());

}

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
     list[i]->move();
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
        
        emit scoreChanged(score);
        delete list[i];
        list.erase(list.begin()+i);
     }
  }
  
  checkCollision();
  repaint();
  timerCount++;
 // std::cout<< "This is how many 10 milliseconds has passed: " << timerCount << std::endl;
}



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

void MainWindow::quitGame()
{
  killTimer(timerId);    
 // gameOver = TRUE;      
  gameStarted = FALSE;
  qApp->exit();
}

void MainWindow::randAnimal()
{
  if(timerCount < 100) // 150 equals 15 seconds
     rand = 0;
  else if(timerCount >= 100 && timerCount < 200) // 300 equals 30 seconds
     rand = std::rand() % 2;
  else if(timerCount >= 200 && timerCount < 300) // 450 equals 45 seconds
     rand = std::rand() % 3;
  else if(timerCount <= 300 && timerCount < 400) // 600 equals 60 seconds
     rand = std::rand() % 4;
  else if(timerCount >= 500) 
     rand = std::rand() % 5;
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
  }
}

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

