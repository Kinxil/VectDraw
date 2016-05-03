#include "disc.h"

Disc::Disc(int X, int Y, struct RGB color, int trans, int radius):Circle(X, Y, color, trans, radius){}

Disc::~Disc(){}

void Disc::drawshape(CImage *img){
  int i,j;

  for(i=getX()-radius;i<getX()+radius; i++)
    for(j=getY()-radius; j<getY()+radius; j++)
      if((pow((i-getX()),2)+pow((j-getY()),2)) <= radius*radius) { //Dans le cercle
          Dot* dot1 = new Dot(i,j,color,trans);
          dot1->drawshape(img);
        }
}
