#include "Moteur.h"
#include "RGBException.h"

int main()
{
	try
	{
	
	
	Moteur m;
	m.Affiche();
	m.ImporteImageNG("../images/lena.bmp");
	m.ImporteImageRGB("../images/lena.bmp");

	m.AugmenteLuminosite(0,50);
	m.DiminueLuminosite(0,50);
	//m.Affiche();
	//m.VisualiseImage(1);
	m.VisualiseImages(2,3);
	m.Soustraire(2,3);
	
	m.Seuillage(0,125);
	m.Negatif(0);
	m.FiltreMedian(0,3);
	m.FiltreMoyenneur(1,3);
	m.VisualiseImage(8);
	m.Erosion(0,3);
	m.Dilatation(0,3);
	m.VisualiseImages(9,10);
	m.FiltreMoyenneurSelection(0,13);
	m.FiltreMoyenneurSelection(1,13);
	m.Affiche();
	//m.ExporterBMP(1,"../images/lol.bmp");
	}
	catch(MoteurException e)
	{
	cout << "ERREUR: " << e.getMessage() << endl;
	}
	catch(BaseException e)
	{
	cout <<"ERREUR: " << e.getMessage() << endl;
	}
	Pause();
 
	
	
	
	return 0;
}
