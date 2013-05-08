#ifndef GAZELLE_H
#define GAZELLE_H

#include <QImage>
#include <QRect>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "animal.h"
#include "farmer.h"

class Gazelle : public Animal
{
   public:
    Gazelle();
    ~Gazelle();

  public:
    void resetState();
    void move( Farmer *f);
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
