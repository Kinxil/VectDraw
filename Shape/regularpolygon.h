#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include "Shapes.h"
#include "line.h"

//*****************************************Polygon*****************************************************//

class RegularPolygon : public Shapes{ // As its name alreday mentionned it, only regular polygons are included in this class (Triangles included)
private:
    //The minimal's coordinates Xmin and Ymin are in class Shape : X and Y
    int R; // Defines the size of the polygon
    int N; // Defines the number of Vertices

public:

    void drawshape(CImage *img);
    int getR();
    int getN();
    RegularPolygon(int X, int Y, struct RGB color, int trans, int R, int N); // New polygon
    ~RegularPolygon(); // Delete
};

#endif // REGULARPOLYGON_H
