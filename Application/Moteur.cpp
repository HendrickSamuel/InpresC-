#include "Moteur.h"

/* ------------------------- Methodes privees --------------------------*/
int Moteur::Insere(Image *pImage){
	ImageB* pB = dynamic_cast<ImageB*>(pImage);
    if (pB != NULL)
    {
      Trace("est une ImageB");
      imagesB.insere(*pB);
      pB-> Dessine();
      return 1;
    }
    ImageNG* pNG = dynamic_cast<ImageNG*>(pImage);
    if (pNG != NULL) 
    {
      Trace("est une ImageNG");
      imagesNG.insere(*pNG);
      pNG->Dessine();
      return 2;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pImage);
    if (pRGB != NULL) 
    {
      Trace("est une ImageRGB");
      imagesRGB.insere(*pRGB);
      pRGB->Dessine();
      return 3;
    }	
    return 0;
}

ImageNG Moteur::GetImageNG(int id) throw(MoteurException){
	ListeTriee<ImageNG> lis(imagesNG);
	Iterateur<ImageNG> it(lis);
	ImageNG img = it.remove();
	
	while(!it.end() && img.getId() != id)
	{
		img = it.remove();
	}
	
	if(img.getId() == id) 
		return img;
	else
		throw(MoteurException("l'image NG n'a pas ete trouvee"));
}

Image* Moteur::GetImage(int id) throw(MoteurException){
	Liste<ImageRGB> lis(imagesRGB);
	Iterateur<ImageRGB> it(lis);
	
	while(!it.end() && it.getpCur()->valeur.getId() != id)
	{
		it++;
	}
	
	if(!it.end())
		return &(it.getpCur()->valeur);
	else
		throw(MoteurException("l'image n'a pas ete trouvee'"));
}

/*----------------- Methodes publiques ------------------------*/

void Moteur::Affiche() const{
	cout << "--ImagesNG------------------------------"<<endl;
	imagesNG.Affiche();
	cout << "--ImagesRGB-----------------------------"<<endl;
	imagesRGB.Affiche();
	cout << "--ImagesB-------------------------------"<<endl;
	imagesB.Affiche();
	cout << endl << endl;
}

void Moteur::SupprimeImage(int id){
	TraceMethode("on demande le remove");
	
	Iterateur<ImageNG> it1(imagesNG);
	while(!it1.end() && it1.getpCur()->valeur.getId() != id)
	{
		it1++;
	}
	
	
	if(!it1.end())
	{
		it1.remove();
	}
	else
	{
		Iterateur<ImageRGB> it2(imagesRGB);
		while(!it2.end() && it2.getpCur()->valeur.getId() != id)
			{
				it2++;
			}
			if(!it2.end())
			{
				it2.remove();
				it2.reset();
			}
			else
			{
				Iterateur<ImageB> it3(imagesB);
				while(!it3.end() && it3.getpCur()->valeur.getId() != id)
					{
						it3++;
					}
					if(!it3.end())
					{
						it3.remove();
						it3.reset();
					}
					else
						throw(MoteurException("l'id a supprimer n'existe pas"));
			}
	}
		
}
