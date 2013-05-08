#include "donkey.h"

Donkey::Donkey()
{
  id = "donkey";
  picture = "donkey.png";
  image.load(picture);

  rect = image.rect();
  resetState();
  
}


Donkey::~Donkey()
{
  std::cout << "Donkey deleted\n";
}

void Donkey::move( Farmer *f )
{
   randNum = std::rand()%4;
  
   if(randNum == 1)
   {
   rect.moveTo(x,y);
   }
   else
   {
      rect.moveTo(x,y+speed+2);
      //std::cout << "y is " << y << std::endl;
      y =y+speed+2;
   }
}


void Donkey::resetState()
{
  Animal::resetState();  
}

QRect Donkey::getRect()
{
  return Animal::getRect();
}

QImage & Donkey::getImage()
{
  return Animal::getImage();
}

