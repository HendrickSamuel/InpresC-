#include "Image.h"

	
/********************************-Constructeur/Destructeur-********************************/

Image::Image() {
	#ifdef DEV
	TraceConstructeur("Constructeur Image par defaut ");
	#endif
	setId(-1);
	nom = NULL;
	//setDimension(Dimension::VGA);
}

Image::Image(int idget, const char* chaineget)
{
	#ifdef DEV
	TraceConstructeur("Constructeur Image par valeur double");
	#endif
	nom = NULL;
	setNom(chaineget);
	setId(idget);
	//setDimension(Dimension::VGA);
}

Image::Image(const Image& old)
{
	#ifdef DEV
	TraceConstructeur("Constructeur Image par copie");
	#endif
	nom = NULL;
	setNom(old.getNom());	
	setId(old.getId());
	setDimension(old.getDimension());	
}

Image::Image(int idget, const char* chaineget,const  Dimension& olddim)
{	
	#ifdef DEV
	TraceConstructeur("Constructeur Image par valeur complete");
	#endif
	nom = NULL;
	setNom(chaineget);
	setId(idget);
	setDimension(olddim);
}

Image::~Image()
{
	#ifdef DEV
	TraceConstructeur("Destructeur");
	#endif
	if(nom)
	{
		delete nom;
	}	
}



/********************************-Setteurs-********************************/
void Image::setId(int idget)
{
	#ifdef DEV
	TraceMethode("setId");
	#endif
	id = idget;
}
		
void Image::setNom(const char* chaineget)
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

void Image::setDimension(const Dimension& olddim)
{
	#ifdef DEV
	TraceMethode("setDimension");
	#endif
	
	dimension.setLargeur(olddim.getLargeur());
	dimension.setHauteur(olddim.getHauteur());
}


/********************************-Getteurs-********************************/

const char* Image::getNom() const
{
	return nom; 
}

int Image::getId() const
{
	return id;
}

const Dimension& Image::getDimension() const
{
	return dimension;
}


/********************************-Methodes autre-********************************/


void Image::Save(ofstream & fichier) const{
	int taillenom = strlen(nom)+1;
	fichier.write((char*)&id,sizeof(int)); // 2. id
	fichier.write((char*)&taillenom,sizeof(int)); // 3. taille du nom
	fichier.write(nom,sizeof(char)*taillenom); // 4. nom
	dimension.Save(fichier); // 5. dimension
}

void Image::Load(ifstream & fichier){
	int taillenom;
	fichier.read((char*)&id,sizeof(int)); // 2. id
	fichier.read((char*)&taillenom,sizeof(int)); // 3. taille du nom
	char* nomtmp = new char[taillenom]; 
	fichier.read(nomtmp,taillenom); // 4. nom
	setNom(nomtmp);
	delete[] nomtmp;
	dimension.Load(fichier);
}

