#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
#include "ImageNG.h"
#include "PixelNG.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
void Essai8();
void Essai9();
void Essai10();
void Essai11();
void Essai12();
void Essai13();

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
      case 9 : Essai9(); break;
      case 10 : Essai10(); break;
      case 11 : Essai11(); break;
      case 12 : Essai12(); break;
      case 13 : Essai13(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

//******************************************************************************************************
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 4 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests des parametres d'une ImageNG" << endl;
  cout << " 2. Tests de l'operateur = de la classe ImageNG" << endl;
  cout << " 3. Tests des operateurs << et >> de la classe Dimension" << endl;
  cout << " 4. Tests de l'operateur << de ImageNG" << endl;
  cout << " 5. Tests des operateurs (+ int) de la classe ImageNG" << endl;
  cout << " 6. Tests de l'operateur (- int) de la classe ImageNG" << endl;
  cout << " 7. Test des operateurs ++ de la classe ImageNG" << endl;
  cout << " 8. Test des operateurs -- de la classe ImageNG" << endl;
  cout << " 9. Tests de la classe PixelNG" << endl;
  cout << " 10. Tests des operateurs (+ PixelNG) de la classe ImageNG" << endl;
  cout << " 11. Test des operateurs == et != de la classe Dimension" << endl;
  cout << " 12. Tests de l'operateur (- ImageNG) de la classe ImageNG" << endl;
  cout << " 13. Test des operateurs < > et == de la classe ImageNG" << endl;
  cout << " 14. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
//*** Tests de l'operateur = de la classe Couleur *******************************************************
//*******************************************************************************************************
void Essai1()
{ 
  cout << "********************************************************************" << endl;
  cout << "(1) ***** Tests des parametres d'une image *************************" << endl;
  cout << "********************************************************************" << endl;

  ImageNG im("../images/lena.bmp");
  im.Affiche();
  cout << "Luminance = " << im.getLuminance() << endl;
  cout << "Minimum   = " << im.getMinimum() << endl;
  cout << "Maximum   = " << im.getMaximum() << endl;
  cout << "Contraste = " << im.getContraste() << endl;
  im.Dessine();
}

//*******************************************************************************************************
//*** Tests de l'operateur = de la classe ImageNG *******************************************************
//*******************************************************************************************************
void Essai2()
{ 
  cout << "********************************************************************" << endl;
  cout << "(2) ***** Test de l'operateur d'affectation de ImageNG *************" << endl;
  cout << "********************************************************************" << endl;
  {
    ImageNG i;
    {
      ImageNG i1("../images/bulles.bmp");  // Ajout d'un nouveau constructeur !!! --> a faire
      cout << "Voici i1 : "; i1.Affiche(); i1.Dessine(); 

      cout << endl << ">>>>> i = i1;" << endl;
      i = i1;
      cout << ">>>>> Destruction de i1" << endl << endl;
    }
    cout << "Voici i : "; i.Affiche(); i.Dessine();

    cout << endl << ">>>>> i2 = i3 = ImageNG(1,\"essai\",Dimension(400,200));" << endl;
    ImageNG i2,i3;
    i2 = i3 = ImageNG(1,"essai",Dimension(400,200));
    cout << "Voici i2 : "; i2.Affiche(); i2.Dessine();
    cout << "Voici i3 : "; i3.Affiche(); i3.Dessine();
  }
}

//*******************************************************************************************************
//*** Tests des operateurs << et >> de la classe Dimension **********************************************
//*******************************************************************************************************
void Essai3()
{
  cout << "**************************************************************************" << endl;
  cout << "(3) ********* Tests des operateurs << et >> de Dimension *****************" << endl;
  cout << "**************************************************************************" << endl;
  Dimension d1(Dimension::HD);
  cout << "d1 = " << d1 << endl;
  cout << "Nouvelle valeur pour d1 = " << endl;
  cin >> d1;
  cout << d1 << endl << endl;
}

//*******************************************************************************************************
//*** Tests de l'operateur << de la classe ImageNG ******************************************************
//*******************************************************************************************************
void Essai4()
{
  cout << "**************************************************************************" << endl;
  cout << "(4) ********* Tests de l'operateur << de ImageNG *************************" << endl;
  cout << "**************************************************************************" << endl;
  ImageNG i1("../images/lena.bmp");
  cout << "ImageNG chargee = " << i1 << endl;
  i1.Dessine();
}

//*******************************************************************************************************
//*** Tests des operateurs (+ int) de la classe ImageNG *************************************************
//*******************************************************************************************************
void Essai5()
{
  cout << "****************************************************************************************" << endl;
  cout << "(5) ********* Tests des operateurs (+ int) de la classe ImageNG ************************" << endl;
  cout << "****************************************************************************************" << endl;

  cout << endl << "***** Tests de ImageNG + int ***************************************************" << endl;
  ImageNG i1("../images/boat.bmp"), i2;
  cout << "Avant :" << endl;
  cout << "i1 = " << i1 << endl; i1.Dessine();
  i2 = i1 + 40;
  cout << "i2 = i1 + 40 = " << i2 << endl; i2.Dessine();
  cout << "Apres :" << endl;
  cout << "i1 = " << i1 << endl; i1.Dessine();

  cout << endl << "***** Tests de int + ImageNG **************************************************" << endl;
  ImageNG i3("../images/lena.bmp"), i4;
  cout << "Avant :" << endl;
  cout << "i3 = " << i3 << endl; i3.Dessine();
  i4 = 50 + i3;
  cout << "i4 = 50 + i3 = " << i4 << endl; i4.Dessine();
  cout << "Apres :" << endl;
  cout << "i3 = " << i3 << endl; i3.Dessine(); 
}

//*******************************************************************************************************
//*** Tests des operateurs (- int) de la classe ImageNG *************************************************
//*******************************************************************************************************
void Essai6()
{
  cout << "****************************************************************************************" << endl;
  cout << "(6) ********* Tests de l'operateur (- int) de la classe ImageNG ************************" << endl;
  cout << "****************************************************************************************" << endl;

  cout << endl << "***** Tests de ImageNG - int ***************************************************" << endl;
  ImageNG i1("../images/boat.bmp"), i2;
  cout << "Avant :" << endl;
  cout << "i1 = " << i1 << endl; i1.Dessine();
  i2 = i1 - 60;
  cout << "i2 = i1 - 60 = " << i2 << endl; i2.Dessine();
  cout << "Apres :" << endl;
  cout << "i1 = " << i1 << endl; i1.Dessine();
}

//*******************************************************************************************************
//*** Tests des operateurs ++ de la classe ImageNG ******************************************************
//*******************************************************************************************************
void Essai7()
{
  cout << "****************************************************************************************" << endl;
  cout << "(7) ********* Test des operateurs ++ de la classe ImageNG ******************************" << endl;
  cout << "****************************************************************************************" << endl;

  ImageNG i(1,"essai++",Dimension(400,200));
  cout << endl << "***** Test de l'operateur de pre-incrementation **********************" << endl;
  cout << "i   : " << i << endl;
  cout << "++i : " << ++i << endl;  // Si tout va bien, i est incremente avant d'etre affichee !
  cout << "i   : " << i << endl << endl;

  cout << "***** Test de l'operateur de post-incrementation *********************" << endl;
  cout << "i   : " << i << endl;
  cout << "i++ : " << i++ << endl;  // Si tout va bien, i est incremente apres avoir ete affichee !
  cout << "i   : " << i << endl << endl;

  cout << "***** Test visuel ++ *************************************************" << endl;
  i = ImageNG("../images/boat.bmp");
  	for (int x=0 ; x<8 ; x++,i++) i.Dessine();
}

//*******************************************************************************************************
//*** Tests des operateurs -- de la classe ImageNG ******************************************************
//*******************************************************************************************************
void Essai8()
{
  cout << "****************************************************************************************" << endl;
  cout << "(8) ********* Test des operateurs -- de la classe ImageNG ******************************" << endl;
  cout << "****************************************************************************************" << endl;

  ImageNG i(1,"essai--",Dimension(400,200));
  i.setBackground(210);
  cout << endl << "***** Test de l'operateur de pre-decrementation **********************" << endl;
  cout << "i   : " << i << endl;
  cout << "--i : " << --i << endl;  // Si tout va bien, i est decremente avant d'etre affichee !
  cout << "i   : " << i << endl << endl;

  cout << "***** Test de l'operateur de post-decrementation *********************" << endl;
  cout << "i   : " << i << endl;
  cout << "i-- : " << i-- << endl;  // Si tout va bien, i est decremente apres avoir ete affichee !
  cout << "i   : " << i << endl << endl;

  cout << "***** Test visuel ++ *************************************************" << endl;
  i = ImageNG("../images/boat.bmp");
  for (int x=0 ; x<8 ; x++,i--) i.Dessine();
}

//*******************************************************************************************************
//*** Tests de la classe PixelNG ************************************************************************
//*******************************************************************************************************
void Essai9()
{
  cout << "****************************************************************************************" << endl;
  cout << "(9) ********* Tests de la classe PixelNG ***********************************************" << endl;
  cout << "****************************************************************************************" << endl;

  PixelNG p1,p2(10,30,155),p3(p2);
  p1.setX(50);
  p1.setY(60);
  p1.setValeur(255);
  cout << p1 << endl << p2 << endl << p3 << endl;
  cout << "x = " << p3.getX() << endl;
  cout << "y = " << p3.getY() << endl;
  cout << "valeur = " << p3.getValeur() << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs (+ PixelNG) de la classe ImageNG *********************************************
//*******************************************************************************************************
void Essai10()
{
  cout << "****************************************************************************************" << endl;
  cout << "(10) ********* Tests des operateurs (+ PixelNG) de la classe ImageNG *******************" << endl;
  cout << "****************************************************************************************" << endl;

  cout << endl << "***** Tests de ImageNG + PixelNG ***********************************************" << endl;
  ImageNG i1(1,"tout noir",Dimension(256,256)), i2;
  cout << "Avant :" << endl;
  cout << "Voici i1 = " << i1 << endl; i1.Dessine();
  cout << "i2 = i1 + PixelNG(128,128,255);" << endl;
  i2 = i1 + PixelNG(128,128,255);
  // Pour le fun :)
  cout << "On ajoute un cercle a i2..." << endl;
  for (int i=0 ; i< 50 ; i++)
  {
    int x = (int)(128 + 60 * cos(2*3.1416*i/50));
    int y = (int)(128 + 60 * sin(2*3.1416*i/50));
    PixelNG p(x,y,150);
    i2 = i2 + p;
  }
  cout << "Voici i2 : " << i2 << endl; i2.Dessine();
  cout << "Apres :" << endl;
  cout << "Re-voici i1 = " << i1 << endl; i1.Dessine();

  cout << endl << "***** Tests de PixelNG + ImageNG ********************************************" << endl;
  ImageNG i3;
  cout << "Avant :" << endl;
  cout << "Voici i2 = " << i2 << endl; i2.Dessine();
  i3 = PixelNG(100,100,255) + i2;
  cout << "i3 = PixelNG(100,100,255) + i2;" << endl; 
  cout << "Voici i3 = " << i3 << endl; i3.Dessine();
  cout << "Apres :" << endl;
  cout << "Re-voici i2 = " << i2 << endl; i2.Dessine();
}

//*******************************************************************************************************
//*** Test des operateurs == et != de la classe Dimension ***********************************************
//*******************************************************************************************************
void Essai11()
{
  cout << "****************************************************************************************" << endl;
  cout << "(11) ********* Test des operateurs == et != de la classe Dimension *********************" << endl;
  cout << "****************************************************************************************" << endl;

  Dimension d1, d2;
  cout << "Encodez une dimension d1 :" << endl;
  cin >> d1;
  cout << "Encodez une dimension d2 :" << endl;
  cin >> d2;
  if (d1 == d2) cout << "--> d1 est egale a d2";
  if (d1 != d2) cout << "--> d1 n'est pas egale a d2";
  cout << endl << endl;
}

//*******************************************************************************************************
//*** Tests de l'operateur (- ImageNG) de la classe ImageNG *********************************************
//*******************************************************************************************************
void Essai12()
{
  cout << "****************************************************************************************" << endl;
  cout << "(12) ********* Tests de l'operateur (- ImageNG) de la classe ImageNG *******************" << endl;
  cout << "****************************************************************************************" << endl;

  ImageNG i1("../images/imageBinaire1.bmp"),i2("../images/imageBinaire2.bmp"),i3;
  cout << "Avant :" << endl;
  cout << "i1 = " << i1 << endl; i1.Dessine();
  cout << "i2 = " << i2 << endl; i2.Dessine();
  i3 = i1 - i2;
  cout << "i3 = i1 - i2 = " << i3 << endl; i3.Dessine();
  cout << "Apres :" << endl;
  cout << "i1 = " << i1 << endl; i1.Dessine();																								
  cout << "i2 = " << i2 << endl; i2.Dessine();
}

//*******************************************************************************************************
//*** Tests des operateurs < > et == de la classe ImageNG ***********************************************
//*******************************************************************************************************
void Essai13()
{
  cout << "****************************************************************************************" << endl;
  cout << "(13) ********* Test des operateurs < > et == de la classe ImageNG **********************" << endl;
  cout << "****************************************************************************************" << endl;

  ImageNG i1("../images/lena.bmp"), i2("../images/boat.bmp");
  cout << "Voici i1 : " << i1 << endl; i1.Dessine();
  cout << "Voici i2 : " << i2 << endl; i2.Dessine();
  
  cout << "Comparaison selon la luminance :" << endl;
  ImageNG::setComparaison(ImageNG::LUMINANCE);
  if (i1 == i2) cout << "--> i1 == i2";
  else if (i1 < i2) cout << "--> i1 < i2";
  else if (i1 > i2) cout << "--> i1 > i2";
  else cout << "aucun des 3...";
  cout << endl << endl;

  cout << "Comparaison pixel a pixel :" << endl;
  ImageNG::setComparaison(ImageNG::PIXEL_A_PIXEL);
  if (i1 == i2) cout << "--> i1 == i2";
  else if (i1 < i2) cout << "--> i1 < i2";
  else if (i1 > i2) cout << "--> i1 > i2";
  else cout << "aucun des 3...";
  cout << endl << endl;
}

