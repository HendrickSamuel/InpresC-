#ifndef UI_H
#define UI_H
#include <iostream>
#include "Moteur.h"

class UI
{
	private :
		Moteur * moteur;
	public :
		UI(Moteur*);
		void Menu();
		void Start();
		void AfficheErreur(const char*);
};

#endif
