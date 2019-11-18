#ifndef MOTEUREXCEPTION_H
#define MOTEUREXCEPTION_H
#include "BaseException.h"

class MoteurException: public BaseException
{
	public:
		MoteurException(const char*);
		~MoteurException();
};
	
#endif
