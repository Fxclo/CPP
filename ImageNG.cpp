#include "ImageNG.h"
#include <iostream>
#include <string.h>

using namespace std;

ImageNG::ImageNG() // constructeur par défaut
{
  nom = new char[20];
  setNom("default");
  setId(1);
}

ImageNG::~ImageNG() // destructeur
{
  delete nom;
}

ImageNG::ImageNG(int id, const char* N) // constructeur d'initialisation
{
  nom = new char[20];
  setNom(N);
  setId(id);
}

ImageNG::ImageNG(const ImageNG& image1) // constructeur de copie
{
  nom = new char[20];
  setNom(image1.nom);
  setId(image1.id);
}


void ImageNG::setId(int val)
{
  if (val >= 0)
    id = val;
}

void ImageNG::setNom(const char* N)
{
  if (strlen(N)== 0)
    return;
  strcpy(nom, N);
}

int ImageNG::getId() const
{
  return id; 
}

char* ImageNG::getNom() const
{
  return nom;
}

void ImageNG::Affiche() const
{
  cout << "Nom : " << getNom() << endl;
  cout << "ID : " << getId() << endl;
}
