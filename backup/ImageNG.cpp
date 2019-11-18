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

ImageNG::ImageNG() {
int i = 7;
	#ifdef DEV
	TraceConstructeur("Constructeur Image par defaut -- %d -- ",i);
	#endif
	setId(-1);
	nom = NULL;
	matrice = NULL;
	setDimension(Dimension::VGA);
	setBackground(0);
}

ImageNG::ImageNG(int idget, const char* chaineget)
{
	#ifdef DEV
	TraceConstructeur("Constructeur Image par valeur double");
	#endif
	nom = NULL;
	setNom(chaineget);
	setId(idget);
	matrice = NULL;
	setDimension(Dimension::VGA);
}

ImageNG::ImageNG(const char* chaineget)
{
	#ifdef DEV
	TraceConstructeur("Constructeur Image par valeur unique");
	#endif
	nom = NULL;
	setNom(chaineget); 
	setId(-1);
	matrice = NULL;
	//setDimension(Dimension::VGA);
	importFromBMP(chaineget);
}

ImageNG::ImageNG(const ImageNG& old)
{
	#ifdef DEV
	TraceConstructeur("Constructeur Image par copie");
	#endif

	nom = NULL;
	setNom(old.getNom());	
	setId(old.getId());
	matrice = NULL;

	setDimension(old.getDimension());

	for(int i= 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur();j++)
			setPixel(i,j,old.getPixel(i,j));
			
	
}

ImageNG::ImageNG(int idget, const char* chaineget,const  Dimension& olddim)
{	
	#ifdef DEV
	TraceConstructeur("Constructeur Image par valeur complete");
	#endif
	nom = NULL;
	setNom(chaineget);
	setId(idget);
	matrice = NULL;
	setDimension(olddim);
}

ImageNG::~ImageNG()
{
	#ifdef DEV
	TraceConstructeur("Destructeur");
	#endif
	if(nom)
	{
		delete nom;
	}
	if(matrice)
	{
		for (int x=0 ; x<dimension.getLargeur() ; x++) delete[] matrice[x];
		delete[] matrice;
	}
	
}

/********************************-Operateurs-********************************/

const ImageNG& ImageNG::operator=(const ImageNG& old)
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

ImageNG operator+(ImageNG& img,int valeur)
{
	int valpixel;
	ImageNG imgtemp(img);
	
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

ImageNG operator+(int valeur,ImageNG& img)
{
	return (img+valeur);
}

ostream& operator<<(ostream& s, const ImageNG& img)
{
	s<<"id: " <<img.getId();	
	s << " nom: "<< img.getNom() << endl;	
	s << "largeur: " << img.dimension.getLargeur() << " hauteur: " << img.dimension.getHauteur();
	s << " luminance: " << img.getLuminance() << " contraste: " << img.getContraste();	
	s << endl;
	
	return s;
}


/********************************-Setteurs-********************************/
void ImageNG::setId(int idget)
{
	#ifdef DEV
	TraceMethode("setId");
	#endif
	id = idget;
}
		
void ImageNG::setNom(const char* chaineget)
{
	if(nom)
	{
		delete nom;
	}
	if(chaineget)
	{
		nom = new char[strlen(chaineget)+1];
		strcpy(nom,chaineget);
	}
	else
	{
	 nom = NULL;
	}
} 

void ImageNG::setDimension(const Dimension& olddim)
{
	#ifdef DEV
	TraceMethode("setDimension");
	#endif
	
	
	int** matricetmp;
	matricetmp = matrice;
	
	matrice = new int*[olddim.getLargeur()];
	for (int x=0 ; x<olddim.getLargeur() ; x++) matrice[x] = new int[olddim.getHauteur()];
	
	
	Dimension dimtmp(dimension);
	
	dimension.setLargeur(olddim.getLargeur());
	dimension.setHauteur(olddim.getHauteur());
	
	setBackground(0);

	
	if(matricetmp != 0)
	{	
		
		for(int i= 0; i < dimtmp.getLargeur() && i < olddim.getLargeur(); i++)
			for(int j = 0; j < dimtmp.getHauteur() && j < olddim.getHauteur();j++)
				setPixel(i,j,matricetmp[i][j]);
						
		
		for (int x=0 ; x<dimtmp.getLargeur() ; x++) delete[] matricetmp[x];
		delete[] matricetmp;

	}

	
}

void ImageNG::setPixel(int x,int y,int val)
{
	matrice[x][y]= val;
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

/********************************-Getteurs-********************************/

const char* ImageNG::getNom() const
{
	return nom; 
}

int ImageNG::getId() const
{
	return id;
}

const Dimension& ImageNG::getDimension() const
{
	return dimension;
}

int ImageNG::getPixel(int x, int y) const
{
	return matrice[x][y];
}

int ImageNG::getLuminance() const
{
	int lum = 0, count = 0;
	if(matrice)
	{
		for(int i=0; i < dimension.getLargeur(); i++)
		for(int j=0; j < dimension.getHauteur(); j++)
		{
			lum += getPixel(i,j);
			count++;
		}
		lum /= count;
	}
	
	return lum;
}

int ImageNG::getMinimum() const
{
	if(matrice)
	{
		int min = getPixel(0,0);
		for(int i=0; i < dimension.getLargeur(); i++)
			for(int j=0; j < dimension.getHauteur(); j++)
				if(min > getPixel(i,j))
					min = getPixel(i,j); 
				
		return min;	
	}
	return 0;
	
}

int ImageNG::getMaximum() const
{
	if(matrice)
	{
		int max = getPixel(0,0);
		for(int i=0; i < dimension.getLargeur(); i++)
			for(int j=0; j < dimension.getHauteur(); j++)
				if(max < getPixel(i,j))
					max = getPixel(i,j);
				
		return max;
	}
	return 0;
		
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
	
	if(matrice)
	{
		cout<< "matrice ok " << endl;
	}
	else
	{
		cout << "pas de matrice" << endl;
	}
	cout << "id: " << id << endl;
	cout << "Largeur: " << dimension.getLargeur() << " | Hauteur: " << dimension.getHauteur() << endl;
}

void ImageNG::Dessine()
{
	WindowSDL::open(dimension.getLargeur(),dimension.getHauteur());
	WindowSDLimage image(dimension.getLargeur(),dimension.getHauteur());
	for(int i= 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur();j++)
			image.setPixel(i,j,matrice[i][j],matrice[i][j],matrice[i][j]);
		
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


