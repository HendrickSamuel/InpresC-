#ifndef XYEXEPTION_H
#define XYEXEPTION_H
#include "BaseException.h"
#include"Ecran.h"

class XYException : public BaseException
{
	private: 
		char coordonnee;
	public:
		XYException();
		XYException(char,const char*);
		XYException(const XYException&);
		~XYException();
		
		void setCoordonnee(char);
		
		char getCoordonnee(void) const;
}; 
	
#endif
