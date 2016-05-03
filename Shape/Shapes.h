//
//  Shapes.hpp
//  Dessin vectoriel
//
//  Created by samir on 12/04/16.
//  Copyright © 2016 samir. All rights reserved.
//

#ifndef Shapes_h
#define Shapes_h

#include <stdio.h>
#include <math.h>
#include "../Image/CImage.h"
#include "../Image/CPixel.h"

typedef struct RGB {
  int R;
  int G;
  int B;
}RGB;


//*****************************************SHAPES*****************************************************//

class Shapes {

protected:
  struct RGB color;
  int trans;
  int X;
  int Y;

public:
  int colorR();
  int colorG();
  int colorB();
  int getX();
  int getY();
  RGB colorRGB();
  void setX(int x);
  void setY(int y);
  int getTrans();
  void colorR(int Red);
  void colorG(int Green);
  void colorB(int Blue);
  void colorRGB(RGB _color);

  virtual void drawshape(CImage *img);
  Shapes(int _X, int _Y, struct RGB _color,int _trans);// Set a new shape
  virtual ~Shapes();// Delete
};

#endif /* Shapes_h */

