#ifndef DOT_H
#define DOT_H

#include "Shapes.h"

//*****************************************POINT*****************************************************//

class Dot : public Shapes{
public:
  void drawshape(CImage *img); // Draw a point
  Dot(int X, int Y, struct RGB color, int trans); // New point
  ~Dot(); // Delete
};


#endif // DOT_H
