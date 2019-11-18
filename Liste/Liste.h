#ifndef LISTE_H
#define LISTE_H
#include "ListeBase.h"
#include "Ecran.h"

using namespace std;

template <class T> class Liste: public ListeBase<T>
{
	private :
		
		
	public :
		Liste();
		Liste(const Liste&);
		~Liste();

		void insere(const T & val);
		
		
};

#endif
