#ifndef PIXEL_H
#define PIXEL_H
#include "XYException.h"
class Pixel
{
	protected:
		int x;
		int y;

	public:
		Pixel();
		Pixel(int,int);
		Pixel(const Pixel&);

		void setX(int);
		void setY(int);

		
		int getX(void) const;
		int getY(void) const;
		bool operator==(const Pixel&) const;
};
#endif
