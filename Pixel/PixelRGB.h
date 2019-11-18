#ifndef PIXELRGB_H
#define PIXELRGB_H
#include "Pixel.h"
#include "Couleur.h"
class PixelRGB: public Pixel
{
	private:
		Couleur val;
	public:
		PixelRGB();
		PixelRGB(int,int,const Couleur &);
		PixelRGB(const PixelRGB&);
		
		friend ostream& operator <<(ostream&,const PixelRGB&);
		
		void setValeur(const Couleur &);
		
		const Couleur& getValeur(void) const;
};
#endif
