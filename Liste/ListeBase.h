#ifndef LISTEBASE_H
#define LISTEBASE_H
#include "Ecran.h"
#include "stdlib.h"

using namespace std;

#include "struct.h"
template<class T> class Iterateur;

template<class T> class ListeBase
{
	protected :
		Cellule<T> *pTete ;
		
	public :
		ListeBase();
		ListeBase(const ListeBase&);
		virtual ~ListeBase();
		
		const ListeBase<T>& operator=(const ListeBase&);
		
		Cellule<T>* getpTete(void) const;
		void setpTete(Cellule<T>*);		
		bool estVide() const;
		int getNombreElements() const;
		void Affiche() const;
		virtual void insere(const T & val) = 0;
		
		friend class Iterateur<T>;
		
		
};

#endif
