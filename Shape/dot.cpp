#include "dot.h"

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
      rcalc = color.R*(1-trans/255.0f) + p->Red()*trans/255.0f;
      gcalc = color.G*(1-trans/255.0f) + p->Green()*trans/255.0f;
      bcalc = color.B*(1-trans/255.0f) + p->Blue()*trans/255.0f;
      p->RGB(rcalc,gcalc,bcalc);
    }
}
