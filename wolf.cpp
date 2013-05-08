#include "wolf.h"

Wolf::Wolf()
{
  id = "wolf";
  picture = "wolf.png";
  image.load(picture);

  rect = image.rect();
  resetState();
  
}


Wolf::~Wolf()
{
  std::cout << "Wolf deleted\n";
}

void Wolf::move( Farmer *f )
{
   randNum = std::rand()%10;
  
   if(randNum == 1)
   {
      rect.moveTo(x,y+(2*speed)+55);
      y = y+ (2*speed)+55;
   }
   else if( randNum == 5)
   {
      rect.moveTo(x+30,y);
      x = x + 30;
   }
   else if( randNum == 7)
   {
      rect.moveTo(x-30,y);
      x = x-30;
   }
   else
   {
   	rect.moveTo(x,y);
   	//std::cout << "y is " << y << std::endl;
   }
}


void Wolf::resetState()
{
  Animal::resetState();  
}

QRect Wolf::getRect()
{
  return Animal::getRect();
}

QImage & Wolf::getImage()
{
  return Animal::getImage();
}

