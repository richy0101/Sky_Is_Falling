#include "mainwindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPushButton>

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 1100;
  int HEIGHT = 548;
  

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();
 
  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}



int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  
    
  MainWindow *window = new MainWindow();
  
  window->setWindowTitle("The Sky Is Falling");
  //window->setFixedSize(548,900);
  center(*window);
  window->show();

  return app.exec();
}
