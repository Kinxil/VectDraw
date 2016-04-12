//
//  Shapes.cpp
//  Dessin vectoriel
//
//  Created by samir on 12/04/16.
//  Copyright © 2016 samir. All rights reserved.
//

#include "Shapes.hpp"

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
Circle::drawshape(){ // Draw a circle

    
    
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
Rectangle::drawshape(){ // Draw a Rectangle
    
    
    
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
Line::drawshape(){ // Draw a Point
    
    
};

//*****************************************POINT*****************************************************//

//Constructor
Point::Point(int X, int Y, struct RGB color, int trans):Shapes(X, Y, color, trans){

};

//Destructor
Point::~Point(){
};

//Drawing function
Point::drawshape(){ // Draw a Point
    
    

};
