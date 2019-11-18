#include "ListeTriee.h"

template <class T> ListeTriee<T>::ListeTriee(): ListeBase<T>::ListeBase(){
	#ifdef DEV
	Trace("Constructeur par defaut ListeTriee");
	#endif
}

template <class T> ListeTriee<T>::ListeTriee(const ListeTriee& old): ListeBase<T>::ListeBase(old){

}

template <class T>ListeTriee<T>::~ListeTriee(){

}

template <class T> void ListeTriee<T>::insere(const T & val){
	#ifdef DEV
	TraceMethode("Inserer ListeTriee");
	#endif
	Cellule<T> *pt = NULL;
	pt = new Cellule<T>;
	
	pt->valeur = val;
	
	
	if(this->estVide())
	{
		#ifdef DEVPLUS
		Trace("est vide");
		#endif
		pt->suivant = NULL;
		this->setpTete(pt);
	}
	else
	{
		#ifdef DEVPLUS
		Trace("est pas vide");
		#endif
		Cellule<T> *pdepl = this->getpTete();
		Cellule<T> *pprec = NULL; 
		while(pdepl != NULL && pdepl->valeur < val)
		{
			pprec = pdepl;
			pdepl = pdepl->suivant;
			#ifdef DEVPLUS
			Trace("on avance de 1");
			#endif
		}	
		if(pdepl == this->getpTete())
		{
			pt->suivant = this->getpTete();
			this->setpTete(pt);
		}
		else
		{	
			pt->suivant = pdepl;
			pprec->suivant = pt;
		}
	}
	
}

template class ListeTriee<int>;
#include "ImageNG.h"
template class ListeTriee<ImageNG>;
