#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle{
public:
  Square(int X, int Y, struct RGB color, int trans, int Length);
  virtual ~Square();
};

#endif // SQUARE_H
