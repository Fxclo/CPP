#include <iostream>
#include "Iterateur.h"
#include "Couleur.h"
#include "ArrayList.h"

using namespace std;

/********************************************************************/
/* INSTANCIATION DES TEMPLATES                                      */
/********************************************************************/

template class Iterateur<int>;
template class Iterateur<Couleur>;

/********************************************************************/
/* CONSTRUCTEUR ET DESTRUCTEUR                                      */
/********************************************************************/

template<class T>
Iterateur<T>::Iterateur(ArrayList<T>& list) : liste(list)
{
    pCur = list.pTete;
}

/********************************************************************/
/* METHODES DE LA CLASSE                                            */
/********************************************************************/

template<class T>
void Iterateur<T>::reset()
{
	pCur = liste.pTete;
}

template<class T>
bool Iterateur<T>::end() const
{
	if (pCur == nullptr) return true;

	return false;
}

template<class T>
bool Iterateur<T>::operator++()
{
	if (pCur) // si pCur est à NULL, il n'avancera pas !
	{
		pCur = pCur->suivant; 
		return true;
	}

	return false;
}

template<class T>
bool Iterateur<T>::operator++(int)
{
	return operator++();
}

template<class T>
Iterateur<T>::operator T()
{
	return pCur->valeur;
}

template<class T>
T& Iterateur<T>::operator &()
{
	return pCur->valeur;
}