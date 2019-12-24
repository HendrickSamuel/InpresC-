#include "ImageRGB.h"
#include "Dimension.h"
#include "Ecran.h"
#include <string.h>
#include <iostream>
	
/********************************-Constructeur/Destructeur-********************************/

ImageRGB::ImageRGB(): Image(),matrice(Dimension::VGA.getLargeur(),Dimension::VGA.getHauteur()) 
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageRGB par defaut");
	#endif	
	setDimension(Dimension::VGA);
}

ImageRGB::ImageRGB(int idget, const char* chaineget): Image(idget,chaineget),matrice(Dimension::VGA.getLargeur(),Dimension::VGA.getHauteur())
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageRGB par valeur double");
	#endif
	setDimension(Dimension::VGA);
}

ImageRGB::ImageRGB(const char* chaineget): matrice(0,0)
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageRGB par valeur unique");
	#endif
	nom = NULL;
	setNom(chaineget); 
	setId(-1);
	//setDimension(Dimension::VGA);
	importFromBMP(chaineget);
}

ImageRGB::ImageRGB(const ImageRGB& old): matrice(0,0)
{
	#ifdef DEV
	TraceConstructeur("Constructeur ImageRGB par copie");
	#endif

	nom = NULL;
	setNom(old.getNom());	
	setId(old.getId());
	setDimension(old.getDimension());

	for(int i= 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur();j++)
			setPixel(i,j,old.getPixel(i,j));	
}

ImageRGB::ImageRGB(int idget, const char* chaineget,const  Dimension& olddim): Image(idget,chaineget), matrice(olddim.getLargeur(),olddim.getHauteur())
{	
	#ifdef DEV
	TraceConstructeur("Constructeur ImageRGB par valeur complete");
	#endif
	setDimension(olddim);
}

ImageRGB::~ImageRGB()
{
	#ifdef DEV
	TraceConstructeur("Destructeur ImageRGB");
	#endif
}

/********************************-Operateurs-********************************/

const ImageRGB& ImageRGB::operator=(const ImageRGB& old)
{
	#ifdef DEV
	TraceConstructeur("Opérateur d'affectation = '");
	#endif
	
	//nom = NULL; si nom et matrice existent alors c'est ok mais sinon ??
	setNom(old.getNom());	
	setId(old.getId());

	setDimension(old.getDimension());

	for(int i= 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur();j++)
			setPixel(i,j,old.getPixel(i,j));
			
	return *this;
}

ImageRGB ImageRGB::operator+(const PixelRGB& pixel)
{
	ImageRGB imgtemp(*this);
	imgtemp.setPixel(pixel.getX(),pixel.getY(),pixel.getValeur());
	return imgtemp;
}


ImageRGB operator+(const PixelRGB& pixel,ImageRGB& img)
{
	return img+pixel;
}

ostream& operator<<(ostream& s, const ImageRGB& img)
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

void ImageRGB::setPixel(int x,int y,const Couleur& coul)
{
	if((this->getDimension().getLargeur() < x || x < 1 )&& (this->getDimension().getHauteur() < y || y < 0) )
		throw XYException('d',"Pixel en dehors de l'image");
	if(this->getDimension().getLargeur() < x || x < 0)
		throw XYException('x',"Pixel en dehors de la largeur");
	if(this->getDimension().getHauteur() < y || y < 0)
		throw XYException('y',"Pixel en dehors de la hauteur");
	matrice(x,y)= coul;
}

void ImageRGB::setBackground(const Couleur& coul) 
{
	for (int i = 0; i < dimension.getLargeur(); i++)
		for(int j = 0; j < dimension.getHauteur(); j++)
			setPixel(i,j,coul);
}

void ImageRGB::setDimension(const Dimension& olddim)
{
	#ifdef DEV
	TraceMethode("setDimension ImageRGB");
	#endif
	Matrice<Couleur> mattmp(olddim.getLargeur(),olddim.getHauteur());
	Dimension dimtmp(dimension);
	
	Image::setDimension(olddim);
	
	if(matrice.getLargeur()!= 0 && matrice.getHauteur()!= 0)
	{
		for(int x = 0; x < dimension.getLargeur() && x < dimtmp.getLargeur();x++)
			for(int y = 0; y < dimension.getHauteur() && y < dimtmp.getHauteur();y++)
			{
				mattmp.setValeur(x,y,mattmp(x,y));				
			}
				
	}
	
	matrice = mattmp;	

	
}

/********************************-Getteurs-********************************/

const Couleur ImageRGB::getPixel(int x, int y) const
{
	return matrice(x,y);
}


/********************************-Methodes autre-********************************/

void ImageRGB::Affiche() const
{
	if(nom)
	{
		cout<< "nom: " << nom << endl;
	}
	else
	{
		cout<<"pas de nom" <<endl;
	}
	
	//si matrice n'existe pas ?
	cout << "id: " << id << endl;
	cout << "Largeur: " << dimension.getLargeur() << " | Hauteur: " << dimension.getHauteur() << endl;
}

void ImageRGB::Dessine() const
{
	Couleur coultmp;
	WindowSDL::open(getDimension().getLargeur(),getDimension().getHauteur());
	WindowSDLimage image(getDimension().getLargeur(),getDimension().getHauteur());
	for(int i= 0; i < getDimension().getLargeur(); i++)
		for(int j = 0; j < getDimension().getHauteur();j++)
		{	
			coultmp = getPixel(i,j);
			image.setPixel(i,j,coultmp.getRouge(),coultmp.getVert(),coultmp.getBleu());
		}
			
	WindowSDL::drawImage(image,0,0);
	WindowSDL::waitClick();
	WindowSDL::close();
}

void ImageRGB::Dessine(int x,int y) const{
	Couleur coultmp;
	int larg = this->getDimension().getLargeur();
	int haut = this->getDimension().getHauteur();
	WindowSDLimage image(larg,haut);
	for(int i= 0; i < larg; i++)
		for(int j = 0; j < haut;j++)
		{	
			coultmp = getPixel(i,j);
			image.setPixel(i,j,coultmp.getRouge(),coultmp.getVert(),coultmp.getBleu());
		}
			
	WindowSDL::drawImage(image,x,y);
}

void ImageRGB::importFromBMP(const char* fichier)
{
	Couleur coul;
	int rouge,vert,bleu;
	WindowSDLimage imgtemp(fichier);
	dimension.setHauteur(imgtemp.getHeight());
	dimension.setLargeur(imgtemp.getWidth());
	setDimension(dimension);
	for(int i=0; i < dimension.getLargeur(); i++)
		for(int j=0; j < dimension.getHauteur(); j++)
		{
			imgtemp.getPixel(i,j,&rouge,&vert,&bleu);
			coul.setRouge(rouge);
			coul.setVert(vert);
			coul.setBleu(bleu);
			setPixel(i,j,coul);
		}
}

void ImageRGB::exportToBMP(const char* fichier)
{
	WindowSDLimage imgtemp(dimension.getLargeur(), dimension.getHauteur());
	for(int i=0; i < dimension.getLargeur(); i++)
		for(int j=0; j < dimension.getHauteur(); j++)
			imgtemp.setPixel(i,j,getPixel(i,j).getRouge(),getPixel(i,j).getVert(),getPixel(i,j).getBleu());
			
	imgtemp.exportToBMP(fichier);
	
}

/*---------------- BONUS -----------------*/
	
	ImageNG ImageRGB::getRouge() const{
		ImageNG imRetour(0,this->getNom(),this->getDimension());
		int larg = this->getDimension().getLargeur();
		int haut = this->getDimension().getHauteur();
		for(int x = 0; x < larg; x++)
			for(int y = 0; y < haut; y++)
				imRetour.setPixel(x,y,this->getPixel(x,y).getRouge());
				
		return imRetour;
	}
	ImageNG ImageRGB::getVert() const{
		ImageNG imRetour(0,this->getNom(),this->getDimension());
		int larg = this->getDimension().getLargeur();
		int haut = this->getDimension().getHauteur();
		for(int x = 0; x < larg; x++)
			for(int y = 0; y < haut; y++)
				imRetour.setPixel(x,y,this->getPixel(x,y).getVert());
				
		return imRetour;
	}
	ImageNG ImageRGB::getBleu() const{
		ImageNG imRetour(0,this->getNom(),this->getDimension());
		int larg = this->getDimension().getLargeur();
		int haut = this->getDimension().getHauteur();
		for(int x = 0; x < larg; x++)
			for(int y = 0; y < haut; y++)
				imRetour.setPixel(x,y,this->getPixel(x,y).getBleu());
				
		return imRetour;
	}
	void ImageRGB::setRGB(const ImageNG &r, const ImageNG &g, const ImageNG& b){
		if(1)// j'arrive pas a comparer les dimension
		{	
			Couleur pixel;
			this->setDimension(r.getDimension());
			int larg = this->getDimension().getLargeur();
			int haut = this->getDimension().getHauteur();
			for(int x = 0; x < larg; x++)
				for(int y = 0; y < haut; y++)
				{
					pixel.setRouge(r.getPixel(x,y));
					pixel.setVert(g.getPixel(x,y));
					pixel.setBleu(b.getPixel(x,y));
					this->setPixel(x,y,pixel);
				}
		}
		else
			throw(XYException(1,"les 3 matrices n'ont pas la meme tailles"));
		
	}
	
/*---------------- FIN BONUS -----------------*/

void ImageRGB::Save(ofstream & fichier) const
{
	Couleur pixel;
	Image::Save(fichier);
	
	for(int x = 0; x < dimension.getLargeur(); x++)
		for(int y = 0; y < dimension.getHauteur(); y++)
			{
				pixel = getPixel(x,y);
				pixel.Save(fichier);
			}
} 

void ImageRGB::Load(ifstream & fichier)
{
	Couleur pixel;
	Image::Load(fichier);
	setDimension(this->getDimension());
	for(int x = 0; x < dimension.getLargeur(); x++)
		for(int y = 0; y < dimension.getHauteur(); y++)
			{
				pixel.Load(fichier);
				setPixel(x,y,pixel);
			}
}
