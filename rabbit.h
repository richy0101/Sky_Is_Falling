#ifndef RABBIT_H
#define RABBIT_H

#include <QImage>
#include <QRect>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "animal.h"
#include "farmer.h"

class Rabbit : public Animal
{
   public:
    Rabbit();
    ~Rabbit();

  public:
    void resetState();
    void move( Farmer *f );
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
