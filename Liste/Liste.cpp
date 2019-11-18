#include "Liste.h"

template <class T> Liste<T>::Liste() : ListeBase<T>::ListeBase(){
	#ifdef DEV
	Trace("Constructeur par defaut Liste");
	#endif
}

template <class T> Liste<T>::Liste(const Liste& old): Liste<T>::ListeBase(old){
//	Cellule<T> *pt = NULL;
//	pt = old.pTete;
//	
//	while(pt != NULL)
//	{
//		insere(pt->valeur);
//		pt = pt->suivant;
//	}
}

template <class T>Liste<T>::~Liste(){

}

template <class T> void Liste<T>::insere(const T & val){
	#ifdef DEV
	TraceMethode("Inserer Liste");
	#endif
	//Liste<T>::Affiche();
	Cellule<T> *pt = NULL;
	pt = new Cellule<T>;
	
	pt->valeur = val;
	pt->suivant = NULL;
	
	
	if(this->estVide())
	{
		#ifdef DEVPLUS
		Trace("est vide");
		#endif
		this->setpTete(pt);
	}
	else
	{	
		#ifdef DEVPLUS
		Trace("est pas vide");
		#endif
		Cellule<T> *pdepl;
		pdepl = this->getpTete();
		while(pdepl->suivant != NULL)
		{
			pdepl = pdepl->suivant;
			#ifdef DEVPLUS
			Trace("on avance de 1");
			#endif
		}	
		pdepl -> suivant = pt;
	}
	
}

template class Liste<int>;
#include "Couleur.h"
template class Liste<Couleur>;
#include "ImageB.h"
template class Liste<ImageB>;
#include "ImageRGB.h"
template class Liste<ImageRGB>;
