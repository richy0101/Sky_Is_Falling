#ifndef FOX_H
#define FOX_H

#include <QImage>
#include <QRect>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "animal.h"
#include "farmer.h"

class Fox : public Animal
{
   public:
    Fox();
    ~Fox();

  public:
    void resetState();
    void move( Farmer *f );
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
