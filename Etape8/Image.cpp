#include "ImageNG.h"
#include "MyQT.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

/********************************************************************/
/* CONSTRUCTEUR ET DESTRUCTEUR                                      */
/********************************************************************/

Image::Image() // constructeur par défaut
{
  nom = NULL;
  setNom("default");
  setId(1);
}

Image::~Image() // destructeur
{
  if(nom) delete nom;
  
  cout << "--Destructeur Image--" << endl;
}

Image::Image(int id, const char* N) // constructeur d'initialisation
{
  nom = NULL;
  setNom(N);
  setId(id);
}

Image::Image(const Image& image1) // constructeur de copie
{
  nom = NULL;
  setNom(image1.getNom());
  setId(image1.getId());
  setDimension(image1.getDimension());
}

Image::Image(int id, const char* N, const Dimension& dim)
{
  nom = NULL;
  setNom(N);
  setId(id);
  setDimension(dim);
}

Image::Image(const char* fichier)
{
  nom = NULL;
  setNom(fichier);
  setId(1);
}


/********************************************************************/
/* SETTERS ET GETTERS                                               */
/********************************************************************/

void Image::setDimension(const Dimension& dim)
{
  if(dim.getHauteur() > H_MAX) dimension.setHauteur(H_MAX);
  else dimension.setHauteur(dim.getHauteur());

  if(dim.getLargeur() > L_MAX) dimension.setLargeur(L_MAX);
  else dimension.setLargeur(dim.getLargeur());
}

void Image::setId(int val)
{
  if (val >= 0)
    id = val;
}

void Image::setNom(const char* N)
{
  if (strlen(N)== 0) // si la chaine est vide
    return;

  if (nom) delete nom;

  nom = new char[strlen(N)+1]; // on alloue dynamiquement
  strcpy(nom, N);
}

Dimension Image::getDimension() const
{
  return dimension;
}

int Image::getId() const
{
  return id; 
}

const char* Image::getNom() const
{
  return nom;
}
