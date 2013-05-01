#include "turtle.h"

Turtle::Turtle()
{
  id = "turtle";
  picture = "turtle.png";
  image.load(picture);

  rect = image.rect();
  resetState();
  
}


Turtle::~Turtle()
{
  std::cout << "Turtle deleted\n";
}

void Turtle::move()
{
   rect.moveTo(x,y+speed);
   //std::cout << "y is " << y << std::endl;
   y +=speed;
}


void Turtle::resetState()
{
  Animal::resetState();  
}

QRect Turtle::getRect()
{
  return Animal::getRect();
}

QImage & Turtle::getImage()
{
  return Animal::getImage();
}

