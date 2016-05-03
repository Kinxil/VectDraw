#include "frectangle.h"

FRectangle::FRectangle(int X, int Y, RGB color, int trans, int Length, int Width):Rectangle(X,Y,color,trans,Length,Width){}

FRectangle::~FRectangle(){}

void FRectangle::drawshape(CImage *img){
  for(int i=0; i<Length; i++)
    for(int j=0; j<Width; j++){
        Dot dot1(X+i,Y+j,color,trans);
        dot1.drawshape(img);
      }
}
