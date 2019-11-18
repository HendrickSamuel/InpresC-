#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>

#include "Matrice.h"
#include "Couleur.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 7 ----------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de la classe Matrice avec des int" << endl;
  cout << " 2. Tests de la classe Matrice avec des char" << endl;
  cout << " 3. Tests de la classe Matrice avec des Couleurs" << endl;
  cout << " 4. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
//*** Tests de la classe Matrice avec des int ***********************************************************
//*******************************************************************************************************
void Essai1()
{
  cout << endl << "***** (1.1) ***** Test constructeur des constructeurs + Affiche *************************" << endl;
  {
    Matrice<int> m1,m2(6,4),m3(m2),m4(5,3,10);
    m1.Affiche();
    m2.Affiche();
    m3.Affiche();
    m4.Affiche();
  }

  cout << endl << "****** (1.2) ***** Test des setters et getters ******************************************" << endl;
  {
    Matrice<int> m(5,3);
    for (int x=0 ; x<5 ; x++)
      for (int y=0 ; y<3 ; y++)
        m.setValeur(x,y,x+y);

    m.Affiche();

    cout << "Largeur = " << m.getLargeur() << endl;
    cout << "Hauteur = " << m.getHauteur() << endl;
    cout << "Valeur en (3,2) = " << m.getValeur(3,2) << endl;
  }

  cout << endl << "****** (1.3) ***** Test des operateurs *************************************************" << endl;
  Matrice<int> m2;
  {
    Matrice<int> m(5,3);
    for (int x=0 ; x<5 ; x++)
      for (int y=0 ; y<3 ; y++)
        m(x,y) = (x+y);
    m2 = m;
  }
  m2.Affiche();
}

//*******************************************************************************************************
//*** Tests de la classe Matrice avec des char **********************************************************
//*******************************************************************************************************
void Essai2()
{
  cout << endl << "***** (2.1) ***** Test constructeur des constructeurs + Affiche *************************" << endl;
  {
    Matrice<char> m1,m2(6,4),m3(m2),m4(5,3,'z');
    m1.Affiche();
    m2.Affiche();
    m3.Affiche();
    m4.Affiche();
  }

  cout << endl << "****** (2.2) ***** Test des setters et getters ******************************************" << endl;
  {
    Matrice<char> m(5,3);
    for (int x=0 ; x<5 ; x++)
      for (int y=0 ; y<3 ; y++)
        m.setValeur(x,y,'a'+x+y);

    m.Affiche();

    cout << "Largeur = " << m.getLargeur() << endl;
    cout << "Hauteur = " << m.getHauteur() << endl;
    cout << "Valeur en (3,2) = " << m.getValeur(3,2) << endl;
  }

  cout << endl << "****** (2.3) ***** Test des operateurs *************************************************" << endl;
  Matrice<char> m2;
  {
    Matrice<char> m(5,3);
    for (int x=0 ; x<5 ; x++)
      for (int y=0 ; y<3 ; y++)
        m(x,y) = ('a'+x+y);
    m2 = m;
  }
  m2.Affiche();
}

//*******************************************************************************************************
//*** Tests de la classe Matrice avec des Couleurs ******************************************************
//*******************************************************************************************************
void Essai3()
{
  cout << endl << "***** (3.1) ***** Test constructeur des constructeurs + Affiche *************************" << endl;
  {
    Matrice<Couleur> m1,m2(6,4),m3(m2),m4(5,3,Couleur::ROUGE);
    m1.Affiche();
    m2.Affiche();
    m3.Affiche();
    m4.Affiche();
  }

  cout << endl << "****** (3.2) ***** Test des setters et getters ******************************************" << endl;
  {
    Matrice<Couleur> m(5,3);
    for (int x=0 ; x<5 ; x++)
      for (int y=0 ; y<3 ; y++)
        m.setValeur(x,y,Couleur(20*x,20*y,150));

    m.Affiche();

    cout << "Largeur = " << m.getLargeur() << endl;
    cout << "Hauteur = " << m.getHauteur() << endl;
    cout << "Valeur en (3,2) = " << m.getValeur(3,2) << endl;
  }

  cout << endl << "****** (3.3) ***** Test des operateurs *************************************************" << endl;
  Matrice<Couleur> m2;
  {
    Matrice<Couleur> m(5,3);
    for (int x=0 ; x<5 ; x++)
      for (int y=0 ; y<3 ; y++)
        m(x,y) = Couleur(20*x,20*y,150);
    m2 = m;
  }
  m2.Affiche();
}

