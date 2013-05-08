#include "farmer.h"
#include <iostream>

/**
Constructor to load the farmers image and reset its state

@pre Farmer is being constructed
@post
@param None
@return None
*/
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

/**
Method to move farmer left

@pre 
@post
@param an integer that is the x coordinate of the farmer
@return None
*/
void Farmer::moveLeft(int left)
{
  if (rect.left() >= 122)
  {
    rect.moveTo(left, rect.top());
    x = rect.x();
    y = rect.y();
  }
}

/**
Method to move farmer right

@pre
@post
@param an integer that is the x coordinate of the farmer
@return None
*/
void Farmer::moveRight(int right)
{
  if (rect.right() <= 1098)
  {
    rect.moveTo(right, rect.top());
    x = rect.x();
    y = rect.y();
  }
}

/**
A method that places the farmer in the middle of the board on the bottom of the screen when it is constructed.

@pre Farmer is being constructed
@post
@param None
@return None
*/
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
