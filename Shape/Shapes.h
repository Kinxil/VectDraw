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
    void setX(int x);
    void setY(int y);
    int getTrans();
    void colorR(int Red);
    void colorG(int Green);
    void colorB(int Blue);

    virtual void drawshape(CImage *img);
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
    
    void drawshape(CImage *img);
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
    
    void drawshape(CImage *img); // Draw a circle
    int getRadius();
    Circle(int X, int Y, struct RGB color, int trans, int radius); // New circle
    ~Circle(); // Delete
};


//*****************************************POINT*****************************************************//

class Dot : public Shapes{
private:
    
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

