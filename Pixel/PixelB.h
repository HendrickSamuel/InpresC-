#ifndef PIXELB_H
#define PIXELB_H
#include "Pixel.h"
class PixelB: public Pixel
{
	private:
		bool val;
	public:
		PixelB();
		PixelB(int,int,bool);
		PixelB(const PixelB&);
		
		friend ostream& operator <<(ostream&,const PixelB&);
		
		void setValeur(bool);
		
		bool getValeur(void) const;
};
#endif
