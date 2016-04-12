//
//  Shapes.hpp
//  Dessin vectoriel
//
//  Created by samir on 12/04/16.
//  Copyright © 2016 samir. All rights reserved.
//

#ifndef Shapes_hpp
#define Shapes_hpp

#include <stdio.h>
#include "CImage.h"
#include "CPixel.h"

struct RGB {
    
    int R;
    int G;
    int B;
};


//*****************************************SHAPES*****************************************************//

class Shapes {

private:
    
    struct RGB color;
    int trans;
    
public:
    int X;
    int Y;
    // virtual void drawshape();
    int colorR();
    int colorG();
    int colorB();
    int getX();
    int getY();
    int getTrans();
    void colorR(int Red);
    void colorG(int Green);
    void colorB(int Blue);
    Shapes(int X, int Y, struct RGB color,int trans);// Set a new shape
    ~Shapes();// Delete
};

//*****************************************RECTANGLE*****************************************************//

class Rectangle : public Shapes{ // The square is also include in this class
private:
    //The minimal's coordinates Xmin and Ymin are in class Shape : X and Y
    int Length;
    int Width;

public:
    
    void drawshapeR(CImage *img);
    int getLength();
    int getWidth();
    Rectangle(int X, int Y, struct RGB color,int trans, int Length,int Width); // New rectangle
    ~Rectangle(); // Delete
};


//*****************************************CIRCLE*****************************************************//

class Circle : public Shapes{
private:
    //The center's coordinates are in class Shape : X and Y
    int radius;
    
public:
    
    void drawshapeC(CImage *img); // Draw a circle
    int getRadius();
    Circle(int X, int Y, struct RGB color, int trans, int radius); // New circle
    ~Circle(); // Delete
};


//*****************************************POINT*****************************************************//

class Point : public Shapes{
private:
    int X;
    int Y;
    
public:
    int GetX();
    int GetY();
    void SetX(int x);
    void SetY(int y);
    void drawshapeP(CImage *img); // Draw a point
    Point(int X, int Y, struct RGB color, int trans); // New point
    ~Point(); // Delete
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
    void drawshapeL(CImage *img); // Draw a line
    Line(int X1, int Y1, struct RGB color, int trans, int X2, int Y2);// New line
    ~Line(); // Delete
};

#endif /* Shapes_hpp */

