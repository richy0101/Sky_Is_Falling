#include "gazelle.h"

Gazelle::Gazelle()
{
  id = "gazelle";
  picture = "gazelle.png";
  image.load(picture);

  rect = image.rect();
  resetState();
  
}


Gazelle::~Gazelle()
{
  std::cout << "Gazelle deleted\n";
}

void Gazelle::move()
{
   rect.moveTo(x,y+(2*speed-4));
   //std::cout << "y is " << y << std::endl;
   y = y + 2*speed-4;
}


void Gazelle::resetState()
{
  Animal::resetState();  
}

QRect Gazelle::getRect()
{
  return Animal::getRect();
}

QImage & Gazelle::getImage()
{
  return Animal::getImage();
}

