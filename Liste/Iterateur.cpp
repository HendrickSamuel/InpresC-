#include "Iterateur.h"

template <class T> Iterateur<T>::Iterateur(ListeBase<T>& list):liste(list),pCur(list.getpTete()){

}

template <class T> Iterateur<T>::~Iterateur(){
	delete pCur;
}

template <class T> void Iterateur<T>::reset(){
	pCur = liste.getpTete();
}

template <class T> bool Iterateur<T>::end(){
	if(!pCur)
		return true;
	else
		return false;	
}

template <class T> Cellule<T>* Iterateur<T>::getpCur(){
	return pCur;
}

template <class T> T Iterateur<T>::remove(){
	T val= pCur->valeur;
	Cellule<T> *pDepl = liste.getpTete();
	Cellule<T> *pPrec = NULL;
	
	if(pCur != NULL && !liste.estVide())
	{
		#ifdef DEVPLUS
		Trace("1: %d, 2: %d et suivant: %d",pDepl,pCur,pCur->suivant);
		#endif
		
		while(pDepl != pCur && pDepl!= NULL)
		{
			pPrec = pDepl;
			pDepl = pDepl->suivant;
		}
		if(pPrec == NULL)
		{
			liste.setpTete(pCur->suivant);
		}
		else
		{
			pPrec ->suivant = pCur->suivant;
		}
		delete pCur;
		this->reset();
		return val;
	}
	else
	{
		throw BaseException("la liste est vide");
	}
}

template <class T> bool Iterateur<T>::operator++(){
	if(pCur)
	{
		pCur = pCur -> suivant;
		return true;
	}
	else
		return false;

}

template <class T> bool Iterateur<T>::operator++(int){
	return operator++();
}

template <class T> Iterateur<T>::operator T() const{
	return pCur->valeur;
}

template <class T> T& Iterateur<T>::operator&(){
	return pCur->valeur;
}

template class Iterateur<int>;
#include "Couleur.h"
template class Iterateur<Couleur>;
#include "ImageNG.h"
template class Iterateur<ImageNG>;
#include "ImageRGB.h"
template class Iterateur<ImageRGB>;
#include "ImageB.h"
template class Iterateur<ImageB>;




