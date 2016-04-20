////////////////////////////////////
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

class FRectangle : public Rectangle{
public:
  void drawshape(CImage *img);
  FRectangle(int X, int Y, struct RGB color,int trans, int Length,int Width);
  ~FRectangle();
};

class Square : public Rectangle{
public:
  Square(int X, int Y, struct RGB color, int trans, int Length);
  virtual ~Square();
};

/*Note I have an interesting yet weird behavior here :
FSquare derivates from FRectangle and I expected it to use
FRectangle::drawshape() but it seems that FSquare is currently
using Rectangle::drawshape()
Is derived class using the highest parent non virtual function ?
If yes how make it using direct parent version ?
 */
class FSquare : public FRectangle{
public:
  FSquare(int X, int Y, struct RGB color, int trans, int Length);
  ~FSquare();
};

//*****************************************Polygon*****************************************************//

class RegularPolygon : public Shapes{ // As its name alreday mentionned it, only regular polygons are included in this class (Triangles included)
private:
    //The minimal's coordinates Xmin and Ymin are in class Shape : X and Y
    int R; // Defines the size of the polygon
    int N; // Defines the number of Vertices

public:

    void drawshape(CImage *img);
    int getR();
    int getN();
    RegularPolygon(int X, int Y, struct RGB color, int trans, int R, int N); // New polygon
    ~RegularPolygon(); // Delete
};

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

class Disc : public Circle{
public:
  void drawshape(CImage *img); // Draw a circle
  Disc(int X, int Y, struct RGB color, int trans, int radius); // New full circle
  ~Disc();
};

//*****************************************POINT*****************************************************//

class Dot : public Shapes{
public:
  void drawshape(CImage *img); // Draw a point
  Dot(int X, int Y, struct RGB color, int trans); // New point
  ~Dot(); // Delete
};



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

#endif /* Shapes_h */