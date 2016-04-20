/*
 *  CImage.cpp
 *  P_Bitmap
 *
 *  Created by Le Gal on 24/10/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include "CImage.h"

CImage::CImage(int _hauteur, int _largeur){
    //cout << "Instanciation des lignes... " << taille << endl;
    taille = _hauteur;
    liste = (CLigne**)new CLigne**[taille];
    for(int i=0; i<taille; i++){
        liste[i] = new CLigne(_largeur);
    }
    l=_largeur;
    h=_hauteur;
}

CImage::~CImage(){
    for(int i=0; i<taille; i++)
        delete liste[i];
    delete liste;
}

int CImage::size(){
    return taille;
}

CLigne* CImage::getLigne(int position){
    if( (position >= taille) ){
        cout << "CImage::getLigne => trying to access " << position << " but the line has only " << taille << " data" << endl;
    }
    return (position < taille)?liste[position]:NULL;
}

CPixel* CImage::getPixel(int posX, int posY){
    CLigne* ligne =  getLigne( posY );
    if( ligne == NULL) return NULL;
    return ligne->getPixel(posX);
}

int CImage::largeur(){
  return l;
}

int CImage::hauteur(){
  return h;
}

bool CImage::isInPicture(int x, int y){
  if(x<0||x>=l||y<0||y>=h)
    return false;
  return true;
}
