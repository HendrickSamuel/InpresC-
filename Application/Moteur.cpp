#include "Moteur.h"
Moteur::Moteur():Compteur(0)
{
	msgerreur = NULL;
	fichierLog.open("traces.log",std::ofstream::app);
}

Moteur::~Moteur(){
	if(msgerreur)
		delete msgerreur;
	if(fichierLog.is_open())
		fichierLog.close();
}

/* ------------------------- Methodes privees --------------------------*/
int Moteur::Insere(Image *pImage){
	pImage->setId(Compteur);
	Compteur++;
	ImageB* pB = dynamic_cast<ImageB*>(pImage);
    if (pB != NULL)
    {
      imagesB.insere(*pB);
      return Compteur-1;
    }
    ImageNG* pNG = dynamic_cast<ImageNG*>(pImage);
    if (pNG != NULL) 
    {
      imagesNG.insere(*pNG);
      return Compteur-1;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pImage);
    if (pRGB != NULL) 
    {
      imagesRGB.insere(*pRGB);
      return Compteur-1;
    }
    	
    throw(MoteurException("l'image n'a pas ete inseree"));
}

ImageNG Moteur::GetImageNG(int id) throw(MoteurException){
	Iterateur<ImageNG> it(imagesNG);

	while(!it.end() && it.getpCur()->valeur.getId() != id)
	{
		it++;
	}
	
	if(!it.end()) 
		return (it.getpCur()->valeur);
	else
		throw(MoteurException("l'image NG n'a pas ete trouvee"));
}

Image* Moteur::GetImage(int id) throw(MoteurException){
	/*--------IMAGESRGB----------*/
	Iterateur<ImageRGB> it(imagesRGB);
	
	while(!it.end() && it.getpCur()->valeur.getId() != id)
	{
		it++;
	}
	
	if(!it.end())
		return &(it.getpCur()->valeur);
	
	/*--------IMAGESNG----------*/
	Iterateur<ImageNG> it1(imagesNG);
	
	while(!it1.end() && it1.getpCur()->valeur.getId() != id)
	{
		it1++;
	}
	
	if(!it1.end())
		return &(it1.getpCur()->valeur);
	
	/*--------IMAGESB----------*/	
	Iterateur<ImageB> it2(imagesB);
	
	while(!it2.end() && it2.getpCur()->valeur.getId() != id)
	{
		it2++;
	}
	
	if(!it2.end())
		return &(it2.getpCur()->valeur);

	throw(MoteurException("l'image n'a pas ete trouvee'"));
}

/*----------------- Methodes publiques ------------------------*/

void Moteur::Start(){
	this->fichierLog << "Demarrage du moteur" <<endl;
	ifstream fich("sauvegarde.dat",ios::in);
	if(fich.is_open())
	{
		Trace("A");
		this->Load(fich);
		fich.close();
	}	
}

void Moteur::Stop(){
	this->fichierLog << "Arret du moteur" <<endl;
	ofstream fich("sauvegarde.dat",ios::out);
	if(fich.is_open())
	{	
		this->Save(fich);
		fich.close();
	}
}

void Moteur::setMessage(const char* chaineget)
{
	if(msgerreur)
	{
		delete msgerreur;
	}
	if(chaineget)
	{
		msgerreur = new char[strlen(chaineget)+1];
		strcpy(msgerreur,chaineget);
	}
	else
	{
	 msgerreur = NULL;
	}
}

const char* Moteur::getMessage() const{
	return msgerreur;
}

void Moteur::Affiche() const{
	cout << "--ImagesNG------------------------------"<<endl;
	imagesNG.Affiche();
	cout << "--ImagesRGB-----------------------------"<<endl;
	imagesRGB.Affiche();
	cout << "--ImagesB-------------------------------"<<endl;
	imagesB.Affiche();
	cout << "----------------------------------------"<<endl;
}

void Moteur::SupprimeImage(int id){
	if(!imagesNG.estVide())
	{
		Iterateur<ImageNG> it(imagesNG);
		while(!it.end() && it.getpCur()->valeur.getId() != id)
		{
			it++;
		}
		if(!it.end())
		{
			it.remove();
			this->fichierLog << "Suppression de l'imageNG: "<<id <<endl;

		}
	}
	else
	if(!imagesRGB.estVide())
	{
		Iterateur<ImageRGB> it1(imagesRGB);
		while(!it1.end() && it1.getpCur()->valeur.getId() != id)
		{
			it1++;
		}
		if(!it1.end())
		{
			it1.remove();
			this->fichierLog << "Suppression de l'imageRGB: "<<id <<endl;
		} 
	}
	else	
	if(!imagesB.estVide())
	{
		Iterateur<ImageRGB> it2(imagesRGB);
		while(!it2.end() && it2.getpCur()->valeur.getId() != id)
		{
			it2++;
		}
		if(!it2.end())
		{
			it2.remove();
			this->fichierLog << "Suppression de l'imageB: "<<id <<endl;
		} 
	}
	else
		throw(MoteurException("l'image a supprimer n'a pas etee trouvée"));
	
}

int Moteur::ImporteImageNG(const char *chemin){
	try
	{
		int id;
		ImageNG img(chemin);
		id = this->Insere(&img);
		this->fichierLog << "Importation de l'imageNG: "<< chemin << "avec l'id: "<<id <<endl;
		return id;	
	}
	catch(WindowSDLexception e)
	{
		throw(e.getMessage());
	}
}

int Moteur::ImporteImageRGB(const char *chemin){
	try
	{
		int id;
		ImageRGB img(chemin);
		id = this->Insere(&img);
		this->fichierLog << "Importation de l'imageRGB: "<< chemin << "avec l'id: "<<id <<endl;
		return id;	
	}
	catch(WindowSDLexception e)
	{
		throw(e.getMessage());
	}
}

void Moteur::VisualiseImage(int id){
	Image* pt = this->GetImage(id);
	pt->Dessine();
}

void Moteur::VisualiseImages(int id1,int id2){
	Image* pt1 = this->GetImage(id1);
	Image* pt2 = this->GetImage(id2);
	
	int larg;
	int haut;
	
	if(pt1->getDimension().getHauteur() > pt2->getDimension().getHauteur())
		haut = pt1->getDimension().getHauteur();
	else
		haut = pt2->getDimension().getHauteur();
	larg = (pt1->getDimension().getLargeur() + pt2->getDimension().getLargeur());
	
//	TraceMethode("fenetre de %d par %d",larg, haut);
//	
//	TraceMethode("image 1 en 0,0 et image 2 en 0,%d",pt1->getDimension().getLargeur());
	WindowSDL::open(larg,haut);
	pt1->Dessine(0,0);
	pt2->Dessine(pt1->getDimension().getLargeur(),0);
	
	WindowSDL::waitClick();
	WindowSDL::close();
}

void Moteur::ExporterBMP(int id, const char* fichier){
	Image* pt = this->GetImage(id);
	pt->exportToBMP(fichier);
	this->fichierLog << "Exportation de l'image: "<<id <<"vers: "<< fichier <<endl;
}

int Moteur::AugmenteLuminosite(int id, int val){
	int idretour;
	ImageNG im(GetImageNG(id));
	im = im+val;
	idretour = Insere(&im);
	this->fichierLog << "Augmentation de la Luminosite de l'image: "<< id << " + " << val << " --> " << idretour << endl;
	return idretour;
}

int Moteur::DiminueLuminosite(int id, int val){
	int idretour;
	ImageNG im(GetImageNG(id));
	im = im-val;
	idretour = Insere(&im);
	this->fichierLog << "Diminution de la Luminosite de l'image: "<< id << " - " << val << " --> " << idretour << endl;
	return idretour;
}

int Moteur::Soustraire(int id1, int id2){
	int idretour;
	ImageNG im1(GetImageNG(id1));
	ImageNG im2(GetImageNG(id2));
	ImageNG imOut(im1-im2);
	idretour = Insere(&imOut);
	this->fichierLog << "Soustraction de l'image: " << id1 << "par l'image: " << id2 << " --> " << idretour << endl;
	return idretour;
	
}

int Moteur::Seuillage(int id, int seuil){
	int idretour;
	ImageNG image(GetImageNG(id));
	ImageB imgOut = Traitements::Seuillage(image,seuil);
	idretour = Insere(&imgOut);
	this->fichierLog << "Seuillage de l'image: " << id << "au niveau: " << seuil << " --> " << idretour << endl;
	return idretour;
}

int Moteur::Negatif(int id){
	int idretour;
	Image *pt = GetImage(id);
	ImageNG* pNG = dynamic_cast<ImageNG*>(pt);
    if (pNG != NULL) 
    {
    	ImageNG negatif(*pNG);
      negatif = Traitements::Negatif(negatif);
      negatif.setNom("negatif");
      idretour = Insere(&negatif);
      this->fichierLog << "Negatif de l'imageNG: " << id << " --> " << idretour << endl;
      return idretour;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pt);
    if (pRGB != NULL) 
    {
      // negatifRGB
      return -1;
    }	
    // image B
    return -1;
}

int Moteur::FiltreMedian(int id, int tailleFiltre){
	int idretour;
	Image *pt = GetImage(id);
	ImageNG* pNG = dynamic_cast<ImageNG*>(pt);
    if (pNG != NULL) 
    {
    	ImageNG imgOut(*pNG);
      imgOut = Traitements::FiltreMedian(imgOut,tailleFiltre);
      idretour = Insere(&imgOut);
      this->fichierLog << "FiltreMedian de l'imageNG: " << id <<" Filtre: "<< tailleFiltre <<" --> " << idretour << endl;
      return idretour;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pt);
    if (pRGB != NULL) 
    {
      // FiltreMedianRGB
      return -1;
    }	
    // image B
    return -1;
}

int Moteur::FiltreMoyenneur(int id, int tailleFiltre){
	int idretour;
	Image *pt = GetImage(id);
	ImageNG* pNG = dynamic_cast<ImageNG*>(pt);
    if (pNG != NULL) 
    {
    	ImageNG imgOut(*pNG);
      imgOut = Traitements::FiltreMoyenneur(imgOut,tailleFiltre);
      idretour = Insere(&imgOut);
      this->fichierLog << "FiltreMoyenneur de l'imageNG: " << id <<" Filtre: "<< tailleFiltre << " --> " << idretour << endl;
      return idretour;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pt);
    if (pRGB != NULL) 
    {
     	ImageRGB imgOut(*pRGB);
      imgOut = Traitements::FiltreMoyenneur(imgOut,tailleFiltre);
      idretour = Insere(&imgOut);
      this->fichierLog << "FiltreMoyenneur de l'imageRGB: " << id <<" Filtre: "<< tailleFiltre << " --> " << idretour << endl;
      return idretour;
    }	
    // image B
    return -1;
}

int Moteur::Dilatation(int id, int tailleFiltre){
	int idretour;
	Image *pt = GetImage(id);
	ImageNG* pNG = dynamic_cast<ImageNG*>(pt);
    if (pNG != NULL) 
    {
    	ImageNG imgOut(*pNG);
      imgOut = Traitements::Dilatation(imgOut,tailleFiltre);
      idretour = Insere(&imgOut);
      this->fichierLog << "Dilatation de l'imageNG: " << id <<" Filtre: "<< tailleFiltre << " --> " << idretour << endl;
      return idretour;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pt);
    if (pRGB != NULL) 
    {
     	return -1;
    }	
    // image B
    return -1;

}

int Moteur::Erosion(int id, int tailleFiltre){
	int idretour;
	Image *pt = GetImage(id);
	ImageNG* pNG = dynamic_cast<ImageNG*>(pt);
    if (pNG != NULL) 
    {
    	ImageNG imgOut(*pNG);
      imgOut = Traitements::Erosion(imgOut,tailleFiltre);
      idretour = Insere(&imgOut);
       this->fichierLog << "Erosion de l'imageNG: " << id <<" Filtre: "<< tailleFiltre << " --> " << idretour << endl;
      return idretour;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pt);
    if (pRGB != NULL) 
    {
     	return -1;
    }	
    // image B
    return -1;
}

int Moteur::FiltreMoyenneurSelection(int id, int tailleFiltre){
	int idretour;
	Image *pt = GetImage(id);
	WindowSDLclick click;
	WindowSDL::open(pt->getDimension().getLargeur(),pt->getDimension().getHauteur());
	pt->Dessine(0,0);
	
	click = WindowSDL::waitClick();
	Pixel p1(click.getX(),click.getY());
	Trace("click en [%d-%d]",click.getX(), click.getY());
	click = WindowSDL::waitClick();
	Pixel p2(click.getX(),click.getY());
	Trace("click en [%d-%d]",click.getX(), click.getY());
	
	ImageNG* pNG = dynamic_cast<ImageNG*>(pt);
    if (pNG != NULL) 
    {
    	ImageNG imgOut(*pNG);
      imgOut = Traitements::FiltreMoyenneur(imgOut,tailleFiltre,p1,p2);
      imgOut.Dessine(0,0);
      WindowSDL::waitClick();
      WindowSDL::close();
      idretour = Insere(&imgOut);
      this->fichierLog << "FiltreMoyenneurSelection de l'imageNG: " << id <<" Filtre: "<< tailleFiltre << " --> " << idretour << endl;
      return idretour;
    }
    ImageRGB* pRGB = dynamic_cast<ImageRGB*>(pt);
    if (pRGB != NULL) 
    {
     	ImageRGB imgOut(*pRGB);
      imgOut = Traitements::FiltreMoyenneur(imgOut,tailleFiltre,p1,p2);
      imgOut.Dessine(0,0);
      WindowSDL::waitClick();
      WindowSDL::close();
      idretour = Insere(&imgOut);
       this->fichierLog << "FiltreMoyenneurSelection de l'imageRGB: " << id <<" Filtre: "<< tailleFiltre << " --> " << idretour << endl;
      return idretour;
    }	
	WindowSDL::close();
	return -1;	
}

void Moteur::Save(ofstream &fichier) {
	char type = 'X';
	if(!imagesNG.estVide())
	{
		this->fichierLog << "Save des imagesNG "<< endl;
		Iterateur<ImageNG> it1(imagesNG);
		type = 'G';
		while(!it1.end())
		{
			fichier.write((char*)&type,sizeof(char));
			it1.getpCur()->valeur.Save(fichier);
			it1++;
		}
	}
	
	if(!imagesRGB.estVide())
	{
		this->fichierLog << "Save des imagesRGB" << endl;
		Iterateur<ImageRGB> it2(imagesRGB);
		type = 'C';
		while(!it2.end())
		{
			fichier.write((char*)&type,sizeof(char));
			it2.getpCur()->valeur.Save(fichier);
			it2++;
		}
	}
	
	if(!imagesB.estVide())
	{	
		this->fichierLog << "Save des imagesB"<< endl;
		Iterateur<ImageB> it3(imagesB);
		type = 'B';
		while(!it3.end())
		{
			fichier.write((char*)&type,sizeof(char));
			it3.getpCur()->valeur.Save(fichier);
			it3++;
		}
	}
	type = 'O';
	fichier.write((char*)&type,sizeof(char));
	Trace("fin");
}

void Moteur::Load(ifstream &fichier){
	char type = 'X';
	ImageB imb;
	ImageRGB imrgb;
	ImageNG imng;
	
	this->fichierLog << "Load des images" << endl;
	fichier.read((char*)&type,sizeof(char));
	while(type != 'O')
	{
		switch(type)
		{
			case 'G':
				imng.Load(fichier);
				this->Insere(&imng);
				break;
			case 'C':
				imrgb.Load(fichier);
				this->Insere(&imrgb);
				break;
			case 'B':
				imb.Load(fichier);
				this->Insere(&imb);
				break;
			default: 
				throw(MoteurException("le fichier est corrompu"));
		}
		fichier.read((char*)&type,sizeof(char));
	}
	
}

int Moteur::ImporteCSV(const char* fichiercsv){
	char Tampon[80];
	char Type[80];
	char Image[80];
	char *token;
	int nombre = 0;
	ifstream fb(fichiercsv,ios::in);
	if(!fb.is_open())
		throw(MoteurException("le fichier n'est pas accesible"));
	while(fb >> Tampon)
	{
		cout << Tampon << endl;
		token = strtok(Tampon,":");
		strcpy(Type,token);
		token = strtok(NULL,"\n");
		strcpy(Image,token);
		if(strcmp("NG",Type) == 0)
		{
			try
			{
				ImageNG im(Image);
				this->Insere(&im);
				nombre++;
			}
			catch(WindowSDLexception e)
			{
				cout << "image erronée" <<endl;
			}
			
		}
		else
		if(strcmp("RGB",Type) == 0)
		{
			try
			{
				ImageRGB im(Image);
				this->Insere(&im);
				nombre++;
			}
			catch(WindowSDLexception e)
			{
				cout << "image erronée" <<endl;
			}
		}
		else
			cout << "type non supporté" <<endl;				
	}
	return nombre;		
}
