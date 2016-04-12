//
//  Shapes.cpp
//  Dessin vectoriel
//
//  Created by samir on 12/04/16.
//  Copyright © 2016 samir. All rights reserved.
//

#include "Shapes.hpp"
#include "CImage.h"
#include "CPixel.h"
//*****************************************SHAPES*****************************************************//

//Constructor
Shapes::Shapes(int X, int Y, struct RGB color,int trans){
    
    Shapes::trans= trans;
    Shapes::X= X;
    Shapes::Y= Y;
    Shapes::color.R=color.R;
    Shapes::color.G=color.G;
    Shapes::color.B=color.B;
};

//Destructor
Shapes::~Shapes(){
    
    X = 0;
    Y = 0;
    trans=0;
    Shapes::color.R=0;
    Shapes::color.G=0;
    Shapes::color.B=0;
};

// COLOR GETTERS
int Shapes::colorR(){
    return Shapes::color.R;
};

int Shapes::colorG(){
    return Shapes::color.G;
};

int Shapes::colorB(){
    return Shapes::color.B;
};

//COORDINATES GETTERS

int Shapes::getX(){
    return Shapes::X;
};
int Shapes::getY(){
    return Shapes::Y;
};

//TRANSPARANCY GETTER

int Shapes::getTrans(){
    return Shapes::trans;
};


// COLOR SETTERS

void Shapes::colorR(int Red){
    Shapes::color.R = Red;
};

void Shapes::colorG(int Green){
    Shapes::color.G = Green;
};

void Shapes::colorB(int Blue){
    Shapes::color.B = Blue;
};


//*****************************************CIRCLE*****************************************************//

//Constructor
Circle::Circle(int X, int Y, struct RGB color, int trans, int radius):Shapes(X, Y, color, trans){
    Circle::radius = radius;
};

//Radius Getter
int Circle::getRadius(){
    return radius;
}

//Destructor
Circle::~Circle(){
    Circle::radius = 0;
};
//Drawing function
void Circle::drawshapeC(CImage *img){ // Draw a circle

    
    
};

//*****************************************RECTANLGE*****************************************************//

//Constructor
Rectangle::Rectangle(int X, int Y, struct RGB color, int trans, int length, int width):Shapes(X, Y, color, trans){
    Rectangle::Length=length;
    Rectangle::Width=width;
};

//Destructor
Rectangle::~Rectangle(){
    Rectangle::Length=0;
    Rectangle::Width=0;
};

// Length and Width Getters
int Rectangle::getLength(){
    return Length;
};

int Rectangle::getWidth(){
    return Width;
};



//Drawing function
void Rectangle::drawshapeR(CImage *img){ // Draw a Rectangle
    
    int x    = Rectangle::getX();
    int y    = Rectangle::getY();
    int lg   = Rectangle::getLength();
    int larg = Rectangle::getWidth();
    int r    = Shapes::colorR();
    int g    = Shapes::colorG();
    int b    = Shapes::colorB();
    int trans= Shapes::getTrans();
    RGB colortemp;
    colortemp.R= r;
    colortemp.G= g;
    colortemp.B= b;
    
    
    Line ln1(x,y,colortemp,trans,x+lg,y);
    ln1.drawshapeL(img);
    
    Line ln2(x,y,colortemp,trans,x,y+larg);
    ln2.drawshapeL(img);
    
    Line ln3(x,y+larg,colortemp,trans,x+lg, y+larg);
    ln3.drawshapeL(img);
    
    Line ln4(x+lg, y,colortemp,trans,x+lg,y+larg);
    ln4.drawshapeL(img);
    
    
}

//*****************************************LINE*****************************************************//

//Constructor
Line::Line(int X, int Y, struct RGB color, int trans, int X2, int Y2):Shapes(X, Y, color, trans){
    
};

//COORDINATES getter

int Line::getX2(){
    return X2;
}

int Line::getY2(){
    return Y2;
}

//Destructor
Line::~Line(){
};

//Drawing function
void Line::drawshapeL(CImage *img){ // Draw a Point
    
    int x1    = Line::getX();
    int y1    = Line::getY();
    int x2    = Line::getX2();
    int y2    = Line::getY2();
    int r     = Shapes::colorR();
    int g     = Shapes::colorG();
    int b     = Shapes::colorB();
    int trans = Shapes::getTrans();
    int x     = x1;
    int y     = y1;
    
    RGB colortemp2;
    colortemp2.R= r;
    colortemp2.G= g;
    colortemp2.B= b;
    
    Point point(x,y,colortemp2, trans); //Initialize a point
    
    double k;
    
    point.SetX(x);
    point.SetY(y);
    point.drawshapeP(img);
    
    
    for (k=0; k<1; k=k+0.001){
        x=k*x1+(1-k)*x2;
        y=k*y1+(1-k)*y2;
        
        point.SetX(x);
        point.SetY(y);
        point.drawshapeP(img);
    }
    
};

//*****************************************POINT*****************************************************//

//Constructor
Point::Point(int X, int Y, struct RGB color, int trans):Shapes(X, Y, color, trans){

};

//COORDINATES SETTERS
void Point::SetX(int x){
    Shapes::X=x;
};

void Point::SetY(int y){
    Shapes::Y=y;
};

//COORDINATES GETTERS
int Point::GetX(){
    return X;
};

int Point::GetY(){
    return Y;
};
//Destructor
Point::~Point(){
};

//Drawing function
void Point::drawshapeP(CImage *img){ // Draw a Point
    int x=Point::GetX();
    int y=Point::GetY();
    
    int r=Shapes::colorR();
    int g=Shapes::colorG();
    int b=Shapes::colorB();
    
    CPixel * p = img->getPixel(x,y);
    p->Red(r);
    p->Green(g);
    p->Blue(b);
    

};
