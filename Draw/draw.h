
#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../Shape/Shapes.h"

class Draw {
private:
  std::vector<Shapes*> shapes;
  void loadBuffer(std::string *buf, int n, std::ifstream &file);
  struct RGB str2color (std::string c);

public:
  Draw();
  ~Draw();
  void loadFromFile(std::string f); //Load all shapes in a file
  void drawShapes(CImage *img); //Draw all shapes in img file
};

#endif // DRAW_H
