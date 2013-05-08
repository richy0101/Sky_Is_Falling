#ifndef DONKEY_H
#define DONKEY_H

#include <QImage>
#include <QRect>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "animal.h"
#include "farmer.h"

class Donkey : public Animal
{
   public:
    Donkey();
    ~Donkey();

  public:
    void resetState();
    void move( Farmer *f );
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
