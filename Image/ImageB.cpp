#include "ImageB.h"
#include "Dimension.h"
#include "Ecran.h"
#include <string.h>
#include <iostream>

/********************************-Valeurs statiques-********************************/
	
	Couleur ImageB::couleurTrue(255,255,255);
	Couleur ImageB::couleurFalse(0,0,0);

	
/********************************-Constructeur/Destructeur-********************************/

ImageB::ImageB(): Image(), matrice(Dimension::VGA.getLargeur(), Dimension::VGA.getHauteur(),false) 
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageB par defaut");
	#endif
	setDimension(Dimension::VGA);
}

ImageB::ImageB(int idget, const char* chaineget): Image(idget,chaineget), matrice(Dimension::VGA.getLargeur(), Dimension::VGA.getHauteur(),false)
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageB par valeur double");
	#endif
	
	setDimension(Dimension::VGA);
}

ImageB::ImageB(const ImageB& old): matrice(0,0,false)
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageB par copie");
	#endif

	nom = NULL;
	setNom(old.getNom());	
	setId(old.getId());

	setDimension(old.getDimension());

	for(int i= 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur();j++)
			setPixel(i,j,old.getPixel(i,j));	
}

ImageB::ImageB(int idget, const char* chaineget,const  Dimension& olddim): Image(idget,chaineget), matrice(olddim.getLargeur(),olddim.getHauteur(),false)
{	
	#ifdef DEV
	TraceConstructeur("Constructeur ImageB par valeur complete");
	#endif
	setDimension(olddim);
}

ImageB::~ImageB()
{
	#ifdef DEV
	TraceConstructeur("Destructeur ImageB");
	#endif
}

/********************************-Operateurs-********************************/

const ImageB& ImageB::operator=(const ImageB& old)
{
	#ifdef DEV
	TraceConstructeur("Opérateur d'affectation = '");
	#endif
	
	//nom = NULL; si nom et matrice existent alors c'est ok mais sinon ??
	setNom(old.getNom());	
	setId(old.getId());
	//matrice = NULL;

	setDimension(old.getDimension());

	for(int i= 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur();j++)
			setPixel(i,j,old.getPixel(i,j));
			
	return *this;
}

ImageB ImageB::operator+(const PixelB& pixel)
{
	ImageB imgtemp(*this);
	imgtemp.setPixel(pixel.getX(),pixel.getY(),pixel.getValeur());
	return imgtemp;
}


ImageB operator+(const PixelB& pixel,ImageB& img)
{
	return img+pixel;
}

ostream& operator<<(ostream& s, const ImageB& img)
{
	s<<"id: " <<img.getId()<<" ";	
	if(img.getNom())
		s << " nom: "<< img.getNom() << " ";	
	else
		s << "pas de nom" << " ";
	s << "largeur: " << img.dimension.getLargeur() << " hauteur: " << img.dimension.getHauteur();
	s << endl;
	
	return s;
}

/********************************-Setteurs-********************************/

void ImageB::setPixel(int x,int y,bool val)
{	
	if((this->getDimension().getLargeur() < x || x < 1 )&& (this->getDimension().getHauteur() < y || y < 0) )
		throw XYException('d',"Pixel en dehors de l'image");
	if(this->getDimension().getLargeur() < x || x < 0)
		throw XYException('x',"Pixel en dehors de la largeur");
	if(this->getDimension().getHauteur() < y || y < 0)
		throw XYException('y',"Pixel en dehors de la hauteur");
	matrice(x,y)= val;
}

void ImageB::setBackground(bool val) 
{
	for (int i = 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur(); j++)
			if(val)
				setPixel(i,j,true);
			else
				setPixel(i,j,false);	
}

void ImageB::setDimension(const Dimension& olddim)
{
	#ifdef DEV
	TraceMethode("setDimension ImageB");
	#endif
	
	Matrice<bool> mattmp(olddim.getLargeur(),olddim.getHauteur(),false);
	Dimension dimtmp(dimension);
	
	Image::setDimension(olddim);
	
	setBackground(false);
	
	if(matrice.getLargeur()!= 0 && matrice.getHauteur() != 0)
	{
		for(int x = 0; x < dimension.getLargeur() && x < dimtmp.getLargeur();x++)
			for(int y = 0; y < dimension.getHauteur() && y < dimtmp.getHauteur();y++)
			{
				mattmp.setValeur(x,y,matrice(x,y));				
			}
				
	}
	matrice = mattmp;
	
}

/********************************-Getteurs-********************************/

bool ImageB::getPixel(int x, int y) const
{
	return matrice(x,y);
}

/********************************-Methodes autre-********************************/

void ImageB::Affiche() const
{
	if(nom)
	{
		cout<< "nom: " << nom << endl;
	}
	else
	{
		cout<<"pas de nom" <<endl;
	}
	
	cout << "id: " << id << endl;
	cout << "Largeur: " << dimension.getLargeur() << " | Hauteur: " << dimension.getHauteur() << endl;
}

void ImageB::Dessine() const
{
	WindowSDL::open(getDimension().getLargeur(),getDimension().getHauteur());
	WindowSDLimage image(getDimension().getLargeur(),getDimension().getHauteur());
	for(int i= 0; i < getDimension().getLargeur(); i++)
		for(int j = 0; j < getDimension().getHauteur();j++)
			if(getPixel(i,j))
				{
					//TraceMethode("true");
					image.setPixel(i,j,couleurTrue.getRouge(),couleurTrue.getVert(),couleurTrue.getBleu());
				}
			else
				{
					//TraceMethode("false");
					image.setPixel(i,j,couleurFalse.getRouge(),couleurFalse.getVert(),couleurFalse.getBleu());
				}
				
	WindowSDL::drawImage(image,0,0);
	WindowSDL::waitClick();
	WindowSDL::close();
}

void ImageB::Dessine(int x, int y) const
{
	WindowSDLimage image(getDimension().getLargeur(),getDimension().getHauteur());
	for(int i= 0; i < getDimension().getLargeur(); i++)
		for(int j = 0; j < getDimension().getHauteur();j++)
			if(getPixel(i,j))
				{
					//TraceMethode("true");
					image.setPixel(i,j,couleurTrue.getRouge(),couleurTrue.getVert(),couleurTrue.getBleu());
				}
			else
				{
					//TraceMethode("false");
					image.setPixel(i,j,couleurFalse.getRouge(),couleurFalse.getVert(),couleurFalse.getBleu());
				}
				
	WindowSDL::drawImage(image,x,y);
}


void ImageB::exportToBMP(const char* fichier)
{
	WindowSDLimage imgtemp(dimension.getLargeur(), dimension.getHauteur());
	for(int i=0; i < dimension.getLargeur(); i++)
		for(int j=0; j < dimension.getHauteur(); j++)
			if(getPixel(i,j))
				imgtemp.setPixel(i,j,couleurTrue.getRouge(),couleurTrue.getVert(),couleurTrue.getBleu());
			else
				imgtemp.setPixel(i,j,couleurFalse.getRouge(),couleurFalse.getVert(),couleurFalse.getBleu());
			
	imgtemp.exportToBMP(fichier);
	
}

void ImageB::Save(ofstream & fichier) const
{
	bool pixel;
	Trace("22");
	Image::Save(fichier);
	Trace("23");
	for(int x = 0; x < dimension.getLargeur(); x++)
		for(int y = 0; y < dimension.getHauteur(); y++)
			{
				pixel = getPixel(x,y);
				fichier.write((char*)&pixel,sizeof(bool)); // 7. pixels
			}
} 

void ImageB::Load(ifstream & fichier)
{
	
	bool pixel;
	Image::Load(fichier);
	setDimension(getDimension());
	
	for(int x = 0; x < dimension.getLargeur(); x++)
		for(int y = 0; y < dimension.getHauteur(); y++)
			{
				fichier.read((char*)&pixel,sizeof(bool));
				setPixel(x,y,pixel);
			}
}	
