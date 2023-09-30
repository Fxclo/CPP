#include "ImageNG.h"
#include <iostream>
#include <string.h>

using namespace std;

const int ImageNG::L_MAX(500);
const int ImageNG::H_MAX(500);

ImageNG::ImageNG() // constructeur par défaut
{
  nom = NULL;
  setNom("default");
  setId(1);
}

ImageNG::~ImageNG() // destructeur
{
  if(nom) delete nom;
  cout << "--Destructeur ImageNG--" << endl;
}

ImageNG::ImageNG(int id, const char* N) // constructeur d'initialisation
{
  nom = NULL;
  setNom(N);
  setId(id);
}

ImageNG::ImageNG(const ImageNG& image1) // constructeur de copie
{
  nom = NULL;
  setNom(image1.getNom());
  setId(image1.getId());
}

ImageNG::ImageNG(int id, const char* N, Dimension dim) 
{
  nom = NULL;
  setNom(N);
  setId(id);

  setDimension(dim);
}

void ImageNG::setDimension(Dimension dim)
{
  dimension = dim;
}


void ImageNG::setId(int val)
{
  if (val >= 0)
    id = val;
}

void ImageNG::setNom(const char* N)
{
  if (strlen(N)== 0) // si la chaine est vide
    return;

  if (nom) delete nom;

  nom = new char[strlen(N)+1]; // on alloue dynamiquement
  strcpy(nom, N);
}

Dimension ImageNG::getDimension() const
{
  return dimension;
}

int ImageNG::getId() const
{
  return id; 
}

const char* ImageNG::getNom() const
{
  return nom;
}

void ImageNG::Affiche() const
{
  cout << "Nom : " << getNom() << endl;
  cout << "ID : " << getId() << endl;
  dimension.Affiche();
}