#include "line.h"

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
      x=k*X+(1-k)*X2;
      y=k*Y+(1-k)*Y2;
      if(x!=prevx || y!=prevy) { //New point ?
        prevx=x;
        prevy=y;
        dot.setX(x);
        dot.setY(y);
        dot.drawshape(img);
        }
    }

}
