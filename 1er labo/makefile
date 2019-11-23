.SILENT:
ECRAN = $(HOME)/Documents/C++/Ecran
IMAGE = $(HOME)/Documents/C++/Image
DIM = $(HOME)/Documents/C++/Dimension
SDL = $(HOME)/Documents/C++/WindowSDL
PIX = $(HOME)/Documents/C++/Pixel
COUL = $(HOME)/Documents/C++/Couleur
EXCEPT = $(HOME)/Documents/C++/Exception
MATRICE = $(HOME)/Documents/C++/Matrice
LISTE = $(HOME)/Documents/C++/Liste
TRAITEMENT = $(HOME)/Documents/C++/Traitement
APPLICATION = $(HOME)/Documents/C++/Application

INCL = -I $(ECRAN) -I $(DIM) -I $(PIX) -I $(SDL) -I $(IMAGE) -I $(COUL) -I $(EXCEPT) -I $(MATRICE) -I $(LISTE) -I $(TRAITEMENT) -I $(APPLICATION)
GPP = g++ -g -m64 -Wall -D SUN -D CPP -lSDL -lpthread $(INCL) #-D DEV -D DEVPLUS
IMG_O = Image.o ImageNG.o ImageRGB.o ImageB.o
PIXEL_O = Pixel.o PixelNG.o PixelRGB.o PixelB.o
EXCEPT_O = BaseException.o RGBException.o XYException.o MoteurException.o
LISTE_O = ListeBase.o Liste.o ListeTriee.o

OBJ = $(EXCEPT_O) $(PIXEL_O) $(IMG_O) $(LISTE_O) Dimension.o  Ecran.o WindowSDL.o WindowSDLimage.o WindowSDLexception.o WindowSDLclick.o Couleur.o Matrice.o Iterateur.o Traitements.o Moteur.o UI.o


ALL: Main

clean: 
	echo Repartons de zero;
	rm *.o;
	make;

Test1: $(OBJ) Test1.o
	echo creation du fichier executable 1;
	$(GPP) -o Test1 Test1.o $(OBJ);

Test2: $(OBJ) Test2.o
	echo creation du fichier executable 2;
	$(GPP) -o Test2 Test2.o $(OBJ);
	
Test3: $(OBJ) Test3.o
	echo creation du fichier executable 3;
	$(GPP) -o Test3 Test3.o $(OBJ);
	
Test4: $(OBJ) Test4.o
	echo creation du fichier executable 4;
	$(GPP) -o Test4 Test4.o  $(OBJ);
	
Test5: $(OBJ) Test5.o
	echo creation du fichier executable 5;
	$(GPP) -o Test5 Test5.o $(OBJ);
	
Test6: $(OBJ) Test6.o
	echo creation du fichier executable 6;
	$(GPP) -o Test6 Test6.o $(OBJ);

Test7: $(OBJ) Test7.o
	echo creation du fichier executable 7;
	$(GPP) -o Test7 Test7.o $(OBJ);
	
Test8: $(OBJ) Test8.o
	echo creation du fichier executable 8;
	$(GPP) -o Test8 Test8.o $(OBJ);

Test9: $(OBJ) Test9.o 
	echo creation du fichier executable 9;
	$(GPP) -o Test9 Test9.o $(OBJ);

Test10: $(OBJ) Test10.o
	echo creation du fichier executable 10;
	$(GPP) -o Test10 Test10.o $(OBJ);
	
mTestEgal2019: $(OBJ) mTestEgal2019.o
	echo creation du fichier executable de test;
	$(GPP) -o mTestEgal2019 mTestEgal2019.o $(OBJ);

Main: $(OBJ) main.o
	echo creation du Main;
	$(GPP) -o Main main.o $(OBJ);
	
Ecran.o:	$(ECRAN)/Ecran.cpp $(ECRAN)/Ecran.h
	echo creation de Ecran.o;
	$(GPP) -c $(ECRAN)/Ecran.cpp;

Image.o: $(IMAGE)/Image.cpp $(IMAGE)/Image.h
	echo creation de Image.o;
	$(GPP) -c $(IMAGE)/Image.cpp;

ImageNG.o: $(IMAGE)/ImageNG.cpp $(IMAGE)/ImageNG.h
	echo creation de ImageNG.o;
	$(GPP) -c $(IMAGE)/ImageNG.cpp;
	
ImageRGB.o: $(IMAGE)/ImageRGB.cpp $(IMAGE)/ImageRGB.h
	echo creation de ImageRGB.o;
	$(GPP) -c $(IMAGE)/ImageRGB.cpp;
	
ImageB.o: $(IMAGE)/ImageB.cpp $(IMAGE)/ImageB.h
	echo creation de ImageB.o;
	$(GPP) -c $(IMAGE)/ImageB.cpp;

Dimension.o: $(DIM)/Dimension.cpp $(DIM)/Dimension.h
	echo creation de Dimension.o;
	$(GPP) -c $(DIM)/Dimension.cpp;
	
WindowSDL.o: $(SDL)/WindowSDL.cpp $(SDL)/WindowSDL.h
	echo creation de WindowSDL.o;
	$(GPP) -c $(SDL)/WindowSDL.cpp;
	
WindowSDLimage.o: $(SDL)/WindowSDLimage.cpp $(SDL)/WindowSDLimage.h
	echo creation de WindowSDLimage.o;
	$(GPP) -c $(SDL)/WindowSDLimage.cpp;
	
WindowSDLexception.o:	$(SDL)/WindowSDLexception.cpp $(SDL)/WindowSDLexception.h
	echo Creation de WindowSDLexception.o ...
	$(GPP) -c $(SDL)/WindowSDLexception.cpp

WindowSDLclick.o:	$(SDL)/WindowSDLclick.cpp $(SDL)/WindowSDLclick.h
	echo Creation de WindowSDLclick.o ...
	$(GPP) -c $(SDL)/WindowSDLclick.cpp

Pixel.o: $(PIX)/Pixel.cpp $(PIX)/Pixel.h
	echo creation de Pixel.o;
	$(GPP) -c $(PIX)/Pixel.cpp;
		
PixelNG.o: $(PIX)/PixelNG.cpp $(PIX)/PixelNG.h
	echo creation de PixelNG.o;
	$(GPP) -c $(PIX)/PixelNG.cpp;
	
PixelRGB.o: $(PIX)/PixelRGB.cpp $(PIX)/PixelRGB.h
	echo creation de PixelRGB.o;
	$(GPP) -c $(PIX)/PixelRGB.cpp;
	
PixelB.o: $(PIX)/PixelB.cpp $(PIX)/PixelB.h
	echo creation de PixelB.o;
	$(GPP) -c $(PIX)/PixelB.cpp;
	
Couleur.o: $(COUL)/Couleur.cpp $(COUL)/Couleur.h
	echo creation de Couleur.o;
	$(GPP) -c $(COUL)/Couleur.cpp;
	
BaseException.o: $(EXCEPT)/BaseException.cpp $(EXCEPT)/BaseException.h
	echo creation de BaseException.o;
	$(GPP) -c $(EXCEPT)/BaseException.cpp;

RGBException.o: $(EXCEPT)/RGBException.cpp $(EXCEPT)/RGBException.h
	echo creation de RGBException.o;
	$(GPP) -c $(EXCEPT)/RGBException.cpp;
	
XYException.o: $(EXCEPT)/XYException.cpp $(EXCEPT)/XYException.h
	echo creation de XYException.o;
	$(GPP) -c $(EXCEPT)/XYException.cpp;	

MoteurException.o: $(EXCEPT)/MoteurException.cpp $(EXCEPT)/MoteurException.h
	echo creation de MoteurException.o;
	$(GPP) -c $(EXCEPT)/MoteurException.cpp;

Matrice.o: $(MATRICE)/Matrice.cpp $(MATRICE)/Matrice.h
	echo creation de Matrice.o;
	$(GPP) -c $(MATRICE)/Matrice.cpp; 

ListeBase.o: $(LISTE)/ListeBase.cpp $(LISTE)/ListeBase.h
	echo creation de ListeBase.o;
	$(GPP) -c $(LISTE)/ListeBase.cpp;

Liste.o: $(LISTE)/Liste.cpp $(LISTE)/Liste.h
	echo creation de Liste.o;
	$(GPP) -c $(LISTE)/Liste.cpp;

ListeTriee.o: $(LISTE)/ListeTriee.cpp $(LISTE)/ListeTriee.h
	echo creation de ListeTriee.o;
	$(GPP) -c $(LISTE)/ListeTriee.cpp;
	
Iterateur.o: $(LISTE)/Iterateur.cpp $(LISTE)/Iterateur.h
	echo creation de Iterateur.o;
	$(GPP) -c $(LISTE)/Iterateur.cpp;

Traitements.o: $(TRAITEMENT)/Traitements.cpp $(TRAITEMENT)/Traitements.h
	echo creation de Traitements.o;
	$(GPP) -c $(TRAITEMENT)/Traitements.cpp;

Moteur.o: $(APPLICATION)/Moteur.cpp $(APPLICATION)/Moteur.h
	echo creation de Moteur.o;
	$(GPP) -c $(APPLICATION)/Moteur.cpp;

UI.o: $(APPLICATION)/UI.cpp $(APPLICATION)/UI.h
	echo creation de UI.o;
	$(GPP) -c $(APPLICATION)/UI.cpp;

Test1.o: Test1.cpp
	echo creation de Test1.o;
	$(GPP) -c Test1.cpp;	
		
Test2.o: Test2.cpp
	echo creation de Test2.o;
	$(GPP) -c Test2.cpp;	
		
Test3.o: Test3.cpp
	echo creation de Test3.o;
	$(GPP) -c Test3.cpp;	
	
Test4.o: Test4.cpp
	echo creation de Test4.o;
	$(GPP) -c Test4.cpp;
	
Test5.o: Test5.cpp
	echo creation de Test5.o;
	$(GPP) -c Test5.cpp;

Test6.o: Test6.cpp
	echo creation de Test6.o;
	$(GPP) -c Test6.cpp;
	
Test7.o: Test7.cpp
	echo creation de Test7.o;
	$(GPP) -c Test7.cpp;
	
Test8.o: Test8.cpp
	echo creation du Test8.o;
	$(GPP) -c Test8.cpp;

Test9.o: Test9.cpp
	echo creation du Test9.o;
	$(GPP) -c Test9.cpp;

Test10.o: Test10.cpp
	echo creation du Test10.o;
	$(GPP) -c Test10.cpp;
	
main.o: $(APPLICATION)/main.cpp
	echo creation du main.o;
	$(GPP) -c $(APPLICATION)/main.cpp;
	
mTestEgal2019.o: mTestEgal2019.cpp
	echo creation du test.o;
	$(GPP) -c mTestEgal2019.cpp;
