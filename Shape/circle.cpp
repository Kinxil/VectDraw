#include "circle.h"

//*****************************************CIRCLE*****************************************************//

//Constructor
Circle::Circle(int X, int Y, struct RGB color, int trans, int radius):Shapes(X, Y, color, trans){
  Circle::radius = radius;
}

//Destructor
Circle::~Circle(){}

//Radius Getter
int Circle::getRadius(){
  return radius;
}


//Drawing function
void Circle::drawshape(CImage *img){ // Draw a circle
  int i;
  int perimeter = 2*M_PI*radius; //inner definition of the number of pixel to write > angle step

  for(i=0; i<perimeter+1; i++){
      int xi= getX() + radius*cos((double)i/radius);
      int yi= getY() + radius*sin((double)i/radius);
      Dot* dot1 = new Dot(xi,yi,color,trans);
      dot1->drawshape(img);
    }
}
