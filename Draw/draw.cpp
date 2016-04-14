#include "draw.h"
#define MAXBUF 8

using namespace std;

Draw::Draw() {}

Draw::~Draw(){}

void Draw::loadBuffer(string *buf, int n, ifstream &file) {
  if(n>MAXBUF)
    n=MAXBUF;

  for(int i=1; i<=n; i++)
    getline(file,buf[i]);
}


RGB Draw::str2color(string c) {
    RGB temp;
    stringstream ssc(c);
    string token;

    ssc >> token;
    temp.R = stoi(token);
    ssc >> token;
    temp.G = stoi(token);
    ssc >> token;
    temp.B = stoi(token);
    return temp;
}

void Draw::loadFromFile(string f) {
  ifstream file;
  string buf[MAXBUF];
  RGB color;

  file.open(f);

  if(file.is_open())
    while(getline (file,buf[0])){
        if(buf[0].find("DOT")!=string::npos){ //Shape match = Dot
            loadBuffer(buf,4,file); //Load values
            color = str2color(buf[3]);
            Dot* dotBuf = new Dot(stoi(buf[1]), stoi(buf[2]), color, stoi(buf[4]));//Create Dot
            shapes.push_back(dotBuf);//Store Dot
          }

        //Others shapes follow same principle
        else if(buf[0].find("LINE")!=string::npos){
            loadBuffer(buf,6, file);
            color = str2color(buf[3]);
            Line* lineBuf = new Line(stoi(buf[1]), stoi(buf[2]), color, stoi(buf[4]),stoi(buf[5]), stoi(buf[6]));
            shapes.push_back(lineBuf);
          }

        else if(buf[0].find("RECTANGLE")!=string::npos){
            loadBuffer(buf,6, file);
            color = str2color(buf[3]);
            Rectangle *rectBuf = new Rectangle(stoi(buf[1]), stoi(buf[2]), color, stoi(buf[4]),stoi(buf[5]), stoi(buf[6]));
            shapes.push_back(rectBuf);
          }

        /*else if(buf[0].find("SQUARE")!=string::npos){
            loadBuffer(buf,5, file);
            color = str2color(buf[3]);
            Square sqBuf(stoi(buf[1]), stoi(buf[2]), color, stoi(buf[4]),stoi(buf[5]));
            shapes.push_back(sqBuf);
          }*/

        else if(buf[0].find("CIRCLE")!=string::npos){
            loadBuffer(buf,5, file);
            color = str2color(buf[3]);
            Circle *circleBuf = new Circle(stoi(buf[1]), stoi(buf[2]), color, stoi(buf[4]),stoi(buf[5]));
            shapes.push_back(circleBuf);
          }
      }

  else
    cout << "Could not find file\n";
}

void Draw::drawShapes(CImage *img)
{
  //Shapes *buf;
  for(unsigned int i=0; i<shapes.size(); i++)
    {
      //buf = shapes[i];
      shapes[i]->drawshape(img);
    }
}
