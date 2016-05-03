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

void Shapes::colorRGB(RGB _color){
  color = _color;
}

//Virtual drawshape
void Shapes::drawshape(CImage *img){
  //Does nothing !
}






