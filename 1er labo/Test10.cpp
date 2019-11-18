#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "ImageNG.h"
#include "ImageB.h"
#include "Traitements.h"
#include "BaseException.h"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
/*void Essai8();
*/
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
/*      case 8 : Essai8(); break;*/
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
  cout << " 1. Test du Seuillage d'une ImageNG" << endl;
  cout << " 2. Test du filtre moyenneur sur une ImageNG" << endl;
  cout << " 3. Test du filtre median sur une ImageNG" << endl;
  cout << " 4. Test de l'erosion sur une ImageNG" << endl;
  cout << " 5. Test de la dilatation sur une ImageNG" << endl;
  cout << " 6. Essai de detection de contours sur une ImageNG" << endl;
  cout << " 7. Test du negatif sur une ImageNG" << endl;
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
  cout << "***** 1. Test du Seuillage d'une ImageNG *****************************************************" << endl;

  ImageNG image("../images/joconde.bmp");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  int seuil;
  cout << "Seuil = ";
  cin >> seuil;
  cin.ignore();

  ImageB imageSeuillee;
  imageSeuillee = Traitements::Seuillage(image,seuil);

  cout << "Voici l'image seuillee : " << imageSeuillee << endl; imageSeuillee.Dessine();
}

//*******************************************************************************************************
void Essai2()
{
  cout << "***** 2. Test du filtre moyenneur sur une ImageNG ********************************************" << endl;

  ImageNG image("../images/lena.bmp");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  ImageNG imageFiltree;
  imageFiltree = Traitements::FiltreMoyenneur(image,17,Pixel(100,100),Pixel(200,200));

  cout << "Voici l'image filtree : " << imageFiltree << endl; imageFiltree.Dessine();

  ImageNG image2("../images/mandrill.bmp");
  cout << "Voici l'image de départ : " << image << endl; image2.Dessine();

  ImageNG imageFiltree2;
  imageFiltree2 = Traitements::FiltreMoyenneur(image2,7);

  cout << "Voici l'image filtree : " << imageFiltree2 << endl; imageFiltree2.Dessine();
}

//*******************************************************************************************************
void Essai3()
{
  cout << "***** 3. Test du filtre median sur une ImageNG ********************************************" << endl;
	try{
  ImageNG image("../images/house.bmp");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  int taille;
  cout << "Taille du filtre = ";
  cin >> taille;
  cin.ignore();

  ImageNG imageFiltree;
  imageFiltree = Traitements::FiltreMedian(image,taille);
  
  
  cout << "Voici l'image filtree : " << imageFiltree << endl; imageFiltree.Dessine();
	}
	catch(BaseException e)
	{
	 cout << e.getMessage() << endl;
	}
}

//*******************************************************************************************************
void Essai4()
{
  cout << "***** 4. Test de l'erosion sur une ImageNG ********************************************" << endl;

  ImageNG image("../images/lena.bmp");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  int taille;
  cout << "Taille du filtre = ";
  cin >> taille;
  cin.ignore();

  ImageNG imageFiltree;
  imageFiltree = Traitements::Erosion(image,taille);

  cout << "Voici l'image erodee : " << imageFiltree << endl; imageFiltree.Dessine();
}

//*******************************************************************************************************
void Essai5()
{
  cout << "***** 5. Test de la dilatation sur une ImageNG ********************************************" << endl;

  ImageNG image("../images/lena.bmp");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  int taille;
  cout << "Taille du filtre = ";
  cin >> taille;
  cin.ignore();

  ImageNG imageFiltree;
  imageFiltree = Traitements::Dilatation(image,taille);

  cout << "Voici l'image dilatee : " << imageFiltree << endl; imageFiltree.Dessine();
}

//*******************************************************************************************************
void Essai6()
{
  cout << "***** 6. Essai de detection de contours sur une ImageNG ************************************" << endl;

  ImageNG image("../images/joconde.bmp");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  ImageNG imageResultat;
  imageResultat = Traitements::Dilatation(image,3) - Traitements::Erosion(image,3);

  cout << "Voici l'image contours : " << imageResultat << endl; imageResultat.Dessine();
}

//*******************************************************************************************************
void Essai7()
{
  cout << "***** 7. Test du negatif sur une ImageNG ************************************" << endl;

  ImageNG image("../images/bulles.bmp");
  cout << "Voici l'image de départ : " << image << endl; image.Dessine();

  ImageNG negatif;
  negatif = Traitements::Negatif(image);

  cout << "Voici l'image negatif : " << negatif << endl; negatif.Dessine();
}

