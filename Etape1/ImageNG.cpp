#include "ImageNG.h"
#include <iostream>
#include <string.h>

using namespace std;

ImageNG::ImageNG() // constructeur par défaut
{
  nom = NULL;
  setNom("default");
  setId(1);
}

ImageNG::~ImageNG() // destructeur
{
  if(nom) delete nom;
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
}
