#ifndef LINE_H
#define LINE_H

#include "Shapes.h"
#include "dot.h"

//*****************************************LINE*****************************************************//

class Line : public Shapes{
private:
  //The First's coordinates X1 and Y1 are in class Shape : X and Y
  int X2;
  int Y2;

public:
  int getX2();
  int getY2();
  void drawshape(CImage *img); // Draw a line
  Line(int X1, int Y1, struct RGB color, int trans, int X2, int Y2);// New line
  ~Line(); // Delete
};

#endif // LINE_H
