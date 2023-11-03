#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "Iterateur.h"

template<class T> 
struct Cellule
{
	T valeur;
	Cellule<T> *suivant;
};

template<class T> 
class ArrayList
{
	protected:

	Cellule<T> *pTete;

	public:

	ArrayList();
	ArrayList(const ArrayList<T>& list);
	~ArrayList();

	bool estVide() const;
	int getNombreElements() const;
	void Affiche() const;
	void insereElement(const T& val);
	T& getElement(int ind) const;
	T retireElement(int ind);

	ArrayList<T>& operator=(const ArrayList<T>& list);

	friend class Iterateur<T>; 

};

#endif