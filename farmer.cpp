#include "farmer.h"
#include <iostream>

Farmer::Farmer()
{
  x = 0;
  y = 0;
  image.load("farmer.png");

  rect = image.rect();
  resetState();
}

Farmer::~Farmer()
{
 std::cout << ("Farmer deleted\n");
}

int Farmer::getX()
{
   return x;
}

int Farmer::getY()
{
   return y;
}

void Farmer::moveLeft(int left)
{
  if (rect.left() >= 122)
  {
    rect.moveTo(left, rect.top());
    x = rect.x();
    y = rect.y();
  }
}

void Farmer::moveRight(int right)
{
  if (rect.right() <= 1098)
  {
    rect.moveTo(right, rect.top());
    x = rect.x();
    y = rect.y();
  }
}

void Farmer::resetState()
{
  rect.moveTo(450, 500);
  x = 450;
  y = 500;
}

QRect Farmer::getRect()
{
  return rect;
}

QImage & Farmer::getImage()
{
  return image;
}
