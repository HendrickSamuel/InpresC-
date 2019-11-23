#ifndef IMAGERGB_H
#define IMAGERGB_H
using namespace std;

#include <string.h>
#include "Dimension.h"
#include "WindowSDL.h"
#include "WindowSDLimage.h"
#include "PixelRGB.h"
#include "Image.h"
#include "Couleur.h"
#include "XYException.h"
#include "Matrice.h"
#include "ImageNG.h"

class ImageRGB: public Image
{
	private: 
		Matrice<Couleur> matrice;


	public:
		
		ImageRGB();
		ImageRGB(int, const char* );
		ImageRGB(const char* );
		ImageRGB(const ImageRGB&);
		ImageRGB(int, const char*, const Dimension&);
		~ImageRGB();
		
		const ImageRGB& operator=(const ImageRGB&);
		ImageRGB operator+(const PixelRGB&);
		friend ImageRGB operator+(const PixelRGB&,ImageRGB&);
		friend ostream& operator <<(ostream&,const ImageRGB&);
		
				
		void setPixel(int,int,const Couleur&); 
		void setBackground(const Couleur&); 
		void setDimension(const Dimension&);
		

		const Couleur getPixel(int, int) const;

		
		void Affiche() const;
		void Dessine() const;		
		void Dessine(int,int) const;
		void importFromBMP(const char*);
		void exportToBMP(const char*);
		
		ImageNG getRouge() const;
		ImageNG getVert() const;
		ImageNG getBleu() const;
		void setRGB(const ImageNG &r, const ImageNG &g, const ImageNG& b);

		
		void Save(ofstream &) const; 
		void Load(ifstream &);	
		
		
		

		
		
		
};

#endif

