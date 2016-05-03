
#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../Shape/Shapes.h"
#include "../Shape/rectangle.h"
#include "../Shape/frectangle.h"
#include "../Shape/square.h"
#include "../Shape/fsquare.h"
#include "../Shape/dot.h"
#include "../Shape/line.h"
#include "../Shape/circle.h"
#include "../Shape/disc.h"
#include "../Shape/regularpolygon.h"

class Draw {
private:
  std::vector<Shapes*> shapes;
  void loadBuffer(std::string *buf, int n, std::ifstream &file);
  struct RGB str2color (std::string c);
  double scaling;

public:
  Draw();
  ~Draw();
  void setScaling(double _scaling);
  void setScaling(int _scaling);
  void loadFromFile(std::string f); //Load all shapes in a file
  void drawShapes(CImage *img); //Draw all shapes in img file
};

#endif // DRAW_H
