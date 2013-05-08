#include "animal.h"
#include <iostream>
#include <cstdlib>
#include <QRect>
/**
Constructor to load image of animal and reset its state on the board

@pre
@post
@param None
@return None
*/
Animal::Animal()
{
  randAnimal();
  image.load(picture);

  rect = image.rect();
  resetState();
}


Animal::~Animal()
{
  //std::cout << "Animal deleted\n";
}

void Animal::randAnimal()
{
  int rand = std::rand() % 5;
  switch(rand)
  {
     case 0: picture = "turtle.png";
     break;
     case 1: picture = "donkey.png";
     break;
     case 2: picture = "fox.png";
     break;
     case 3: picture = "gazelle.png";
     break;
     case 4: picture = "cheetah.png";
     break;
  }
}

void Animal::move(Farmer *f)
{
}

/**
Method to randomly place the animal at the top of the board

@pre Animal is being constructed
@post
@param None
@return None
*/
void Animal::resetState()
{
  rand = std::rand() % 1030 + 120;
  rect.moveTo(rand, 0);
  //std::cout << "X coords: " << getRect().x() << " Y coords: " << getRect().y()<< std::endl;
  x = getRect().x();
  y = getRect().y();
}

QRect Animal::getRect()
{
  return rect;
}

QImage & Animal::getImage()
{
  return image;
}
