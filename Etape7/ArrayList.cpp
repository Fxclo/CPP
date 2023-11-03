#include <iostream>
#include "ArrayList.h"
#include "Iterateur.h"
#include "Couleur.h"
#include "Image.h"

using namespace std;

/********************************************************************/
/* INSTANCIATION DES TEMPLATES                                      */
/********************************************************************/

template class ArrayList<int>;
template class ArrayList<Couleur>;

/********************************************************************/
/* CONSTRUCTEUR ET DESTRUCTEUR                                      */
/********************************************************************/

template<class T>
ArrayList<T>::ArrayList() 
{
	pTete = nullptr;
}


template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& list) 
{
	pTete = nullptr;

    Cellule<T>* pCur = list.pTete;
    Cellule<T>* pPrec = nullptr;

    while (pCur != nullptr) 
    {
        Cellule<T> *pNew = new Cellule<T>;
        pNew->valeur = pCur->valeur;
        pNew->suivant = nullptr;

        if (pTete == nullptr) pTete = pNew; // si la liste est vide, c'est le premier
        else pPrec->suivant = pNew; 		// sinon, ça devient le suivant
        
        pPrec = pNew;						
        pCur = pCur->suivant;
    }
}


template<class T>
ArrayList<T>::~ArrayList()
{
    Cellule<T> *pCur = pTete;
    Cellule<T> *pPrec = nullptr;

    while (pCur != nullptr)
    {
        pPrec = pCur;
        pCur = pCur->suivant;
        delete pPrec;
    }
}

/********************************************************************/
/* METHODES DE LA CLASSE                                            */
/********************************************************************/

template<class T>
bool ArrayList<T>::estVide() const
{
   if (pTete == nullptr) return true;

   return false;
}

template<class T>
int ArrayList<T>::getNombreElements() const
{
    Cellule<T> *pCur = pTete;
    int i = 0;

    while (pCur != nullptr)
    {
        pCur = pCur->suivant;
        i++;
    }

    return i;
}

template<class T>
void ArrayList<T>::Affiche() const
{
	if (estVide()) 
	{
		cout << "La liste est vide !" << endl;
		return;
	}

	Cellule<T> *pCur = pTete;

	while (pCur != nullptr)
	{
		cout << "Valeur : " << pCur->valeur << endl;
		pCur = pCur->suivant;
	}

}

template<class T>
void ArrayList<T>::insereElement(const T& val)
{
	Cellule<T> *pNew = new Cellule<T>;

	pNew->valeur = val;
	pNew->suivant = nullptr;

	if(estVide()) 
		pTete = pNew;
	else
	{
		Cellule<T> *pCur = pTete;
		Cellule<T> *pPrec = nullptr;

		while (pCur != nullptr)
		{
			pPrec = pCur;
			pCur = pCur->suivant;
		}

		pPrec->suivant = pNew;
	}
}

template<class T>
T& ArrayList<T>::getElement(int ind) const
{
	/* Gerer si l'indice est hors limite ! */

	Cellule<T> *pCur = pTete;
	int i = 0;

	while (i < ind)
	{
		pCur = pCur->suivant;
		i++;
	}

	return pCur->valeur;
}

template<class T>
T ArrayList<T>::retireElement(int ind)
{
    Cellule<T> *pCur = pTete;
    Cellule<T> *pPrec = nullptr;

    int i = 0;

    while (i < ind)
    {
        pPrec = pCur;
        pCur = pCur->suivant;
        i++;
    }

    if (pPrec != nullptr) // Si pPrec est != NULL, alors ce n'est pas le premier
    {
        pPrec->suivant = pCur->suivant;
    }
    else // Si l'élément à retirer est le premier de la liste
    {
        pTete = pCur->suivant; 
    }

    T valeurRetiree = pCur->valeur;
    delete pCur; 

    return valeurRetiree;
}

template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& list)
{
	Cellule<T>* pCur = list.pTete;
    Cellule<T>* pPrec = nullptr;

    while (pCur != nullptr) 
    {
        Cellule<T> *pNew = new Cellule<T>;
        pNew->valeur = pCur->valeur;
        pNew->suivant = nullptr;

        if (pTete == nullptr) pTete = pNew; // si la liste est vide, c'est le premier
        else pPrec->suivant = pNew; 		// sinon, ça devient le suivant
        
        pPrec = pNew;						
        pCur = pCur->suivant;
    }

    return *this;
}