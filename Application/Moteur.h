#ifndef MOTEUR_H
#define MOTEUR_H

#include "Image.h"
#include "ImageNG.h"
#include "ImageRGB.h"
#include "ImageB.h"

#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"

#include "MoteurException.h"
#include "WindowSDL.h"
#include "Traitements.h"

#include <string.h>
#include <stdio.h>

using namespace std;

	class Moteur
	{
		private :
			char *msgerreur;
			int Compteur;
			ofstream fichierLog;
			
			ListeTriee<ImageNG> imagesNG ;
			Liste<ImageRGB> imagesRGB ;
			Liste<ImageB> imagesB ;
			
			int Insere(Image *pImage);
			ImageNG GetImageNG(int) throw(MoteurException);
			Image* GetImage(int) throw(MoteurException);
			
		//...
		public :
			
			Moteur();
			~Moteur();
			void Start();
			void Stop();
			void setMessage(const char*);
			const char* getMessage() const;
			void Affiche() const;
			void SupprimeImage(int);
			int ImporteImageNG(const char *);
			int ImporteImageRGB(const char *);
			void VisualiseImage(int);
			void VisualiseImages(int,int);
			void ExporterBMP(int, const char*);
			int AugmenteLuminosite(int,int);
			int DiminueLuminosite(int, int);
			int Soustraire(int, int);
			
			int Seuillage(int, int);
			int Negatif(int);
			int FiltreMedian(int,int);
			int FiltreMoyenneur(int, int);
			int Dilatation(int,int);
			int Erosion(int,int);
			
			int FiltreMoyenneurSelection(int, int);
			
			void Save(ofstream &);
			void Load(ifstream &);
			
			int ImporteCSV(const char*);
} ;

#endif
