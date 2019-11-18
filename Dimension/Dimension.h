#ifndef DIMENSION_H
#define DIMENSION_H
#include <iostream>
#include "XYException.h"
#include <fstream>
using namespace std;


#include <string.h>
class Dimension
{
	private: 
		int largeur;
		int hauteur;

	public:
		
		static const Dimension VGA; 
		static const Dimension HD;
		static const Dimension FULL_HD;
		// essai avec const impossible
			
		Dimension();
		Dimension(int,int);
		Dimension(const Dimension&);
		
		int operator ==(const Dimension&);
		int operator !=(const Dimension&);
		friend ostream& operator <<(ostream&,const Dimension&);
		friend istream& operator >>(istream&,Dimension&);
	
		void setLargeur(int);
		void setHauteur(int);
		int getLargeur() const;
		int getHauteur() const;
		void Affiche() const ;
		void Save(ofstream &) const; 
		void Load(ifstream &);
		
};

#endif
// VGA(640,480) HD(1280,720) FULL_HD(1920,1080)
