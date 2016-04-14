
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

  void loadBuffer(std::string *buf, int n, std::ifstream &file);
  struct RGB str2color (std::string c);

public:
  std::vector<Shapes*> shapes;
  Draw();
  ~Draw();
  void loadFromFile(std::string f);
  void drawShapes(CImage *img);
};

#endif // DRAW_H
