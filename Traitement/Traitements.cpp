#include "Traitements.h"

ImageB Traitements::Seuillage(const ImageNG& imgNG,int seuil){
	ImageB imgB;
	imgB.setDimension(imgNG.getDimension());
	
	int larg = imgB.getDimension().getLargeur();
	int haut = imgB.getDimension().getHauteur();
	
	for(int x=0; x < larg; x++)
		for(int y=0; y < haut; y++)
			{
				if(imgNG.getPixel(x,y) > seuil)
					imgB.setPixel(x,y,true);
				else
					imgB.setPixel(x,y,false);
			}
	return imgB;
}

ImageNG Traitements::FiltreMoyenneur(const ImageNG& imageIn, int taille, Pixel p1, Pixel p2)
{
	if(taille%2 == 0)
		throw(BaseException("la taille de la modification doit etre impaire"));
	ImageNG imgOut(imageIn);
	int moyenne;
	int compteur;
	int xbase1, xbase2;
	int ybase1, ybase2;
	if(p1 == p2)
	{
		ybase1 = p1.getY();
		ybase2 = imageIn.getDimension().getHauteur();
		xbase1 = p1.getX();
		xbase2 = imageIn.getDimension().getLargeur();
	}
	else
	{
		if(p1.getY() < p2.getY())
		{
			ybase1 = p1.getY();
			ybase2 = p2.getY();
		}		
		else
		{
			ybase1 = p2.getY();
			ybase2 = p1.getY();
		}	
			
		
		if(p1.getY() < p2.getY())
		{
			xbase1 = p1.getX();
			xbase2 = p2.getX();
		}		
		else
		{
			xbase1 = p2.getX();
			xbase2 = p1.getX();
		}	
	}	 
	
	for(int x = xbase1; x < imageIn.getDimension().getLargeur() && x < xbase2; x++)
		for(int y = ybase1; y < imageIn.getDimension().getHauteur() && y < ybase2; y++)
		{
			compteur = 0;
			moyenne = 0;
			for(int x1 = x-(taille/2); x1 <= x+(taille/2); x1++)
			{
				for(int y1 = y-(taille/2); y1 <= y+(taille/2); y1++)
				{
					
					if(!(x1 < 0 || y1 < 0 || x1 > (imageIn.getDimension().getLargeur()-1) || y1 > (imageIn.getDimension().getHauteur()-1)))
						{
							moyenne += imageIn.getPixel(x1,y1);
							compteur++; 
							//Trace("BON pour le point [%d,%d], on cherche [%d,%d] avec valeur: %d",x,y,x1,y1,imageIn.getPixel(x1,y1));
						}
						
				}
			}
			moyenne = moyenne / compteur;
//			Trace("moyenne: %d", moyenne);
			imgOut.setPixel(x,y,moyenne);
			//exit(0);
		}
	return imgOut;
}

ImageRGB Traitements::FiltreMoyenneur(const ImageRGB& imageIn, int taille, Pixel p1, Pixel p2)
{
	if(taille%2 == 0)
		throw(BaseException("la taille de la modification doit etre impaire"));
		
	ImageNG imageRouge(imageIn.getRouge());
	ImageNG imageVert(imageIn.getVert());
	ImageNG imageBleu(imageIn.getBleu());
	ImageRGB imageOut(imageIn);
	
	imageRouge = FiltreMoyenneur(imageRouge, taille, p1, p2);
	imageVert = FiltreMoyenneur(imageVert, taille, p1, p2);
	imageBleu = FiltreMoyenneur(imageBleu, taille, p1, p2);
	
	imageOut.setRGB(imageRouge, imageVert, imageBleu);
	return imageOut;	
}

ImageNG Traitements::FiltreMedian(const ImageNG& imageIn, int taille){
	if(taille%2 == 0)
			throw(BaseException("la taille de la modification doit etre impaire"));
			
	ImageNG imgOut(imageIn);
	int compteur;
	for(int x = 0; x < imageIn.getDimension().getLargeur(); x++)
		for(int y = 0; y < imageIn.getDimension().getHauteur(); y++)
		{
			ListeTriee<int> liste;
			Iterateur<int> iterateur(liste);
			compteur = 0;
			for(int x1 = x-(taille/2); x1 <= x+(taille/2); x1++)
			{
				for(int y1 = y-(taille/2); y1 <= y+(taille/2); y1++)
				{
					if(!(x1 < 0 || y1 < 0 || x1 > (imageIn.getDimension().getLargeur()-1) || y1 > (imageIn.getDimension().getHauteur()-1)))
						{
							liste.insere(imageIn.getPixel(x1,y1));
							compteur++;
						}
				}
			}
			compteur = compteur/2;
			iterateur.reset();
			for(int i = 0; i < compteur; i++)
			{
				iterateur++;
			}
			imgOut.setPixel(x,y,iterateur.remove());
		}
	return imgOut;
}

ImageRGB Traitements::FiltreMedian(const ImageRGB& imageIn, int taille)
{
	if(taille%2 == 0)
		throw(BaseException("la taille de la modification doit etre impaire"));
		
	ImageNG imageRouge(imageIn.getRouge());
	ImageNG imageVert(imageIn.getVert());
	ImageNG imageBleu(imageIn.getBleu());
	ImageRGB imageOut(imageIn);
	
	imageRouge = FiltreMedian(imageRouge, taille);
	imageVert = FiltreMedian(imageVert, taille);
	imageBleu = FiltreMedian(imageBleu, taille);
	
	imageOut.setRGB(imageRouge, imageVert, imageBleu);
	return imageOut;	
}

ImageNG Traitements::Erosion(const ImageNG& imageIn, int taille){
	if(taille%2 == 0)
		throw(BaseException("la taille de la modification doit etre impaire"));
		
	ImageNG imgOut(imageIn);
	for(int x = 0; x < imageIn.getDimension().getLargeur(); x++)
		for(int y = 0; y < imageIn.getDimension().getHauteur(); y++)
		{
			ListeTriee<int> liste;
			Iterateur<int> iterateur(liste);
			for(int x1 = x-(taille/2); x1 <= x+(taille/2); x1++)
			{
				for(int y1 = y-(taille/2); y1 <= y+(taille/2); y1++)
				{
					
					if(x1 < 0 || y1 < 0 || x1 > (imageIn.getDimension().getLargeur()-1) || y1 > (imageIn.getDimension().getHauteur()-1))
						;//Trace("MAUVAIS pour le point [%d,%d], on cherche [%d,%d]",x,y,x1,y1);
					else
						{
							liste.insere(imageIn.getPixel(x1,y1));
							//Trace("BON pour le point [%d,%d], on cherche [%d,%d] avec valeur: %d",x,y,x1,y1,imageIn.getPixel(x1,y1));
						}
						
				}
			}
			iterateur.reset();
			imgOut.setPixel(x,y,iterateur.remove());
			//exit(0);
		}
	return imgOut;
}

ImageRGB Traitements::Erosion(const ImageRGB& imageIn, int taille){
	if(taille%2 == 0)
		throw(BaseException("la taille de la modification doit etre impaire"));
		
	ImageNG imageRouge(imageIn.getRouge());
	ImageNG imageVert(imageIn.getVert());
	ImageNG imageBleu(imageIn.getBleu());
	ImageRGB imageOut(imageIn);
	
	imageRouge = Erosion(imageRouge, taille);
	imageVert = Erosion(imageVert, taille);
	imageBleu = Erosion(imageBleu, taille);
	
	imageOut.setRGB(imageRouge, imageVert, imageBleu);
	return imageOut;	
}

ImageNG Traitements::Dilatation(const ImageNG& imageIn, int taille){
	if(taille%2 == 0)
		throw(BaseException("la taille de la modification doit etre impaire"));
		
	ImageNG imgOut(imageIn);
	int compteur;
	for(int x = 0; x < imageIn.getDimension().getLargeur(); x++)
		for(int y = 0; y < imageIn.getDimension().getHauteur(); y++)
		{
			ListeTriee<int> liste;
			Iterateur<int> iterateur(liste);
			compteur = 0;
			for(int x1 = x-(taille/2); x1 <= x+(taille/2); x1++)
			{
				for(int y1 = y-(taille/2); y1 <= y+(taille/2); y1++)
				{
					
					if(x1 < 0 || y1 < 0 || x1 > (imageIn.getDimension().getLargeur()-1) || y1 > (imageIn.getDimension().getHauteur()-1))
						;//Trace("MAUVAIS pour le point [%d,%d], on cherche [%d,%d]",x,y,x1,y1);
					else
						{
							liste.insere(imageIn.getPixel(x1,y1));
							compteur++; 
							//Trace("BON pour le point [%d,%d], on cherche [%d,%d] avec valeur: %d",x,y,x1,y1,imageIn.getPixel(x1,y1));
						}
						
				}
			}
			iterateur.reset();
			for(int i = 0; i < compteur-1; i++)
			{
				iterateur++;
			}
//			Trace("moyenne: %d", moyenne);
			imgOut.setPixel(x,y,iterateur.remove());
			//exit(0);
		}
	return imgOut;
}

ImageRGB Traitements::Dilatation(const ImageRGB& imageIn, int taille){
	if(taille%2 == 0)
		throw(BaseException("la taille de la modification doit etre impaire"));
		
	ImageNG imageRouge(imageIn.getRouge());
	ImageNG imageVert(imageIn.getVert());
	ImageNG imageBleu(imageIn.getBleu());
	ImageRGB imageOut(imageIn);
	
	imageRouge = Dilatation(imageRouge, taille);
	imageVert = Dilatation(imageVert, taille);
	imageBleu = Dilatation(imageBleu, taille);
	
	imageOut.setRGB(imageRouge, imageVert, imageBleu);
	return imageOut;	
}

ImageNG Traitements::Negatif(const ImageNG& imageIn)
{
	ImageNG imgOut(imageIn);
	for(int x = 0; x < imageIn.getDimension().getLargeur(); x++)
		for(int y = 0; y < imageIn.getDimension().getHauteur(); y++)
			imgOut.setPixel(x,y,(255-imageIn.getPixel(x,y)));
	return imgOut;
}

ImageRGB Traitements::Negatif(const ImageRGB& imageIn){
		
	ImageNG imageRouge(imageIn.getRouge());
	ImageNG imageVert(imageIn.getVert());
	ImageNG imageBleu(imageIn.getBleu());
	ImageRGB imageOut(imageIn);
	
	imageRouge = Negatif(imageRouge);
	imageVert = Negatif(imageVert);
	imageBleu = Negatif(imageBleu);
	
	imageOut.setRGB(imageRouge, imageVert, imageBleu);
	return imageOut;	
}
