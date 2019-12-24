#include "UI.h"

	UI::UI(Moteur* m):moteur(m){}
	void UI::Menu(){
		EffEcran();
		AffChaine("",1,1,GRAS);
		cout << "**************************************************************************************************"<<endl;
		cout << "****MiniPhotoshop en C++**************************************************************************"<<endl;
		cout << "**************************************************************************************************"<<endl<<endl;
		moteur->Affiche();
		
		Titre("**********Menu General****************************************************************************");
		cout << " O. Quitter" <<endl;
		cout << " 1. Visualiser une image et ses caracteristiques"<<endl;
		cout << " 2. Visulaiser deux images simultanement"<<endl;
		cout << " 3. Importer un ensemble d'images à partir d'un fichier csv"<<endl;
		cout << " 4. Exporter vers BMP"<<endl;
		cout << " 5. Supprimer une Image"<<endl;
		Titre("**********Menu Images*****************************************************************************");
		cout << "11. Filtre Moyenneur" <<endl;
		cout << "12. Filtre Median"<<endl;
		cout << "13. Erosion"<<endl;
		cout << "14. Dilatation"<<endl;
		cout << "15. Negatif"<<endl;
		Titre("**********Menu ImageNG*****************************************************************************");
		cout << " 6. \033[34;01m Importer une imageNG \033[0m" <<endl;
		cout << " 7. Augmenter la luminosite" <<endl;
		cout << " 8. Diminuer la luminosite" <<endl;
		cout << " 9. Soustraire deux images" <<endl;
		cout << "10. Seuillage" <<endl;
		Titre("**********Menu ImageRGB****************************************************************************");
		cout << "16. \033[34;01m Importer une ImageRGB \033[0m"<<endl;
		Titre("**********Menu ImageB******************************************************************************");
		cout << "17. Changer les couleurs des booleens"<<endl;
		Titre("***************************************************************************************************");
		if(moteur->getMessage())
		{
			cout  <<"\033[31;01m" <<  moteur->getMessage() << "\033[0m"  << endl;
			moteur->setMessage("");
		}
			
		else
			cout << endl;
		cout << endl;
	}
	
	void UI::Start(){
		int ch;
		int quitter = 0;
		moteur->Start();
		
		
		while(quitter == 0)
		{
			this->Menu();
			cout << "Choix : ";
		  	cin >> ch;
		  	cin.ignore();
		  	switch(ch)
		  	{
		  		case 0: quitter = 1; break;
		  		
		  		case 1:
		  			try{
		  					int num;
				  			cout << "Encodez l'id à afficher: ";
				  			cin >> num;
				  			moteur->VisualiseImage(num);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  		
		  		case 2:
		  			try{
			  			int num1;
			  			int num2;
			  			cout << "Encodez l'id1 à afficher: ";
			  			cin >> num1;
			  			cout << "Encodez l'id2 à afficher: ";
			  			cin >> num2;
			  			moteur->VisualiseImages(num1,num2);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  		
		  		case 3:
		  			try{
		  				char Tampon[80];
		  				int nombre = 0;
		  				cout << "Encodez le chemin d'acces du csv: ";
		  				cin >> Tampon;
		  				nombre = moteur->ImporteCSV(Tampon);
		  				cout << nombre << "Images importées correctement" <<endl;
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}
		  			break;
		  		
		  		case 4:
		  			try{
			  			int num;
			  			char Tampon[80];
			  			cout << "Encodez l'id a exporter: ";
			  			cin >> num;
			  			cout << "Encodez le nom de sortie: ";
			  			cin >> Tampon;
			  			moteur->ExporterBMP(num,Tampon);
			  		}
			  		catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
			  		break;
			  	
			  	case 5: 
			  		try{
			  			int num;
			  			cout << "Encodez l'id a supprimer: ";
			  			cin >> num;
			  			moteur->SupprimeImage(num);
			  		}
			  		catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}		
			  		break;
		  			
		  		case 6:
		  			try{
		  				char Tampon[80];
		  				int numret;
		  				cout << "Encodez le chemin d'acces: ";
		  				cin >> Tampon;
		  				numret = moteur->ImporteImageNG(Tampon);
		  				moteur->VisualiseImage(numret);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}
		  			catch(...)
		  			{
		  				//AfficheErreur("Erreur d'encodage");
		  			}	
		  			break;
		  			
		  		case 7:
		  			try{
		  				int num,numret,lum;
			  			cout << "Encodez l'id de l'image à augmenter la luminosité: ";
			  			cin >> num;
			  			cout << "De combien voulez vous augmenter: ";
			  			cin >> lum;
			  			numret = moteur->AugmenteLuminosite(num,lum);
			  			moteur->VisualiseImages(num,numret);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  		
		  		case 8:
		  			try{
		  				int num,numret,lum;
			  			cout << "Encodez l'id de l'image à diminuer la luminosité: ";
			  			cin >> num;
			  			cout << "De combien voulez vous diminuer: ";
			  			cin >> lum;
			  			numret = moteur->DiminueLuminosite(num,lum);
			  			moteur->VisualiseImages(num,numret);
		  			
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  			
		  		case 9:
		  			try{
		  				int num1,num2,numret;
			  			cout << "Encodez l'id1 à soustraire: ";
			  			cin >> num1;
			  			cout << "Encodez l'id2 à soustraire: ";
			  			cin >> num2;
			  			numret = moteur->Soustraire(num1,num2);
			  			moteur->VisualiseImages(num1,numret);
		  			
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  		
		  		case 10:
		  			try{
		  				int num,numret,seuil;
			  			cout << "Encodez l'id de l'image à seuiller: ";
			  			cin >> num;
			  			cout << "Filtre: ";
			  			cin >> seuil;
			  			numret = moteur->Seuillage(num,seuil);
			  			moteur->VisualiseImages(num,numret);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  			
		  		case 11:
		  			try{
		  				int num,numret,filtre,type;
			  			cout << "Encodez l'id de l'image à Flouter: ";
			  			cin >> num;
			  			cout << "Filtre complet(1) ou filtre partiel(2): ";
			  			cin >> type;
			  			cout << "Filtre: ";
			  			cin >> filtre;
			  			switch(type)
			  			{
			  				case 1: numret = moteur->FiltreMoyenneur(num,filtre); break;
			  				case 2: numret = moteur->FiltreMoyenneurSelection(num,filtre); break;
			  				default: AfficheErreur("mauvais encodage");
			  			}
			  			moteur->VisualiseImages(num,numret);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  			
		  		case 12:
		  			try{
		  				int num,numret,filtre;
			  			cout << "Encodez l'id de l'image à Nettoyer: ";
			  			cin >> num;
			  			cout << "Filtre: ";
			  			cin >> filtre;
			  			numret = moteur->FiltreMedian(num,filtre);	
			  			moteur->VisualiseImages(num,numret);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  			
		  		case 13:
		  			try{
		  				int num,numret,filtre;
			  			cout << "Encodez l'id de l'image à Eroser: ";
			  			cin >> num;
			  			cout << "Filtre: ";
			  			cin >> filtre;
			  			numret = moteur->Erosion(num,filtre);	
			  			moteur->VisualiseImages(num,numret);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  			
		  		case 14:
		  			try{
		  				int num,numret,filtre;
			  			cout << "Encodez l'id de l'image à Dilater: ";
			  			cin >> num;
			  			cout << "Filtre: ";
			  			cin >> filtre;
			  			numret = moteur->Dilatation(num,filtre);
			  			moteur->VisualiseImages(num,numret);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  			
		  		case 15:
		  			try{
		  				int num,numret;
			  			cout << "Encodez l'id de l'image à Inverse: ";
			  			cin >> num;
			  			numret = moteur->Negatif(num);
			  			moteur->VisualiseImages(num,numret);
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  			
		  		case 16:
		  			try{
		  				char Tampon[80];
		  				int numret;
		  				cout << "Encodez le chemin d'acces: ";
		  				cin >> Tampon;
		  				numret = moteur->ImporteImageRGB(Tampon);
		  				moteur->VisualiseImage(numret);		  				
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  			
		  		case 17:
		  			try{
		  				Couleur c1, c2;
		  				cout << "-----Couleur1-----"<<endl;
		  				cin >> c1;
		  				cout << "-----Couleur2-----"<<endl;
		  				cin >> c2;
		  				ImageB::couleurTrue = c1;
  						ImageB::couleurFalse = c2;	
		  			}
		  			catch(MoteurException e)
		  			{
		  				AfficheErreur(e.getMessage());
		  			}	
		  			break;
		  			
//		  		case 18:
//		  			{
//		  			
//		  			}
//		  			break;
		  		
		  		default: AfficheErreur("numero non valide");
			}
			
		}
		moteur->Stop();
		EffEcran();
		Titre("Aurevoir");
	}
	
void UI::AfficheErreur(const char* erreur)
{
	moteur->setMessage(erreur);
}
