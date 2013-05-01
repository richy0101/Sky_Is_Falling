#ifndef CHEETAH_H
#define CHEETAH_H

#include <QImage>
#include <QRect>
#include <string>
#include <iostream>
#include <cstdlib>
#include "animal.h"

class Cheetah : public Animal
{
   public:
    Cheetah();
    ~Cheetah();

  public:
    void resetState();
    void move();
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
