#include "Ecran.h"
#include <string.h>
#include <iostream>
#include "PixelB.h"

using namespace std;

PixelB::PixelB():Pixel()
{
	val=false;
}

PixelB::PixelB(int x,int y,bool val):Pixel(x,y)
{
	this->val =  val;
}

PixelB::PixelB(const PixelB& pixel)
{
	this->x = pixel.getX();
	this->y = pixel.getY();
	this->val = pixel.getValeur();
}


void PixelB::setValeur(bool coul)
{
	this->val = coul;
}

bool PixelB::getValeur(void) const
{
	return this->val;
}

ostream& operator <<(ostream& s,const PixelB& pixel)
{
	s << "x: " << pixel.getX() << " y: " << pixel.getY();
	s << " Valeur: " << pixel.getValeur();
	return s;
}
