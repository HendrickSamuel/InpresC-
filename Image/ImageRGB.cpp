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
	s<<"id: " <<img.getId()<<endl;
	if(img.getNom())
		s << " nom: "<< img.getNom() << endl;	
	else
		s << "pas de nom" << endl;
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

void ImageRGB::Save(ofstream & fichier) const
{
	char type = 'C';
	int taillenom = strlen(nom);
	Couleur pixel;
	fichier.write(&type,sizeof(char)); // 1. type
	fichier.write((char*)&id,sizeof(int)); // 2. id
	fichier.write((char*)&taillenom,sizeof(int)); // 3. taille du nom
	fichier.write(nom,sizeof(char)*taillenom); // 4. nom
	dimension.Save(fichier); // 5. dimension
	
	for(int x = 0; x < dimension.getLargeur(); x++)
		for(int y = 0; y < dimension.getHauteur(); y++)
			{
				pixel = getPixel(x,y);
				pixel.Save(fichier);
			}
} 

void ImageRGB::Load(ifstream & fichier)
{
	char type = 'X';
	int taillenom;
	Couleur pixel;
	fichier.read(&type,sizeof(char));// 1. type
	if(type != 'C')
	{
		Trace("mauvais type");
		//throw erreur
	}
	#ifdef DEVPLUS
	Trace("bon type");
	#endif
	
	fichier.read((char*)&id,sizeof(int)); // 2. id
	fichier.read((char*)&taillenom,sizeof(int)); // 3. taille du nom
	char* nomtmp = new char[taillenom+1]; 
	fichier.read(nomtmp,taillenom); // 4. nom
	setNom(nomtmp);
	delete[] nomtmp;
	dimension.Load(fichier);
	matrice.Redimension(dimension);
	
	for(int x = 0; x < dimension.getLargeur(); x++)
		for(int y = 0; y < dimension.getHauteur(); y++)
			{
				pixel.Load(fichier);
				setPixel(x,y,pixel);
			}
}
