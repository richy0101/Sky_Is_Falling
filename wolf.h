#ifndef WOLF_H
#define WOLF_H

#include <QImage>
#include <QRect>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "animal.h"
#include "farmer.h"

class Wolf : public Animal
{
   public:
    Wolf();
    ~Wolf();

  public:
    void resetState();
    void move( Farmer *f );
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
