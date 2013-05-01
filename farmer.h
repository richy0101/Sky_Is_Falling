#ifndef FARMER_H
#define FARMER_H

#include <QImage>
#include <QRect>

class Farmer
{

  public:
    Farmer();
    ~Farmer();

  public:
    void resetState();
    void moveLeft(int left);
    void moveRight(int right);
    QRect getRect();
    QImage & getImage();

  private:
    QImage image;
    QRect rect;

};

#endif
