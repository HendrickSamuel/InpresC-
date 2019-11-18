#ifndef IMAGENG_H
#define IMAGENG_H
using namespace std;

#include <string.h>
#include "Dimension.h"
#include "WindowSDL.h"
#include "WindowSDLimage.h"
#include "PixelNG.h"
#include "Image.h"
#include "RGBException.h"
#include "XYException.h"
#include "Matrice.h"

class ImageNG: public Image
{
	private: 
		Matrice<int> matrice;
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
		ImageNG operator+(int);
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
		friend ImageNG operator+(int,const ImageNG&);
		friend ostream& operator <<(ostream&,const ImageNG&);
		
				
		void setPixel(int,int,int); 
		void setBackground(int); 
		static void setComparaison(int);
		void setDimension(const Dimension&);
		

		int getPixel(int, int) const;
		int getLuminance() const;
		int getMinimum() const; 
		int getMaximum() const; 
		float getContraste() const;
		static int getComparaison();
		
		
		void Affiche() const;
		void Dessine() const;		
		void importFromBMP(const char*);
		void exportToBMP(const char*);

		void Save(ofstream &) const; 
		void Load(ifstream &);	
		
		
		
		

		
		
		
};

#endif

