#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "./Format/CBitmap.h"
#include "./Draw/draw.h"
#include "Processing/processing.h"

int main(int argc, char * argv[]) {
  double scale = 1.5f;

  //Default program
  cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
  cout << "(II) + Number of arguments = " << argc << endl;

  cout << "(II) CBitmap object creation" << endl;
  CBitmap *image = new CBitmap();
  string filename2 = "Sortie.bmp";
  string filename3 = "Sortie2.bmp";

  cout << "(II) CImage pointer extraction" << endl;
  CImage   *img = new CImage(scale*250, scale*200);

  //Tests
  Draw *newdraw = new Draw();
  newdraw->setScaling(scale);
  newdraw->loadFromFile("formes.txt");
  newdraw->drawShapes(img);

  image->setImage( img );
  cout << "(II) CBitmap image saving" << endl;
  image->SaveBMP(filename2);

  Processing *newP = new Processing();
  CBitmap *image2 = new CBitmap();
  img = newP->imgScaling(img,2.0f);
  image2->setImage( img );
  cout << "Modified image saving" << endl;
  image2->SaveBMP(filename3);

 // delete newdraw;
  return 1;
}

