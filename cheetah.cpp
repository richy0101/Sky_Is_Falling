#include "cheetah.h"

Cheetah::Cheetah()
{
  id = "cheetah";
  picture = "cheetah.png";
  image.load(picture);

  rect = image.rect();
  resetState();
  
}


Cheetah::~Cheetah()
{
  std::cout << "Cheetah deleted\n";
}

void Cheetah::move( Farmer *f )
{
   randNum = std::rand()%5;
  
   if(randNum == 1)
   {
      rect.moveTo(x,y+(2*speed)+15);
      y = y+ (2*speed)+15;
   }
   else
   {
   	rect.moveTo(x,y+(2*speed));
   	//std::cout << "y is " << y << std::endl;
   	y = y+ 2*speed;
   }
}


void Cheetah::resetState()
{
  Animal::resetState();  
}

QRect Cheetah::getRect()
{
  return Animal::getRect();
}

QImage & Cheetah::getImage()
{
  return Animal::getImage();
}

