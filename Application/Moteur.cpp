#include "Moteur.h"

int Moteur::Insere(Image *pImage){
	ImageB* pB = dynamic_cast<ImageB*>(pImage);
    if (pB != NULL)
    {
      Trace("est une ImageB");
      imagesB.insere(*pB);
      return 1;
    }
    ImageNG* pNG = dynamic_cast<ImageNG*>(pImage);
    if (pNG != NULL) 
    {
      Trace("est une ImageNG");
      imagesNG.insere(*pNG);
      return 2;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pImage);
    if (pRGB != NULL) 
    {
      Trace("est une ImageRGB");
      imagesRGB.insere(*pRGB);
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
