#include "farmer.h"
#include <iostream>

Farmer::Farmer()
{
  image.load("farmer.png");

  rect = image.rect();
  resetState();
}

Farmer::~Farmer()
{
 std::cout << ("Farmer deleted\n");
}

void Farmer::moveLeft(int left)
{
  if (rect.left() >= 122)
    rect.moveTo(left, rect.top());
}

void Farmer::moveRight(int right)
{
  if (rect.right() <= 898)
    rect.moveTo(right, rect.top());
}

void Farmer::resetState()
{
  rect.moveTo(450, 500);
}

QRect Farmer::getRect()
{
  return rect;
}

QImage & Farmer::getImage()
{
  return image;
}
