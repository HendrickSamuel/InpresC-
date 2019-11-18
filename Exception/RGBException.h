#ifndef RGBEXEPTION_H
#define RGBEXEPTION_H
#include "BaseException.h"
#include"Ecran.h"
	
class RGBException :public BaseException
{
	private: 
		int valeur;
	public:
		RGBException();
		//RGBException(int);
		RGBException(int,const char*);
		RGBException(const RGBException&);
		~RGBException();
		
		void setValeur(int);
		
		int getValeur(void) const;
}; 
	
#endif
