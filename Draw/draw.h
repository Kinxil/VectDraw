#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "../Shape/Shapes.h"

class Draw {
private:
  std::vector<Shape> shapes;
  void loadBuffer(std::string *buf, int n, std::ifstream &file);
  struct rgb str2color (std::string c);

public:
  Draw();
  ~Draw();
  void loadFromFile(std::string f);
  void drawShapes();
};

#endif // DRAW_H
