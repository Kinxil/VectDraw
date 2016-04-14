//
//  Shapes.cpp
//  Dessin vectoriel
//
//  Created by samir on 12/04/16.
//  Copyright © 2016 samir. All rights reserved.
//

#include "Shapes.h"
#include "../Format/CBitmap.h"

//*****************************************SHAPES*****************************************************//

//Constructor
Shapes::Shapes(int X, int Y, struct RGB color,int trans){
    
    Shapes::trans= trans;
    Shapes::X= X;
    Shapes::Y= Y;
    Shapes::color.R=color.R;
    Shapes::color.G=color.G;
    Shapes::color.B=color.B;
}

//Destructor
Shapes::~Shapes(){
    
    X = 0;
    Y = 0;
    trans=0;
    Shapes::color.R=0;
    Shapes::color.G=0;
    Shapes::color.B=0;
}

// COLOR GETTERS
int Shapes::colorR(){
    return Shapes::color.R;
}

int Shapes::colorG(){
    return Shapes::color.G;
}

int Shapes::colorB(){
    return Shapes::color.B;
}

//COORDINATES GETTERS

int Shapes::getX(){
    return X;
}
int Shapes::getY(){
    return Y;
}


//COORDINATES SETTERS
void Shapes::setX(int x){
    X=x;
}

void Shapes::setY(int y){
    Y=y;
}


//TRANSPARANCY GETTER

int Shapes::getTrans(){
    return Shapes::trans;
}


// COLOR SETTERS

void Shapes::colorR(int Red){
    Shapes::color.R = Red;
}

void Shapes::colorG(int Green){
    Shapes::color.G = Green;
}

void Shapes::colorB(int Blue){
    Shapes::color.B = Blue;
}

void Shapes::drawshape(CImage *img){
 //Does nothing !
}

//*****************************************CIRCLE*****************************************************//

//Constructor
Circle::Circle(int X, int Y, struct RGB color, int trans, int radius):Shapes(X, Y, color, trans){
    Circle::radius = radius;
}

//Radius Getter
int Circle::getRadius(){
    return radius;
}

//Destructor
Circle::~Circle(){
    Circle::radius = 0;
}

//Drawing function
void Circle::drawshape(CImage *img){ // Draw a circle
  int i,j;
  RGB col={255,0,255};

  /*for(i=X-radius;i<X+radius; i++)
    for(j=Y-radius; j<Y+radius; j++)
      if((pow((i-X),2)+pow((j-Y),2)) <= radius*radius) { //Dans le cercle
        CPixel *p = img->getPixel(i,j);
        p->RGB(colorR(),colorG(),colorB());
        }*/

  for(i=X-radius;i<X+radius; i++)
      for(j=Y-radius; j<Y+radius; j++)
        if((pow((i-X),2)+pow((j-Y),2)) <= radius*radius) { //Dans le cercle
          Dot* dot1 = new Dot(i,j,col,getTrans());
          dot1->drawshape(img);
          }
}

//*****************************************RECTANGLE*****************************************************//

//Constructor
Rectangle::Rectangle(int X, int Y, struct RGB color, int trans, int length, int width):Shapes(X, Y, color, trans){
    Rectangle::Length=length;
    Rectangle::Width=width;
}

//Destructor
Rectangle::~Rectangle(){
    Rectangle::Length=0;
    Rectangle::Width=0;
}

// Length and Width Getters
int Rectangle::getLength(){
    return Length;
}

int Rectangle::getWidth(){
    return Width;
}



//Drawing function
void Rectangle::drawshape(CImage *img){ // Draw a Rectangle
    
    int x    = getX();
    int y    = getY();
    int lg   = getLength();
    int larg = getWidth();
    int r    = colorR();
    int g    = colorG();
    int b    = colorB();
    int trans= getTrans();
    RGB colortemp;
    colortemp.R= r;
    colortemp.G= g;
    colortemp.B= b;
    
    
    Line ln1(x,y,colortemp,trans,x+lg,y);
    ln1.drawshape(img);
    
    Line ln2(x,y,colortemp,trans,x,y+larg);
    ln2.drawshape(img);
    
    Line ln3(x,y+larg,colortemp,trans,x+lg, y+larg);
    ln3.drawshape(img);
    
    Line ln4(x+lg, y,colortemp,trans,x+lg,y+larg);
    ln4.drawshape(img);
    
    
}

//*****************************************LINE*****************************************************//

//Constructor
Line::Line(int X, int Y, struct RGB color, int trans, int _X2, int _Y2):Shapes(X, Y, color, trans){
    X2 = _X2;
    Y2 = _Y2;
}

//COORDINATES getter

int Line::getX2(){
    return X2;
}

int Line::getY2(){
    return Y2;
}

//Destructor
Line::~Line(){
}

//Drawing function
void Line::drawshape(CImage *img){ // Draw a Point
    
    int x1    = getX();
    int y1    = getY();
    int x2    = getX2();
    int y2    = getY2();
    int r     = colorR();
    int g     = colorG();
    int b     = colorB();
    int trans = getTrans();
    int x     = x1;
    int y     = y1;
    
    RGB colortemp2;
    colortemp2.R= r;
    colortemp2.G= g;
    colortemp2.B= b;
    
    Dot dot(x,y,colortemp2, trans); //Initialize a point
    
    double k;
    
    dot.setX(x);
    dot.setY(y);
    dot.drawshape(img);
    
    
    for (k=0; k<1; k=k+0.001){
        cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
        x=k*x1+(1-k)*x2;
        y=k*y1+(1-k)*y2;
        cout << x << " " << y << endl;
        dot.setX(x);
        dot.setY(y);
        dot.drawshape(img);
    }
    
}

//*****************************************POINT*****************************************************//

//Constructor
Dot::Dot(int X, int Y, struct RGB color, int trans):Shapes(X, Y, color, trans){

}

//Destructor
Dot::~Dot(){
}

//Drawing function
void Dot::drawshape(CImage *img){ // Draw a Point
    int x=getX();
    int y=getY();
    
    int r=colorR();
    int g=colorG();
    int b=colorB();
    CPixel * p = img->getPixel(x,y);
    p->Red(r);
    p->Green(g);
    p->Blue(b);
    

}

//Rnew = R*trans/255 + Rimage*(1-trans)/255
//Calcul avec transparence
