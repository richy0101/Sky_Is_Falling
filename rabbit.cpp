#include "rabbit.h"

Rabbit::Rabbit()
{
  id = "rabbit";
  picture = "rabbit.png";
  image.load(picture);

  rect = image.rect();
  resetState();
  
}


Rabbit::~Rabbit()
{
  std::cout << "Rabbit deleted\n";
}

void Rabbit::move( Farmer *f )
{
   randNum = std::rand()%10;
   
   if(randNum == 1)
   {
      if (x >= f->getX())
      {
      	rect.moveTo(x-10,y+(2*speed)+55);
      	y = y+ (2*speed)+55;
      	x -= 10;
   	}
   	else
   	{
   	   rect.moveTo(x+10,y+(2*speed)+55);
   	   x += 10;
   	   y = y+(2*speed)+55;
   	}
   }
   else
   {
   	rect.moveTo(x,y);
   	//std::cout << "y is " << y << std::endl;
   }
}


void Rabbit::resetState()
{
  Animal::resetState();  
}

QRect Rabbit::getRect()
{
  return Animal::getRect();
}

QImage & Rabbit::getImage()
{
  return Animal::getImage();
}

