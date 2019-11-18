#ifndef MOTEUR_H
#define MOTEUR_H

#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"
#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"
#include "Image.h"
#include "MoteurException.h"

	class Moteur
	{
		private :
			ListeTriee<ImageNG> imagesNG ;
			Liste<ImageRGB> imagesRGB ;
			Liste<ImageB> imagesB ;
			
			int Insere(Image *pImage);
			ImageNG GetImageNG(int) throw(MoteurException);
			Image* GetImage(int) throw(MoteurException);
			
		
			
	//...
		public :
			
//			Moteur();
//			~Moteur();
	//...
	} ;

#endif
