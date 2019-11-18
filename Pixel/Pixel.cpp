#include "Ecran.h"
#include <string.h>
#include <iostream>
#include "Pixel.h"

using namespace std;

Pixel::Pixel()
{
	x=0;
	y=0;
}

Pixel::Pixel(int x,int y)
{
	this->setX(x);
	this->setY(y);
}

Pixel::Pixel(const Pixel& pixel)
{
	this->setX(pixel.getX());
	this->setY(pixel.getY());
}

void Pixel::setX(int x)
{	
	if(x < 0)
		throw XYException('x',"Position du Pixel invalide");
	this->x = x;
}
void Pixel::setY(int y)
{
	if(y < 0)
		throw XYException('y',"Position du Pixel invalide");
	this->y = y;
}

int Pixel::getX(void) const
{
	return this->x;
}

int Pixel::getY(void) const
{
	return this->y;
}

bool Pixel::operator==(const Pixel& p2) const
{
	if((this->getX() == p2.getX())&&(this->getY() == p2.getY()))
		return true;
	else
		return false;
}
