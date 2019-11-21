#ifndef TRAITEMENTS_H
#define TRAITEMENTS_H

#include "ImageNG.h"
#include "ImageB.h"
#include "ImageRGB.h"
#include <stdlib.h>
#include "Ecran.h"
#include "Pixel.h"
#include "Iterateur.h"
#include "ListeTriee.h"

	class Traitements
	{
		private:
		public:
			static ImageB Seuillage(const ImageNG&,int);
			static ImageNG FiltreMoyenneur(const ImageNG&, int, Pixel p1=Pixel(), Pixel p2=Pixel());
			static ImageRGB FiltreMoyenneur(const ImageRGB&, int, Pixel p1=Pixel(), Pixel p2=Pixel());
			static ImageNG FiltreMedian(const ImageNG&, int);
			static ImageNG Erosion(const ImageNG&, int);
			static ImageNG Dilatation(const ImageNG&, int);
			static ImageNG Negatif(const ImageNG&);
	};

#endif
