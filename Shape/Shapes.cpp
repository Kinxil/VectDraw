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
Shapes::Shapes(int _X, int _Y, struct RGB _color,int _trans){

    trans = _trans;
    X = _X;
    Y = _Y;
    color = _color;
}

//Destructor
Shapes::~Shapes(){}

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

RGB Shapes::colorRGB(){
    return color;
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


//TRANSPARENCY GETTER

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

void Shapes::colorRGB(RGB _color){
    color = _color;
}

//Virtual drawshape
void Shapes::drawshape(CImage *img){
    //Does nothing !
}


<<<<<<< HEAD




=======
//Constructor
Circle::Circle(int X, int Y, struct RGB color, int trans, int radius):Shapes(X, Y, color, trans){
    Circle::radius = radius;
}

Disc::Disc(int X, int Y, struct RGB color, int trans, int radius):Circle(X, Y, color, trans, radius){}

//Radius Getter
int Circle::getRadius(){
    return radius;
}

//Destructor
Circle::~Circle(){}

Disc::~Disc(){}

//Drawing function
void Circle::drawshape(CImage *img){ // Draw a circle
    int i;
    int perimeter = (int)(2*M_PI*radius); //inner definition of the number of pixel to write > angle step

    for(i=0; i<perimeter+1; i++){
        int xi= (int)(getX() + radius*cos((double)i/radius));
        int yi= (int)(getY() + radius*sin((double)i/radius));
        Dot* dot1 = new Dot(xi,yi,color,trans);
        dot1->drawshape(img);
    }
}

void Disc::drawshape(CImage *img){
    int i,j;

    for(i=getX()-radius;i<getX()+radius; i++)
        for(j=getY()-radius; j<getY()+radius; j++)
            if((pow((i-getX()),2)+pow((j-getY()),2)) <= radius*radius) { //Dans le cercle
                Dot* dot1 = new Dot(i,j,color,trans);
                dot1->drawshape(img);
            }
}

//*****************************************POLYGON*****************************************************//

//Constructor
RegularPolygon::RegularPolygon(int X, int Y, struct RGB color, int trans, int R, int N):Shapes(X, Y, color, trans){

    RegularPolygon::R = R;
    RegularPolygon::N = N;
}

//Radius Getter
int RegularPolygon::getR(){
    return R;
}

//Number of Vertex Getter
int RegularPolygon::getN(){
    return N;
}

//Destructor
RegularPolygon::~RegularPolygon(){
    R = 0;
    N = 0;
}

//Drawing function
void RegularPolygon::drawshape(CImage *img) { // Draw a regular polygon. Notice that triangle shapes are also included
    int i;
    int r = colorR();
    int g = colorG();
    int b = colorB();
    RGB color={r,g,b};
    int Xi, Yi, Xii, Yii;

    for (i = 0; N + 1 >= i; i++) {

        Xi =  (int)(R * cos(2 * M_PI * i / N));
        Yi = (int)(R * sin(2 * M_PI * i / N));
        Xii = (int)(R * cos(2 * M_PI * (i + 1) / N));
        Yii =  (int)(R * sin(2 * M_PI * (i + 1) / N));

        Line lni(X + Xi, Y + Yi, color, trans, X + Xii, Y + Yii);
        lni.drawshape(img);

    }
}

//*****************************************RECTANGLE*****************************************************//

//Constructor
Rectangle::Rectangle(int X, int Y, struct RGB color, int trans, int length, int width):Shapes(X, Y, color, trans){
    Length=length;
    Width=width;
}

FRectangle::FRectangle(int X, int Y, RGB color, int trans, int Length, int Width):Rectangle(X,Y,color,trans,Length,Width){}

Square::Square(int X, int Y, RGB color, int trans, int Length):Rectangle(X,Y,color,trans,Length,Length){
    //Does nothing but using Width=Length
}

FSquare::FSquare(int X, int Y, RGB color, int trans, int Length):FRectangle(X,Y,color,trans,Length,Length){}

//Destructor
Rectangle::~Rectangle(){}

FRectangle::~FRectangle(){}

Square::~Square(){}

FSquare::~FSquare(){}

// Length and Width Getters
int Rectangle::getLength(){
    return Length;
}

int Rectangle::getWidth(){
    return Width;
}

//Drawing function
void Rectangle::drawshape(CImage *img){ // Draw a Rectangle
    Line ln1(X,Y,color,trans,X+Length,Y);
    ln1.drawshape(img);

    Line ln2(X,Y,color,trans,X,Y+Width);
    ln2.drawshape(img);

    Line ln3(X,Y+Width,color,trans,X+Length, Y+Width);
    ln3.drawshape(img);

    Line ln4(X+Length, Y,color,trans,X+Length,Y+Width);
    ln4.drawshape(img);
}

void FRectangle::drawshape(CImage *img){
    for(int i=0; i<Length; i++)
        for(int j=0; j<Width; j++){
            Dot dot1(X+i,Y+j,color,trans);
            dot1.drawshape(img);
        }
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
Line::~Line(){}

//Drawing function
void Line::drawshape(CImage *img){ // Draw a Point
    int x     = X;
    int y     = Y;
    int prevx = -1;
    int prevy = -1;

    Dot dot(x,y,color, trans); //Initialize a point
    dot.setX(x);
    dot.setY(y);
    dot.drawshape(img);

    for (double k=0; k<1; k=k+0.001){
        x=(int)(k*X+(1-k)*X2);
        y=(int)(k*Y+(1-k)*Y2);
        if(x!=prevx || y!=prevy) { //New point ?
            prevx=x;
            prevy=y;
            dot.setX(x);
            dot.setY(y);
            dot.drawshape(img);
        }
    }

}

//*****************************************POINT*****************************************************//

//Constructor
Dot::Dot(int X, int Y, struct RGB color, int trans):Shapes(X, Y, color, trans){}

//Destructor
Dot::~Dot(){}

//Drawing function
void Dot::drawshape(CImage *img){ // Draw a Point
    if(img->isInPicture(X,Y)){ //To make sure it's in picture
        int rcalc, gcalc, bcalc;
        CPixel * p = img->getPixel(X,Y);
        rcalc = (int)(color.R*(1-trans/255.0f) + p->Red()*trans/255.0f);
        gcalc = (int)(color.G*(1-trans/255.0f) + p->Green()*trans/255.0f);
        bcalc = (int)(color.B*(1-trans/255.0f) + p->Blue()*trans/255.0f);
        p->RGB(rcalc,gcalc,bcalc);
    }
}
>>>>>>> origin/master
