#ifndef TURTLE_H
#define TURTLE_H

#include <QImage>
#include <QRect>
#include <string>
#include <iostream>
#include <cstdlib>
#include "animal.h"

class Turtle : public Animal
{
  public:
    Turtle();
    ~Turtle();

  public:
    void resetState();
    void move();
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
