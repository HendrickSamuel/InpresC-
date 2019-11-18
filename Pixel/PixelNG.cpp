#include "Ecran.h"
#include <string.h>
#include <iostream>
#include "PixelNG.h"

using namespace std;

PixelNG::PixelNG():Pixel()
{
	val=0;
}

PixelNG::PixelNG(int x,int y,int val):Pixel(x,y)
{
	
	setValeur(val);
}

PixelNG::PixelNG(const PixelNG& pixel)
{
	this->x = pixel.getX();
	this->y = pixel.getY();
	this->val = pixel.getValeur();
}


void PixelNG::setValeur(int val)
{
	if(val < 0 || val > 255)
		throw RGBException(val,"Composant du PixelNG invalide");
	this->val = val;
}


int PixelNG::getValeur(void) const
{
	return this->val;
}

ostream& operator <<(ostream& s,const PixelNG& pixel)
{
	s << "x: " << pixel.getX() << " y: " << pixel.getY() << " val: " << pixel.getValeur();
	return s;
}
