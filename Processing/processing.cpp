#include "processing.h"

Processing::Processing(){}

//Scaling : This method use simple down/upsampling with a inner averaging filter 3x3
//Upsampling will cause few aliasing but blurred edges
CImage* Processing::imgScaling(CImage *img, double _scaling){
  if(_scaling < 0)
    _scaling = - _scaling;

  int l = img->largeur()*_scaling;
  int h = img->hauteur()*_scaling;
  cout <<"h/l : "  << h << " "<< l << endl;
  CImage *tmp = new CImage (h,l);

  for(int i=0; i<l; i++)
    for(int j=0; j<h; j++){
      int iOrig = i/_scaling; //Get nearest i
      int jOrig = j/_scaling; //Get nearest j

      CPixel *pf = new CPixel(); //Temporary pixel
      if(iOrig > 0 && iOrig < img->largeur()-1 &&jOrig > 0 && jOrig < img->hauteur()-1){ //Not in border
          for(int i_f=-1; i_f<=1; i_f++)
            for(int j_f=-1; j_f<=1; j_f++){
                CPixel *p1 = img->getPixel(iOrig+i_f,jOrig+j_f);
                pf->Red(pf->Red() + round(p1->Red()/9.0f));
                pf->Green(pf->Green() + round(p1->Green()/9.0f));
                pf->Blue(pf->Blue() + round(p1->Blue()/9.0f));
              }
          pf->RGB(pf->Red(), pf->Green(), pf->Blue());
        }

      else{ //In border
          CPixel *p1 = img->getPixel(iOrig,jOrig);
          pf->RGB(p1->Red(),p1->Green(),p1->Blue());
        }
      CPixel *pdest = tmp->getPixel(i,j);
      pdest->RGB(pf->Red(),pf->Green(),pf->Blue());
    }

  return tmp;
}
