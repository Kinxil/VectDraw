#ifndef FSQUARE_H
#define FSQUARE_H

#include "frectangle.h"

/*Note I have an interesting yet weird behavior here :
FSquare derivates from FRectangle and I expected it to use
FRectangle::drawshape() but it seems that FSquare is currently
using Rectangle::drawshape()
Is derived class using the highest parent non virtual function ?
If yes how make it using direct parent version ?
 */
class FSquare : public FRectangle{
public:
  FSquare(int X, int Y, struct RGB color, int trans, int Length);
  ~FSquare();
};

#endif // FSQUARE_H
