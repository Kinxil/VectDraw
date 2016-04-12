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


struct RGB {
    
    int R;
    int G;
    int B;
};

//*****************************************SHAPES*****************************************************//

class Shapes {

private:
    int X;
    int Y;
    struct RGB color;
    int trans;
    
public:
    
    virtual void drawshape();
    int colorR();
    int colorG();
    int colorB();
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
    
    virtual void drawshape();
    Rectangle(int X, int Y, struct RGB color,int trans, int Length,int Width); // New rectangle
    ~Rectangle(); // Delete
};


//*****************************************CIRCLE*****************************************************//

class Circle : public Shapes{
private:
    //The center's coordinates are in class Shape : X and Y
    int radius;
    
public:
    
    virtual void drawshape(); // Draw a circle
    Circle(int X, int Y, struct RGB color, int trans, int radius); // New circle
    ~Circle(); // Delete
};


//*****************************************POINT*****************************************************//

class Point : public Shapes{

    //The point's coordinates are in class Shape : X and Y
public:
    
    virtual void drawshape(); // Draw a point
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
    
    virtual void drawshape(); // Draw a line
    Line(int X1, int Y1, struct RGB color, int trans, int X2, int Y2);// New line
    ~Line(); // Delete
};

#endif /* Shapes_hpp */

