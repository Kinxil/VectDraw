/*
 *  CImage.h
 *  P_Bitmap
 *
 *  Created by Le Gal on 24/10/06.
 *  Copyright 2006 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "CLigne.h"

#ifndef CIMAGE_H_
#define CIMAGE_H_

class CImage{
private:
    CLigne** liste;
    int taille;
    int h;
    int l;

public:
    CImage(int _hauteur, int _largeur);

    ~CImage();

    int size();

    CLigne* getLigne(int position);

    CPixel* getPixel(int posX, int posY);

    int largeur();
    int hauteur();
    bool isInPicture(int x, int y);
};

#endif /*CIMAGE_H_*/
