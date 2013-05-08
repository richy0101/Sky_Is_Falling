#ifndef TURTLE_H
#define TURTLE_H

#include <QImage>
#include <QRect>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "animal.h"
#include "farmer.h"


class Turtle : public Animal
{
  public:
    Turtle();
    ~Turtle();

  public:
    void resetState();
    void move( Farmer *f );
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
