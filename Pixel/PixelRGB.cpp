#include "Ecran.h"
#include <string.h>
#include <iostream>
#include "PixelRGB.h"

using namespace std;

PixelRGB::PixelRGB():Pixel()
{
	val=Couleur::NOIR;
}

PixelRGB::PixelRGB(int x,int y,const Couleur& coul):Pixel(x,y)
{
	this->val =  coul;
}

PixelRGB::PixelRGB(const PixelRGB& pixel)
{
	this->x = pixel.getX();
	this->y = pixel.getY();
	this->val = pixel.getValeur();
}


void PixelRGB::setValeur(const Couleur& coul)
{
	this->val = coul;
}


const Couleur& PixelRGB::getValeur(void) const
{
	return this->val;
}

ostream& operator <<(ostream& s,const PixelRGB& pixel)
{
	s << "x: " << pixel.getX() << " y: " << pixel.getY();
	s << " R: " << pixel.getValeur().getRouge();
	s << " G: " << pixel.getValeur().getVert();
	s << " B: " << pixel.getValeur().getBleu();
	return s;
}
