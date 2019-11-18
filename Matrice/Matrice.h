#ifndef MATRICE_H
#define MATRICE_H
#include "Ecran.h"
#include "Dimension.h"
#include <iostream>
using namespace std;

template <class T> class Matrice
{
	private:
		T** tab;
		int hauteur;
		int largeur;
		
		void creeTab(int,int);		
	public:
		Matrice();
		Matrice(int,int);
		Matrice(int,int,const T&);
		Matrice(const Matrice&);
		~Matrice();
		
		const Matrice<T>& operator=(const Matrice&);
		const T operator()(int x,int y) const;
		T& operator()(int x,int y);		
		
		void setValeur(int,int,const T&);
		void setLargeur(int);
		void setHauteur(int);

		const T& getValeur(int,int) const;
		int getLargeur() const;
		int getHauteur() const;	
		
		void Affiche() const;
		void Redimension(int, int);
		void Redimension(const Dimension&);
}; 


#endif
