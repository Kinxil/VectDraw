#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "./Format/CBitmap.h"
#include "./Draw/draw.h"

int main(int argc, char * argv[]) {
  //Default program
  cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
  cout << "(II) + Number of arguments = " << argc << endl;

  cout << "(II) CBitmap object creation" << endl;
  CBitmap *image = new CBitmap();
  string filename2 = "Sortie.bmp";

  cout << "(II) CImage pointer extraction" << endl;
  CImage   *img = new CImage(200, 200);
  for(int i=0; i<200; i++){
      CPixel *p = img->getPixel(i, i);
      p->RGB(255,255,255);
    }

  //Tests
  Draw newdraw;
  newdraw.loadFromFile("formes.txt");

  RGB col={255,0,255};
  Circle* c = new Circle(50,50,col,50,25);
  c->drawshapeC(img);
  Rectangle *rec = new Rectangle(100,100,col,50,20,20);
  rec->drawshapeR(img);
  Line *li = new Line(150,150,col,50,170,190);
  li->drawshapeL(img);

  image->setImage( img );
  cout << "(II) CBitmap image saving" << endl;
  image->SaveBMP(filename2);
  return 1;
}

