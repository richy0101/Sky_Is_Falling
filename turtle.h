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

/**
A class that represents a turtle that inherits the basic member functions of the class Animal. It implements the move function.

@author rhphilli
*/

class Turtle : public Animal
{
  public:
    Turtle();
    ~Turtle();

  public:
    void resetState();
    /**a method that allows the turtle to move in the direction of where the farmer is*/
    void move( Farmer *f );
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
