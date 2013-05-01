#include "fox.h"

Fox::Fox()
{
  id = "fox";
  picture = "fox.png";
  image.load(picture);

  rect = image.rect();
  resetState();
  
}


Fox::~Fox()
{
  std::cout << "Fox deleted\n";
}

void Fox::move()
{
   randNum = std::rand()%5;
  
   if(randNum == 1)
   {
      rect.moveTo(x,y-10);
      y -=10;
   }
   else
   {
   	rect.moveTo(x,y+speed+4);
   	//std::cout << "y is " << y << std::endl;
   	y =y+speed+4;
   }
}


void Fox::resetState()
{
  Animal::resetState();  
}

QRect Fox::getRect()
{
  return Animal::getRect();
}

QImage & Fox::getImage()
{
  return Animal::getImage();
}

