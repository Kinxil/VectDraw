#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shapes.h"
#include "Dot.h"

//*****************************************CIRCLE*****************************************************//

class Circle : public Shapes{
protected:
  //The center's coordinates are in class Shape : X and Y
  int radius;

public:
  void drawshape(CImage *img); // Draw a circle
  int getRadius();
  Circle(int X, int Y, struct RGB color, int trans, int radius); // New circle
  ~Circle(); // Delete
};

#endif // CIRCLE_H
