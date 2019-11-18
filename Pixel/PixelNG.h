#ifndef PIXELNG_H
#define PIXELNG_H
#include "Pixel.h"
#include "RGBException.h"
class PixelNG: public Pixel
{
	private:
		int val;
	public:
		PixelNG();
		PixelNG(int,int,int);
		PixelNG(const PixelNG&);
		
		friend ostream& operator <<(ostream&,const PixelNG&);
		
		void setValeur(int);
		
		int getValeur(void) const;
};
#endif
