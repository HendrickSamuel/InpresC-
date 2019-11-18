#include "RGBException.h"

RGBException::RGBException():BaseException()
{
	setValeur(0);
}

RGBException::RGBException(int val,const char* msg):BaseException(msg)
{
	setValeur(val);	
}
RGBException::RGBException(const RGBException& old)
{
	setMessage(old.getMessage());
	setValeur(old.getValeur());
}
RGBException::~RGBException()
{

}
	
void RGBException::setValeur(int val)
{
	this->valeur = val;
}

int RGBException::getValeur() const
{
	return this->valeur;
}

