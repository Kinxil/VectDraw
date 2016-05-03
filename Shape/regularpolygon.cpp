#include "regularpolygon.h"

//*****************************************POLYGON*****************************************************//

//Constructor
RegularPolygon::RegularPolygon(int X, int Y, struct RGB color, int trans, int R, int N):Shapes(X, Y, color, trans){

    RegularPolygon::R = R;
    RegularPolygon::N = N;
}

//Radius Getter
int RegularPolygon::getR(){
    return R;
}

//Number of Vertex Getter
int RegularPolygon::getN(){
    return N;
}

//Destructor
RegularPolygon::~RegularPolygon(){
    R = 0;
    N = 0;
}

//Drawing function
void RegularPolygon::drawshape(CImage *img) { // Draw a regular polygon. Notice that triangle shapes are also included
    int i;
    int r = colorR();
    int g = colorG();
    int b = colorB();
    RGB color={r,g,b};
    int Xi, Yi, Xii, Yii;

    for (i = 0; N + 1 >= i; i++) {

        Xi =  (int)(R * cos(2 * M_PI * i / N));
        Yi = (int)(R * sin(2 * M_PI * i / N));
        Xii = (int)(R * cos(2 * M_PI * (i + 1) / N));
        Yii =  (int)(R * sin(2 * M_PI * (i + 1) / N));

        Line lni(X + Xi, Y + Yi, color, trans, X + Xii, Y + Yii);
        lni.drawshape(img);

    }
}
