#include "XYException.h"

XYException::XYException():BaseException()
{
	setCoordonnee('n'); // none
}

XYException::XYException(char coord,const char* msg):BaseException(msg)
{
	setCoordonnee(coord);
}
XYException::XYException(const XYException& old)
{
	setMessage(old.getMessage());
	setCoordonnee(old.getCoordonnee());
}

XYException::~XYException()
{
}
		
void XYException::setCoordonnee(char c)
{
	if(c == 'x' || c == 'y' || c == 'd')
		coordonnee = c;
	else
		coordonnee = 'n';
}
	
char XYException::getCoordonnee(void) const
{
	return coordonnee;
} 
	

