#include <stdlib.h>
#include <iostream>
using namespace std;
#include "ImageNG.h"
#include "Dimension.h"
#include "Couleur.h"
#include "Liste.h"
//#include "BaseException.h"
#include "Ecran.h"
#include "WindowSDLexception.h"
#include "Matrice.h"
void ClassImageNG(const char*);
void ClassDimension(const char*);
void ClassCouleur(const char*);
void ClassListe(const char*);
void ClassListeImageNG(const char*);

int main()
{

//ClassImageNG("ImageNG : I2 = I1");
//ClassDimension("Dimension : D2 = D1");
//ClassImageNG("ImageNG : I2 = I1");
//ClassCouleur("Couleur : C2 = C1");
//ClassListe("Liste : Liste2 = Liste1");
ClassListeImageNG("ListeImageNG : Liste2 = Liste1");

exit(0);
}

//// Pour le premier test.
//void ClassImageNG(const char * Texte)
//{
//EffEcran();
//AffChaine(Texte,2,1,GRAS);
//cout <<endl;
//ImageNG	C1(10,"PremiereImage");
//Titre("I1 (avant) : ");
//C1.Affiche();
//{
//Titre("I2 : ");
//cout <<endl;
//ImageNG	C2(C1);
//C2.Affiche();
//}
//ImageNG	CImageNG;            //     Juste pour decaler la pile
//CImageNG.setNom("xxxxxxxxxxxxxxxxxxxx");

//Titre("I1 (apres): "); 
//C1.Affiche();
//Pause();
//}

void ClassDimension(const char * Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;
Dimension	D1(10,20);
Titre("D1 (avant) : ");
D1.Affiche();
{ 
Dimension	D2;
D2 = D1;
Titre("D2 :");
D2.Affiche();
}
}

void ClassCouleur(const char * Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;
Couleur	C1(100,150,200);
Titre("C1 (avant) : ");
C1.Affiche();
{ 
Couleur	C2;
C2 = C1;
Titre("C2 :");
C2.Affiche();
}

//Couleur	CBidon;                // Juste pour decaler la pile
//CBidon.setNom("xxxxxxxxxxxxxxxxxxxx");

Titre("C1 (apres) : ");
C1.Affiche();

Pause();
}

// Pour le 3eme test

void ClassImageNG(const char * Texte)
{
//Trace("debut de copie %s",Texte);
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;
Dimension	D1(250,250);
ImageNG	C1(10,"PremiereImage",D1);
C1.setBackground(125);
////for (int i = 0;i<100;i+=1) C1.setPixel(i,i,100);
Titre("I1 (avant) : ");
C1.Affiche();
try
	{
	C1.Dessine();
	}
catch(WindowSDLexception E)
	{
	cout << "aaa" << E.getMessage() << endl;
	}


{
Titre("I2 : ");
cout <<endl;
ImageNG	C2;
C2 = C1;
C2.Affiche();
C2.Dessine();
}
ImageNG	CImageNG;            //     Juste pour decaler la pile
CImageNG.setNom("xxxxxxxxxxxxxxxxxxxx");

Titre("I1 (apres): "); 
C1.Affiche();
C1.Dessine();
Pause();
}


void ClassListe(const char * Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;

Liste<int> L1;

L1.insere(20);
L1.insere(40);
L1.insere(50);

Titre("L1 (avant) : ");
L1.Affiche();
{ 
Liste<int> L2;
L2 = L1;
Titre("Liste2 :");
L2.Affiche();
}
ImageNG*	PBidon = new ImageNG();	// Juste pour decaler la pile
PBidon->setNom("Juste pour decaler la pile");
ImageNG	CImageNG;            //     Juste pour decaler la pile
CImageNG.setNom("xxxxxxxxxxxxxxxxxxxx");

Titre("Liste1 : ");
L1.Affiche();

Pause();
}

void ClassListeImageNG(const char * Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;

Liste<ImageNG> L1;
ImageNG	C1("./../images/joconde.bmp");
C1.Affiche();
C1.Dessine();
L1.insere(C1);
ImageNG	C2("./../images/bulles.bmp");
C2.Dessine();
L1.insere(C2);
ImageNG	C3("./../images/lena.bmp");
L1.insere(C3);
C3.Dessine();

Titre("L1 (avant) : ");
L1.Affiche();
{ 
Liste<ImageNG> L2;
L2 = L1;
Titre("Liste2 :");
L2.Affiche();
}
ImageNG*	PBidon = new ImageNG();	// Juste pour decaler la pile
PBidon->setNom("Juste pour decaler la pile");
ImageNG	CImageNG;            //     Juste pour decaler la pile
CImageNG.setNom("Juste pour decaler la pile");

Titre("Liste1 : ");
L1.Affiche();

Pause();
}

