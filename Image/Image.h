#ifndef IMAGE_H
#define IMAGE_H
using namespace std;

#include <string.h>
#include "Dimension.h"
#include "Ecran.h"

class Image
{
	protected: 
		int id;
		char* nom;
		Dimension dimension;		

	public:

		Image();
		Image(int, const char* );
		Image(const Image&);
		Image(int, const char*, const Dimension&);
		virtual ~Image();
				
				
		void setId(int);
		void setNom(const char*);
		void setDimension(const Dimension&);
		
		const char * getNom() const;
		int getId() const;
		const Dimension& getDimension() const;

		void Save(ofstream &) const;
		void Load(ifstream &);
		
		virtual void Affiche() const =0;
		virtual void Dessine() const =0;		
		virtual void exportToBMP(const char*) =0;

		
};

#endif

