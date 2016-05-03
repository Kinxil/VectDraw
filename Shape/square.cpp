#include "square.h"

Square::Square(int X, int Y, RGB color, int trans, int Length):Rectangle(X,Y,color,trans,Length,Length){
  //Does nothing but using Width=Length
}

Square::~Square(){}
