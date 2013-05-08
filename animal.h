#ifndef ANIMAL_H
#define ANIMAL_H

#include <QImage>
#include <QRect>
#include <QString>
#include <iostream>
#include <stdlib.h>
#include "farmer.h"

/**
A superclass to represent an animal that has basic methods. To be inherited by many specific animals.

@author rhphilli
*/

class Animal
{
   public:
    Animal();
    ~Animal();

  public:
    void resetState();
    QRect getRect();
    QImage & getImage();
    /**a pure virtual move method to be implemented by inherited classes*/
    virtual void move( Farmer *f);
    void randAnimal();
    int x;
    int y;
    int randNum;
    int speed;
    QString id;
    

  protected:
    QImage image;
    QRect rect;
    QString picture;
    int rand;
      


};

#endif
