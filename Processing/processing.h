#ifndef PROCESSING_H
#define PROCESSING_H

#include "../Image/CImage.h"
#include <math.h>

class Processing
{
public:
  Processing();
  CImage *imgScaling(CImage *img, double _scaling);
};

#endif // PROCESSING_H
