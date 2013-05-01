#ifndef ANIMAL_H
#define ANIMAL_H

#include <QImage>
#include <QRect>
#include <QString>
#include <iostream>

class Animal
{
   public:
    Animal();
    ~Animal();

  public:
    void resetState();
    QRect getRect();
    QImage & getImage();
    virtual void move();
    void randAnimal();
    int x;
    int y;
    int random;
    int speed;
    QString id;
    

  protected:
    QImage image;
    QRect rect;
    QString picture;
    int rand;
      


};

#endif