#ifndef DISC_H
#define DISC_H

#include "circle.h"


class Disc : public Circle{
public:
  void drawshape(CImage *img); // Draw a circle
  Disc(int X, int Y, struct RGB color, int trans, int radius); // New full circle
  ~Disc();
};


#endif // DISC_H
