#ifndef ImageB_H
#define ImageB_H
using namespace std;

#include <string.h>
#include "Dimension.h"
#include "WindowSDL.h"
#include "WindowSDLimage.h"
#include "PixelB.h"
#include "Image.h"
#include "Couleur.h"
#include "XYException.h"
#include "Matrice.h"

class ImageB: public Image
{
	private: 
		Matrice<bool> matrice;
		

	public:	
		static Couleur couleurTrue;
		static Couleur couleurFalse;
 
		ImageB();
		ImageB(int, const char* );	
		ImageB(const ImageB&);
		ImageB(int, const char*, const Dimension&);
		~ImageB();
		
		const ImageB& operator=(const ImageB&);
		ImageB operator+(const PixelB&);
		friend ImageB operator+(const PixelB&,ImageB&);
		friend ostream& operator <<(ostream&,const ImageB&);
		
				
		void setPixel(int,int,bool); 
		void setBackground(bool);
		void setDimension(const Dimension&);
		

		bool getPixel(int, int) const;
		
		
		void Affiche() const;
		void Dessine() const;		
		void Dessine(int,int) const;
		void exportToBMP(const char*);
		
		void Save(ofstream &) const; 
		void Load(ifstream &);	
		
		
		
		
		

		
		
		
};

#endif

