#include "BaseException.h"

/*---------------------------------Constructeurs -----------------------------------*/

BaseException::BaseException()
{
	#ifdef DEV
	TraceConstructeur("Creation BaseException simple");
	#endif
	message = NULL;
}

BaseException::BaseException(const char* chaineget)
{
	#ifdef DEV
	TraceConstructeur("Creation BaseException par valeur");
	#endif
	message = NULL;
	setMessage(chaineget);
}
BaseException::BaseException(const BaseException& old)
{
	#ifdef DEV
	TraceConstructeur("Creation BaseException par copie");
	#endif
	message = NULL;
	setMessage(old.getMessage());
}

BaseException::~BaseException()
{
	#ifdef DEV
	TraceConstructeur("Destruction BaseException");
	#endif
	if(message)
		delete message;
}
/*---------------------------------Setteurs -----------------------------------*/

void BaseException::setMessage(const char* chaineget)
{
	if(message)
	{
		delete message;
	}
	if(chaineget)
	{
		message = new char[strlen(chaineget)+1];
		strcpy(message,chaineget);
	}
	else
	{
	 message = NULL;
	}
} 

/*---------------------------------Getteurs -----------------------------------*/

const char* BaseException::getMessage() const
{
	return message;
}
