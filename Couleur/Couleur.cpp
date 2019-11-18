#include "Couleur.h"

const Couleur Couleur::ROUGE(255,0,0);
const Couleur Couleur::VERT(0,255,0);
const Couleur Couleur::BLEU(0,0,255);
const Couleur Couleur::BLANC(255,255,255);
const Couleur Couleur::NOIR(0,0,0);

Couleur::Couleur()
{
	setRouge(0);
	setVert(0);
	setBleu(0);
}

Couleur::Couleur(int r,int g,int b)
{
	#ifdef DEVPLUS
	TraceConstructeur("Constructeur R: %d G: %d B: %d", r,g,b);
	#endif 
	setRouge(r);
	setVert(g);
	setBleu(b);
}

Couleur::Couleur(const Couleur& old)
{
	#ifdef DEVPLUS
	TraceConstructeur("Constructeur R: %d G: %d B: %d", old.getRouge(),old.getVert(),old.getBleu());
	#endif 
	setRouge(old.getRouge());
	setVert(old.getVert());
	setBleu(old.getBleu());
}
 
const Couleur& Couleur::operator=(const Couleur& old){
	setRouge(old.getRouge());
	setVert(old.getVert());
	setBleu(old.getBleu());

	return(*this);
}

ostream& operator<<(ostream& s, const Couleur& coul)
{
	s<<"[R: " <<coul.getRouge();
	s<<" G: " <<coul.getVert();
	s<<" B: " <<coul.getBleu() << "]";	
return s;
}

istream& operator >>(istream& s,Couleur& c)
{
	int r,g,b;
	
	cout << "Rouge: ";
		s>>r;
		
	cout << "Vert: ";
		s>>g;
	
	cout << "Bleu: ";
		s>>b;
	
	c.setRouge(r);
	c.setVert(g);
	c.setBleu(b);
	
	return s;
	
}
	
	
	
void Couleur::setRouge(int r)
{
	if(r < 0 || r > 255)
		throw RGBException(r,"Composante rouge invalide");
		
	rouge = r;
}

void Couleur::setVert(int v)
{
	if(v < 0 || v > 255)
		throw RGBException(v,"Composante vert invalide");
		
	vert = v;
}

void Couleur::setBleu(int b)
{
	if(b < 0 || b > 255)
		throw RGBException(b, "Composante bleu invalide");
	bleu = b;
}

int Couleur::getRouge() const{
	return rouge;
}

int Couleur::getVert() const{
	return vert;
}

int Couleur::getBleu() const{
	return bleu;
}

void Couleur::Affiche() const{
	cout << "[R: " << getRouge() << " G: " << getVert() << " B: " << getBleu() <<"]" <<endl;
}

void Couleur::Save(ofstream & fichier) const 
{
	Couleur coultmp(*this);	
	fichier.write((char*)&coultmp,sizeof(coultmp));
}

void Couleur::Load(ifstream & fichier)
{
	Couleur coultmp;
	fichier.read((char*)&coultmp,sizeof(coultmp));
	*this = coultmp;

}
