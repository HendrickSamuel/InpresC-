#ifndef STRUCT_H
#define STRUCT_H
	template<class T> struct Cellule
	{
		T valeur ;
		Cellule<T> *suivant ;
	};
#endif
