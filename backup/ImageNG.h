#ifndef IMAGENG_H
#define IMAGENG_H
using namespace std;

#include <string.h>
#include "Dimension.h"
#include "WindowSDL.h"
#include "WindowSDLimage.h"
#include "PixelNG.h"

class ImageNG
{
	private: 
		int id;
		char* nom;
		Dimension dimension;
		int** matrice;
		static int comparaison;
		

	public:
		static const int LUMINANCE;
		static const int PIXEL_A_PIXEL;
 
		ImageNG();
		ImageNG(int, const char* );
		ImageNG(const char* );
		ImageNG(const ImageNG&);
		ImageNG(int, const char*, const Dimension&);
		~ImageNG();
		
		const ImageNG& operator=(const ImageNG&);
		friend ImageNG operator+(ImageNG&,int);
		ImageNG operator-(int);
		ImageNG operator-(const ImageNG&);
		const ImageNG& operator++();
		ImageNG operator++(int);
		const ImageNG& operator--();
		ImageNG operator--(int);
		ImageNG operator+(const PixelNG&);
		bool operator<(const ImageNG&);
		bool operator>(const ImageNG&);
		bool operator==(const ImageNG&);
		friend ImageNG operator+(const PixelNG&,ImageNG&);
		friend ImageNG operator+(int, ImageNG&);
		friend ostream& operator <<(ostream&,const ImageNG&);
		
				
		void setId(int);
		void setNom(const char*);
		void setDimension(const Dimension&);
		void setPixel(int,int,int); 
		void setBackground(int); 
		static void setComparaison(int);
		
		const char * getNom() const;
		int getId() const;
		const Dimension& getDimension() const;
		int getPixel(int, int) const;
		int getLuminance() const;
		int getMinimum() const; 
		int getMaximum() const; 
		float getContraste() const;
		static int getComparaison();
		
		
		void Affiche() const;
		void Dessine();		
		void importFromBMP(const char*);
		void exportToBMP(const char*);

		
		
		
		
		

		
		
		
};

#endif

