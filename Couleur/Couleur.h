#ifndef COULEUR_H
#define COULEUR_H

#include "Ecran.h"
#include "RGBException.h"
#include <iostream>
#include <fstream>
using namespace std;

class Couleur
{
	private: 
		int rouge;
		int vert;
		int bleu;
		

	public:
		static const Couleur ROUGE; 
		static const Couleur VERT;
		static const Couleur BLEU;
		static const Couleur BLANC;
		static const Couleur NOIR;
		
		Couleur();
		Couleur(int,int,int);
		Couleur(const Couleur&);
		
		const Couleur& operator=(const Couleur&);
		friend ostream& operator <<(ostream&,const Couleur&);	
		friend istream& operator >>(istream&, Couleur&);
		
		void setRouge(int);
		void setVert(int);
		void setBleu(int);
		
		int getRouge() const;
		int getVert() const;
		int getBleu() const;
		
		void Affiche() const;
		void Save(ofstream &) const; 
		void Load(ifstream &);		

};

#endif

