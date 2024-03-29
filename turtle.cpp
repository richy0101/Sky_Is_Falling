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

/**
move method specific for turtle that makes the turtle go in a steady pace in the direction of the farmer 

@pre Turtle is on the board
@post 
@param a pointer to the Farmer on the board
@return None
*/
void Turtle::move( Farmer *f )
{
   if (x >= f->getX())
   {
      rect.moveTo(x-1,y+speed);
      x -= 1;
      y += speed;
   }
   else
   {
      rect.moveTo(x+1,y+speed);
      x += 1;
      y += speed;
   }
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

