#ifndef ITERATEUR_H
#define ITERATEUR_H
#include "ListeBase.h"
#include "struct.h"
#include "Ecran.h"
#include "BaseException.h"

template <class T> class Iterateur
{
	private:
		ListeBase<T>& liste;
		Cellule<T> *pCur;
		
	public:
		Iterateur(ListeBase<T>&);
		~Iterateur();
		
		void reset(); //qui réinitialise l’itérateur au début de la liste.
		bool end(); //qui retourne le booléen true si l’itérateur est situé au bout de la liste.
		Cellule<T>* getpCur();
		T remove(); //qui supprime de la liste et retourne l’élément pointé par l’itérateur.
		bool operator++();//Opérateur ++ qui déplace l’itérateur vers la droite.
		bool operator++(int);
		operator T()const;//Opérateur de casting () qui retourne (par valeur) l’élément pointé par l’itérateur.
		T& operator&();//Opérateur & qui retourne (par référence) l’élément pointé par l’itérateur.
	
};

#endif
