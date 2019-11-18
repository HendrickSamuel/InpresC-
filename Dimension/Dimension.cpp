#include "Dimension.h"
#include <string.h>
#include <iostream>

using namespace std;

const Dimension Dimension::VGA(640,480);
const Dimension Dimension::HD(1280,720);
const Dimension Dimension::FULL_HD(1920,1080);
// essai avec const impossible


Dimension::Dimension()
{
	setLargeur(300);
	setHauteur(400);
}

Dimension::Dimension(int large, int haut)
{
	setLargeur(large);
	setHauteur(haut);
}
	
Dimension::Dimension(const Dimension& old)
{
	setLargeur(old.getLargeur());
	setHauteur(old.getHauteur());
}

int Dimension::operator==(const Dimension& d1)
{
	if((this->largeur == d1.largeur) && (this->hauteur == d1.hauteur))
		return 1;	
	else
		return 0;
}

int Dimension::operator!=(const Dimension& d1)
{
	if((this->largeur == d1.largeur) && (this->hauteur == d1.hauteur))
		return 0;	
	else
		return 1;
}

void Dimension::setLargeur(int largeget)
{
	if(largeget < 1)
		throw XYException('x',"dimension en largeur trop petite"); 
	largeur = largeget;
}

void Dimension::setHauteur(int hautget)
{
	if(hautget < 1)
		throw XYException('y', "dimension en hauteur trop petite");
	hauteur =  hautget;
}

int Dimension::getLargeur() const
{
	return largeur;
}

int Dimension::getHauteur() const
{
	return hauteur;
}

void Dimension::Affiche() const
{
	cout << "largeur: " << largeur << " hauteur: " << hauteur << endl;
}

ostream& operator <<(ostream& s,const Dimension& d)
{
	s << "largeur: " << d.getLargeur() << " hauteur: " << d.getHauteur() << endl;
	return s;
}

istream& operator >>(istream& s,Dimension& d)
{
	int l,h;
	
	cout << "hauteur: ";
		s>>h;
	
	cout << "largeur: ";
		s>>l;

	d.setHauteur(h);
	d.setLargeur(l);
	
	return s;
	
}

void Dimension::Save(ofstream & fichier) const 
{
	Dimension dimtmp(*this);	
	fichier.write((char*)&dimtmp,sizeof(dimtmp));
}

void Dimension::Load(ifstream & fichier)
{
	Dimension dimtmp;
	fichier.read((char*)&dimtmp,sizeof(dimtmp));
	#ifdef DEVPLUS
	Trace("on recup des dims de: %d par %d",dimtmp.getLargeur(),dimtmp.getHauteur());
	#endif
	setLargeur(dimtmp.getLargeur());
	setHauteur(dimtmp.getHauteur());	
}
