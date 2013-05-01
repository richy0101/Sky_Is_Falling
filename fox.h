#ifndef FOX_H
#define FOX_H

#include <QImage>
#include <QRect>
#include <string>
#include <iostream>
#include <cstdlib>
#include "animal.h"

class Fox : public Animal
{
   public:
    Fox();
    ~Fox();

  public:
    void resetState();
    void move();
    QRect getRect();
    QImage & getImage();
    
  private:
      


};
#endif
