#include "Moteur.h"
#include "RGBException.h"

int main()
{
	Moteur m;
	ImageNG imgfin;
	ImageNG img("../images/joconde.bmp");
	img.setId(1);
	m.Insere(&img);
	ImageNG img1("../images/lena.bmp");
	img1.setId(2);
	m.Insere(&img1);
	
	imgfin = m.GetImageNG(2);
	imgfin.Dessine();
	
	m.Affiche();
	
	m.SupprimeImage(2);
	imgfin.Dessine();
	m.Affiche();
	m.SupprimeImage(1);

	m.Affiche();
	
	
	
	
	return 0;
}
