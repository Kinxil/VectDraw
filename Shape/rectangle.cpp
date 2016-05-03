#include "rectangle.h"

//Constructor
Rectangle::Rectangle(int X, int Y, struct RGB color, int trans, int length, int width):Shapes(X, Y, color, trans){
  Length=length;
  Width=width;
}

//Destructor
Rectangle::~Rectangle(){}

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
