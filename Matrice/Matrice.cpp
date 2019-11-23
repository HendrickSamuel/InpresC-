#include "Matrice.h"

		/*---------------------- CONSTRUCTEURS / DESCTRUCTEUR ----------------------*/
		template <class T> Matrice<T>::Matrice(){ //pas utilisé 
			#ifdef DEV
			TraceConstructeur("Constructeur Matrice Defaut");
			#endif
			tab = NULL;
			creeTab(3,3);			
		}
		
		template <class T> Matrice<T>::Matrice(int L, int H){
			#ifdef DEV
			TraceConstructeur("Constructeur Matrice par valeur double");
			#endif
			tab = NULL;
			creeTab(L,H);
		}
		
		template <class T> Matrice<T>::Matrice(int L, int H, const T& val){
			#ifdef DEV
			TraceConstructeur("Constructeur Matrice par valeur triple");
			#endif
			tab = NULL;
			creeTab(L,H);
			
			for(int x = 0; x < getLargeur(); x++)
				for(int y = 0; y < getHauteur(); y++)
					setValeur(x,y,val);
		}
		
		template <class T> Matrice<T>::Matrice(const Matrice<T>& m){
			#ifdef DEV
			TraceConstructeur("Constructeur Matrice par copie");
			#endif
			tab = NULL;
			creeTab(m.getLargeur(),m.getHauteur());
			
			for(int x = 0; x < getLargeur(); x++)
				for(int y = 0; y < getHauteur(); y++)
					setValeur(x,y,m.getValeur(x,y));
			
		}
		
		template <class T> Matrice<T>::~Matrice(){
			#ifdef DEV
			TraceConstructeur("Destructeur Matrice");
			#endif
			if(tab)
			{
				for (int x=0 ; x<getLargeur() ; x++) delete[] tab[x];
				delete[] tab;
				tab = NULL;
			}
			
		}
		
		/*---------------------- OPPERATEURS ----------------------*/
		template <class T> const Matrice<T>& Matrice<T>::operator=(const Matrice<T>& old){
			creeTab(old.getLargeur(),old.getHauteur());
			
			for(int x = 0; x < getLargeur(); x++)
				for(int y = 0; y < getHauteur(); y++)
					setValeur(x,y,old.getValeur(x,y));
			return(*this);
		}
		
		template <class T> const T Matrice<T>::operator()(int x,int y) const{
			return getValeur(x,y);
		}
		
		template <class T> T& Matrice<T>::operator()(int x,int y){
			return tab[x][y];
		}	
		
		/*---------------------- SETTEURS ----------------------*/		
		template <class T> void Matrice<T>::setValeur(int x,int y,const T& val){
			//exception
			tab[x][y] = val;
		}
		
		template <class T> void Matrice<T>::setLargeur(int L){
			//exception
			largeur = L;
		}
		
		template <class T> void Matrice<T>::setHauteur(int H){
			//exception
			hauteur = H;
		}

		/*---------------------- GETTEURS ----------------------*/
		template <class T> const T& Matrice<T>::getValeur(int x,int y) const{
			return tab[x][y];
		}
		
		template <class T> int Matrice<T>::getLargeur() const{
			return largeur;
		}
		
		template <class T> int Matrice<T>::getHauteur() const{
			return hauteur;
		}
		
		/*---------------------- AUTRE ----------------------*/ 
		template <class T> void Matrice<T>::creeTab(int newLargeur, int newHauteur){
			#ifdef DEV
			Trace("creeMatrice de %d par %d", newLargeur,newHauteur);
			#endif
			if(tab)
			{
				for (int x=0 ; x<getLargeur() ; x++) delete[] tab[x];
				delete[] tab;
//				tab = NULL;
			}			
			
			setLargeur(newLargeur);
			setHauteur(newHauteur);
			
			tab = new T*[newLargeur];
			for (int x=0 ; x<newLargeur ; x++) tab[x] = new T[newHauteur];
	
			
		}
		
		template <class T> void Matrice<T>::Affiche() const
		{
			for(int x = 0; x < getHauteur(); x++)
			{
				for(int y = 0; y < getLargeur(); y++)
				{
					cout << getValeur(y,x) << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
					
		}
		
		template <class T> void  Matrice<T>::Redimension(int L, int H)
		{
			creeTab(L,H);
		}
		
		template <class T> void  Matrice<T>::Redimension(const Dimension& dim)
		{
			creeTab(dim.getLargeur(),dim.getHauteur());
		}
				
template class Matrice<int>;
template class Matrice<char>;
template class Matrice<bool>;
#include "Couleur.h"
template class Matrice<Couleur>;
