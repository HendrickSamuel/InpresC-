#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"

#include "Couleur.h"
#include "ImageNG.h"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
void Essai8();

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
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      case 7 : Essai7(); break;
      case 8 : Essai8(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 9 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template Liste avec des entiers" << endl;
  cout << " 2. Test du template Liste avec des objets de la classe Couleur" << endl;
  cout << " 3. Test du template ListeTriee avec des entiers" << endl;
  cout << " 4. Test du template ListeTriee avec des objets de la classe ImageNG" << endl;
  cout << " 5. Test de l'iterateur avec une Liste d'entiers" << endl;
  cout << " 6. Test de l'iterateur avec une Liste de Couleurs" << endl;
  cout << " 7. Test de l'iterateur avec une Liste triee d'entiers" << endl;
  cout << " 8. Test de l'iterateur avec une Liste triee de ImageNG" << endl;
  cout << " 9. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
void Essai1()
{
  cout << "----- 1. Test du template Liste avec des entiers --------------------------------------------" << endl;
  cout << "----- 1.1 Creation et gestion d'une Liste ---------------------------------------------------" << endl;

  Liste<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "Liste Vide ? " << liste.estVide() << endl;
  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  cout << "Liste Vide ? " << liste.estVide() << endl;
  liste.Affiche();                                       // --> (3 -2 5 -1 0)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;

  cout << "----- 1.2 Test du constructeur de copie -----------------------------------------------------" << endl;
  {
    Liste<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.Affiche();
    cout << "----> On insere 50 dans la copie :" << endl; 
    liste2.insere(50);
    liste2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;

  cout << "----- 1.3 Test de l'operateur = -------------------------------------------------------------" << endl;
  {
    Liste<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.Affiche();
    cout << "----> On insere 100 dans la nouvelle liste :" << endl; 
    liste3.insere(100);
    liste3.Affiche();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;
}

//*********************************************************************************************
void Essai2()
{
  cout << "----- 2. Test du template Liste avec des objets de la classe Couleur --------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Couleur> liste;
  liste.Affiche();                                    
  cout << endl;

  cout << "On insere (127,0,255)..." << endl;
  liste.insere(Couleur(127,0,255));
  liste.Affiche();

  cout << "On insere le Rouge..." << endl;
  liste.insere(Couleur::ROUGE);
  liste.Affiche();

  cout << "On insere (25,67,45)..." << endl;
  Couleur *ptr = new Couleur(25,67,45);
  liste.insere(*ptr);
  delete ptr;
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl << endl;

  cout << endl;
}

//*******************************************************************************************************
void Essai3()
{
  cout << "----- 3. Test du template ListeTriee avec des entiers ------------------------" << endl;
  cout << "----- 3.1 Creation et gestion d'une Liste triee ------------------------------" << endl;
  ListeTriee<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "On insere 3,-2,5,-1,0 et -8..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  liste.insere(-8);
  liste.Affiche();                                       // --> (-8 -2 -1 0 3 5)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;

  cout << "----- 1.2 Test du constructeur de copie ----------------------------------" << endl;
  {
    ListeTriee<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.Affiche();
    cout << "----> On insere 4 dans la copie :" << endl; 
    liste2.insere(4);
    liste2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;

  cout << "----- 1.3 Test de l'operateur = -------------------------------------------" << endl;
  {
    ListeTriee<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.Affiche();
    cout << "----> On insere 6 dans la nouvelle liste :" << endl; 
    liste3.insere(6);
    liste3.Affiche();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;
}

//*******************************************************************************************************
void Essai4()
{
  cout << "----- 4. Test du template ListeTriee avec des objets de la classe ImageNG -------------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeTriee<ImageNG> liste;
  liste.Affiche();                                       
  cout << endl;

  ImageNG::setComparaison(ImageNG::LUMINANCE);

  cout << "On insere quelques images..." << endl;
  ImageNG im(1,"Test",Dimension(255,255));
  im.setBackground(128);
  liste.insere(im);
  liste.insere(im + 80);
  liste.insere(im - 50);
  liste.insere(im + 30);
  liste.insere(im - 10);
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai5()
{
  cout << "----- 5. Test de l'iterateur avec une Liste d'entiers ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<int> liste;
  Iterateur<int> it(liste);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On modifie le 3eme element de la liste (5 --> 20)..." << endl;
  it.reset();  // on est sur 3
  it++;        // on est sur -2
  it++;        // on est sur 5;
  &it = 20;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;

  cout << "On supprime le 2eme element de la liste (-2)..." << endl;
  it.reset();
  it++;        // on est sur -2
  int valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

//*******************************************************************************************************
void Essai6()
{
  cout << "----- 6. Test de l'iterateur avec une Liste de Couleur --------------------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Couleur> liste;
  Iterateur<Couleur> it(liste);

  cout << "On insere quelques couleurs..." << endl;
  liste.insere(Couleur(128,128,128));
  liste.insere(Couleur::VERT);
  liste.insere(Couleur::ROUGE);

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Couleur)it << endl;
  cout << endl;

  cout << "On modifie le 3eme element de la liste (--> BLEU)..." << endl;
  it.reset();  // on est sur Gris
  it++;        // on est sur VERT
  it++;        // on est sur ROUGE
  &it = Couleur::BLEU;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;

  cout << "On supprime le 1er element de la liste (\"Gris\")..." << endl;
  it.reset();        // on est sur Gris
  Couleur valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

//*******************************************************************************************************
void Essai7()
{
  cout << "----- 7. Test de l'iterateur avec une Liste triee d'entiers ------------------------" << endl;
  cout << "Creation  d'une ListeTriee..." << endl;
  ListeTriee<int> liste;
  Iterateur<int> it(liste);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a l'iterateur..." << endl; // --> (-2 -1 0 3 5)
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On supprime le 2eme element de la liste (-1)..." << endl;
  it.reset();  // on est sur -2
  it++;        // on est sur -1
  int valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

//*******************************************************************************************************
void Essai8()
{
  cout << "----- 8. Test de l'iterateur avec une Liste triee de ImageNG -------------------------------" << endl;
  cout << "Creation  d'une ListeTriee..." << endl;
  ListeTriee<ImageNG> liste;
  Iterateur<ImageNG> it(liste);

  ImageNG::setComparaison(ImageNG::LUMINANCE);

  cout << "On insere quelques images..." << endl;
  ImageNG im(1,"Test",Dimension(255,255));
  im.setBackground(128);
  liste.insere(im);
  liste.insere(im + 80);
  liste.insere(im - 50);
  liste.insere(im + 30);
  liste.insere(im - 10);

  cout << "On affiche et dessine grace a l'iterateur..." << endl; 
  for (it.reset() ; !it.end() ; it++)
  {
    cout << " " << (ImageNG)it << endl;
    ((ImageNG)it).Dessine();
  }
  cout << endl;

  cout << "On supprime le 2eme element de la liste..." << endl;
  it.reset();  
  it++;        
  ImageNG valeurRetiree = it.remove();
  it.remove();
  it.remove();
  it.remove();
  it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

