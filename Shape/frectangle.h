#ifndef FRECTANGLE_H
#define FRECTANGLE_H

#include "rectangle.h"
#include "dot.h"

class FRectangle : public Rectangle{
public:
  void drawshape(CImage *img);
  FRectangle(int X, int Y, struct RGB color,int trans, int Length,int Width);
  ~FRectangle();
};

#endif // FRECTANGLE_H
