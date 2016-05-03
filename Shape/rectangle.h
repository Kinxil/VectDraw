#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shapes.h"
#include "line.h"

//*****************************************RECTANGLE*****************************************************//

class Rectangle : public Shapes{ // The square is also include in this class
protected:
  //The minimal's coordinates Xmin and Ymin are in class Shape : X and Y
  int Length;
  int Width;

public:
  void drawshape(CImage *img);
  int getLength();
  int getWidth();
  Rectangle(int X, int Y, struct RGB color,int trans, int Length,int Width); // New rectangle
  virtual ~Rectangle(); // Delete
};

#endif // RECTANGLE_H
