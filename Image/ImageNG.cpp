#include "ImageNG.h"
#include "Dimension.h"
#include "Ecran.h"
#include <string.h>
#include <iostream>

/********************************-Valeurs statiques-********************************/
	
	const int ImageNG::LUMINANCE = 0;
	const int ImageNG::PIXEL_A_PIXEL = 1;
	
	int ImageNG::comparaison = LUMINANCE;
	
/********************************-Constructeur/Destructeur-********************************/

ImageNG::ImageNG(): Image(),matrice(Dimension::VGA.getLargeur(),Dimension::VGA.getHauteur(),0)
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageNG par defaut");
	#endif
	setDimension(Dimension::VGA);
}

ImageNG::ImageNG(int idget, const char* chaineget): Image(idget,chaineget),matrice(Dimension::VGA.getLargeur(),Dimension::VGA.getHauteur(),0)
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageNG par valeur double");
	#endif
	setDimension(Dimension::VGA);
}

ImageNG::ImageNG(const char* chaineget): matrice(0,0,0) 
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageNG par valeur unique");
	#endif
	nom = NULL;
	setNom(chaineget); 
	setId(-1);
	importFromBMP(chaineget);
}

ImageNG::ImageNG(const ImageNG& old):Image(old), matrice(0,0,0) 
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageNG par copie");
	#endif

//	nom = NULL;
//	setNom(old.getNom());	
//	setId(old.getId());
	
	setDimension(old.getDimension());

	for(int i= 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur();j++)
			setPixel(i,j,old.getPixel(i,j));	
}

ImageNG::ImageNG(int idget, const char* chaineget,const  Dimension& olddim): Image(idget,chaineget), matrice(olddim.getLargeur(),olddim.getHauteur(),0)
{	
	#ifdef DEV
	TraceConstructeur("Constructeur ImageNG par valeur complete");
	#endif
	setDimension(olddim);
}

ImageNG::~ImageNG()
{
	#ifdef DEV
	TraceConstructeur("Destructeur ImageNG");
	#endif
}

/********************************-Operateurs-********************************/

const ImageNG& ImageNG::operator=(const ImageNG& old)
{
	#ifdef DEV
	TraceConstructeur("Opérateur d'affectation = '");
	#endif

	setNom(old.getNom());	
	setId(old.getId());

	setDimension(old.getDimension());

	for(int i= 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur();j++)
			setPixel(i,j,old.getPixel(i,j));
			
	return *this;
}

ImageNG ImageNG::operator+(int valeur)
{
	int valpixel;
	ImageNG imgtemp(*this);
	
	for(int x=0; x < imgtemp.getDimension().getLargeur(); x++)
		for(int y=0; y < imgtemp.getDimension().getHauteur(); y++)
		{
			valpixel = imgtemp.getPixel(x,y)+valeur;
			if(valpixel > 255)
				valpixel = 255;
			imgtemp.setPixel(x,y,valpixel);
		}
	return (imgtemp);
}


ImageNG ImageNG::operator-(int valeur)
{
	int valpixel;
	ImageNG imgtemp(*this);
	
	for(int x=0; x < imgtemp.getDimension().getLargeur(); x++)
		for(int y=0; y < imgtemp.getDimension().getHauteur(); y++)
		{
			valpixel = imgtemp.getPixel(x,y);
			valpixel -= valeur;
			if(valpixel < 0)
				valpixel = 0;
			imgtemp.setPixel(x,y,valpixel);
		}
	return (imgtemp);
}

ImageNG ImageNG::operator-(const ImageNG& d1)
{
	if(dimension != d1.dimension)
		throw XYException('d',"soustraction d'images de tailles differentes");
		
	ImageNG imgtemp(*this);
	
	for(int i=0; i < d1.getDimension().getLargeur() && i < this->getDimension().getLargeur();i++ )
		for(int j=0; j < d1.getDimension().getHauteur() && j < this->getDimension().getHauteur(); j++)
			{
				int diff = this->getPixel(i,j)-d1.getPixel(i,j);
				if(diff < 0)
					diff=0;
				imgtemp.setPixel(i,j,diff);
			}
	return imgtemp;
}

const ImageNG& ImageNG::operator++()
{
	*this = *this + 20;
	return *this;
}

ImageNG ImageNG::operator++(int)
{
	ImageNG temp(*this);
	*this = *this+20;
	return temp;
}

const ImageNG& ImageNG::operator--()
{
	*this = *this - 20;
	return *this;
}

ImageNG ImageNG::operator--(int)
{
	ImageNG temp(*this);
	*this = *this-20;
	return temp;
}

ImageNG ImageNG::operator+(const PixelNG& pixel)
{
	ImageNG imgtemp(*this);
	imgtemp.setPixel(pixel.getX(),pixel.getY(),pixel.getValeur());
	return imgtemp;
}

bool ImageNG::operator<(const ImageNG& i1)
{
	if(comparaison == 0)
	{
		if(this->getLuminance() < i1.getLuminance())
			return true;
		else
			return false;
	}
	else
	{
		if(dimension != i1.dimension)
			throw XYException('d',"Dimension comparaison PAP < inegale");
		for(int i=0; (i < this->getDimension().getLargeur())&& (i< i1.getDimension().getLargeur());i++)
			for(int j=0; (j< this->getDimension().getHauteur()) && (j < i1.getDimension().getHauteur());j++)
				{
					if(this->getPixel(i,j) >= i1.getPixel(i,j))
						return false;
				}
		return true;
	}
}

bool ImageNG::operator>(const ImageNG& i1)
{
	if(comparaison == 0)
	{
		if(this->getLuminance() > i1.getLuminance())
			return true;
		else
			return false;
	}
	else
	{
		if(dimension != i1.dimension)
			throw XYException('d',"Dimension comparaison PAP > inegale");
		for(int i=0; (i < this->getDimension().getLargeur())&& (i< i1.getDimension().getLargeur());i++)
				for(int j=0; (j< this->getDimension().getHauteur()) && (j < i1.getDimension().getHauteur());j++)
					{
						if(this->getPixel(i,j) <= i1.getPixel(i,j))
							return false;
					}
			return true;
	}
}

bool ImageNG::operator==(const ImageNG& i1)
{
	if(comparaison == 0)
	{
		if(this->getLuminance() == i1.getLuminance())
			return true;
		else
			return false;
	}
	else
	{
		if(this->dimension != i1.dimension)
			throw XYException('d',"Dimension comparaison PAP == inegale");
		for(int i=0; (i < this->getDimension().getLargeur())&& (i< i1.getDimension().getLargeur());i++)
				for(int j=0; (j< this->getDimension().getHauteur()) && (j < i1.getDimension().getHauteur());j++)
					{
						if(this->getPixel(i,j) != i1.getPixel(i,j))
							return false;
					}
			return true;
	}	
}

ImageNG operator+(const PixelNG& pixel,ImageNG& img)
{
	return img+pixel;
}

ImageNG operator+(int valeur,const ImageNG& img)
{
	ImageNG image(img);
	return image + valeur;
}

ostream& operator<<(ostream& s, const ImageNG& img)
{
	s<<"id: " <<img.getId() << endl;	
	if(img.getNom())
		s << " nom: "<< img.getNom() << endl;	
	else
		s << "pas de nom" << endl;
	s << "largeur: " << img.dimension.getLargeur() << " hauteur: " << img.dimension.getHauteur();
	s << " luminance: " << img.getLuminance() << " contraste: " << img.getContraste();	
	s << endl;
	
	return s;
}


/********************************-Setteurs-********************************/

void ImageNG::setPixel(int x,int y,int val)
{
	if((this->getDimension().getLargeur() < x || x < 1 )&& (this->getDimension().getHauteur() < y || y < 0) )
		throw XYException('d',"Pixel en dehors de l'image");
	if(this->getDimension().getLargeur() < x || x < 0)
		throw XYException('x',"Pixel en dehors de la largeur");
	if(this->getDimension().getHauteur() < y || y < 0)
		throw XYException('y',"Pixel en dehors de la hauteur");
		
		
	if(val < 0 || val > 255)
		throw RGBException(val,"Composante Niveau de gris invalide");
	matrice(x,y)= val;
}

void ImageNG::setBackground(int val) 
{
	for (int i = 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur(); j++)
			setPixel(i,j,val);
}

void ImageNG::setComparaison(int comp)
{
	switch(comp)
	{
		case 0: 
			comparaison = LUMINANCE;
			break;
		case 1:
			comparaison = PIXEL_A_PIXEL;
			break;
		default:
			comparaison = LUMINANCE;
	}
}

void ImageNG::setDimension(const Dimension& olddim)
{
	#ifdef DEV
	TraceMethode("setDimension ImageNG");
	#endif
	Matrice<int> mattmp(olddim.getLargeur(),olddim.getHauteur(),0);
	Dimension dimtmp(dimension);
	
	Image::setDimension(olddim);
	
	if(matrice.getLargeur() != 0 && matrice.getHauteur() != 0)
	{
		for(int x = 0; x < dimension.getLargeur() && x < dimtmp.getLargeur();x++)
			for(int y = 0; y < dimension.getHauteur() && y < dimtmp.getHauteur();y++)
			{
				#ifdef DEVPLUS
				Trace("valeur du set en [%d,%d] %d",x,y, mattmp(x,y));
				#endif
				matrice.setValeur(x,y,matrice(x,y));				
			}
				
	}
	matrice = mattmp;
}

/********************************-Getteurs-********************************/

int ImageNG::getPixel(int x, int y) const
{
	return matrice(x,y);
}

int ImageNG::getLuminance() const
{
	//si pas matrice ?
	int lum = 0, count = 0;
	for(int i=0; i < dimension.getLargeur(); i++)
			for(int j=0; j < dimension.getHauteur(); j++)
			{
				lum += getPixel(i,j);
				count++;
			}
			lum /= count;
	
	return lum;
}

int ImageNG::getMinimum() const
{
	//si pas matrice ?
		int min = getPixel(0,0);
		for(int i=0; i < dimension.getLargeur(); i++)
			for(int j=0; j < dimension.getHauteur(); j++)
				if(min > getPixel(i,j))
					min = getPixel(i,j); 
				
		return min;	
}

int ImageNG::getMaximum() const
{
	//si pas matrice ?
		int max = getPixel(0,0);
		for(int i=0; i < dimension.getLargeur(); i++)
			for(int j=0; j < dimension.getHauteur(); j++)
				if(max < getPixel(i,j))
					max = getPixel(i,j);
				
		return max;		
}

float ImageNG::getContraste() const
{
	float contraste;
	int min, max;
	min = getMinimum();
	max = getMaximum();
	
	contraste = (float)(max-min)/(float)(max+min);
	
	return contraste;
} 

int ImageNG::getComparaison()
{
	return comparaison;
}

/********************************-Methodes autre-********************************/

void ImageNG::Affiche() const
{
	if(nom)
	{
		cout<< "nom: " << nom << endl;
	}
	else
	{
		cout<<"pas de nom" <<endl;
	}
	
	// affichage du contenu de matrice ?
	cout << "id: " << id << endl;
	cout << "Largeur: " << dimension.getLargeur() << " | Hauteur: " << dimension.getHauteur() << endl;
}

void ImageNG::Dessine() const
{
	WindowSDL::open(getDimension().getLargeur(),getDimension().getHauteur());
	WindowSDLimage image(getDimension().getLargeur(),getDimension().getHauteur());
	for(int i= 0; i < getDimension().getLargeur(); i++)
		for(int j = 0; j < getDimension().getHauteur();j++)
			image.setPixel(i,j,getPixel(i,j),getPixel(i,j),getPixel(i,j));
		
	WindowSDL::drawImage(image,0,0);
	WindowSDL::waitClick();
	WindowSDL::close();
}

void ImageNG::importFromBMP(const char* fichier)
{
	int gris,rouge,vert,bleu;
	
	WindowSDLimage imgtemp(fichier);
	dimension.setHauteur(imgtemp.getHeight());
	
	dimension.setLargeur(imgtemp.getWidth());
	setDimension(dimension);
	for(int i=0; i < dimension.getLargeur(); i++)
		for(int j=0; j < dimension.getHauteur(); j++)
		{
			imgtemp.getPixel(i,j,&rouge,&vert,&bleu);
			gris = (rouge+vert+bleu)/3;
			setPixel(i,j,gris);
		}
}

void ImageNG::exportToBMP(const char* fichier)
{
	WindowSDLimage imgtemp(dimension.getLargeur(), dimension.getHauteur());
	for(int i=0; i < dimension.getLargeur(); i++)
		for(int j=0; j < dimension.getHauteur(); j++)
			imgtemp.setPixel(i,j,getPixel(i,j),getPixel(i,j),getPixel(i,j));
			
	imgtemp.exportToBMP(fichier);
	
}

void ImageNG::Save(ofstream & fichier) const
{
	char type = 'N';
	int pixel;
	fichier.write(&type,sizeof(char)); // 1. type
	Image::Save(fichier);
	
	for(int x = 0; x < dimension.getLargeur(); x++)
		for(int y = 0; y < dimension.getHauteur(); y++)
			{
				pixel = getPixel(x,y);
				fichier.write((char*)&pixel,sizeof(int)); // 7. pixels
			}
} 

void ImageNG::Load(ifstream & fichier)
{
	char type = 'X';
	int pixel;
	fichier.read(&type,sizeof(char));// 1. type
	if(type != 'N')
	{
		Trace("mauvais type");
		//throw erreur
	}
	#ifdef DEVPLUS
	Trace("bon type");
	#endif
	Image::Load(fichier);
	
	setDimension(this->getDimension());
	
	for(int x = 0; x < dimension.getLargeur(); x++)
		for(int y = 0; y < dimension.getHauteur(); y++)
			{
				fichier.read((char*)&pixel,sizeof(int));
				setPixel(x,y,pixel);
			}
}	
