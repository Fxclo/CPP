#include "ImageNG.h"
#include "MyQT.h"
#include <iostream>
#include <string.h>

using namespace std;

ImageNG::ImageNG() // constructeur par défaut
{
  nom = NULL;
  setNom("default");
  setId(1);
  setBackground(0);
  //setDimension(getDimension());
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
  setBackground(0);
}

ImageNG::ImageNG(const ImageNG& image1) // constructeur de copie
{
  nom = NULL;
  setNom(image1.getNom());
  setId(image1.getId());

  setDimension(image1.getDimension());

 for(int i = 0; i < dimension.getLargeur(); i++)
  {
    for(int j = 0; j < dimension.getHauteur(); j++) matrice[i][j]= image1.matrice[i][j];
  }
}

ImageNG::ImageNG(int id, const char* N, const Dimension& dim) 
{
  nom = NULL;
  setNom(N);
  setId(id);
  setBackground(0);
  setDimension(dim);
}

void ImageNG::setDimension(const Dimension& dim)
{
  if(dim.getHauteur() > H_MAX) dimension.setHauteur(H_MAX);
  else dimension.setHauteur(dim.getHauteur());

  if(dim.getLargeur() > L_MAX) dimension.setLargeur(L_MAX);
  else dimension.setLargeur(dim.getLargeur());
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

void ImageNG::setBackground(int val)
{
  if(val < 0) return; 
  
  for(int i = 0; i < L_MAX; i++)
  {
    for(int j = 0; j < H_MAX; j++) matrice[i][j]= val; // je mets tous les pixels au meme niveau de gris
  }
}

void ImageNG::setPixel(int x, int y, int val)
{
  if (x < 0) return;
  if (y < 0) return;
  if (val < 0) return;

  matrice[x][y] = val; // je donne un niveau de gris à un pixel précis de la matrice
}

int ImageNG::getPixel(int x, int y) const
{
  return matrice[x][y]; // je retourne le niveau de gris du pixel
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

void ImageNG::Dessine() const
{
  MyQT::ViewImage(*this);
}

void ImageNG::importFromFile(const char* fichier) 
{
  MyQT::ImportFromFile(*this, fichier);
}

void ImageNG::exportToFile(const char* fichier, const char* format)
{
  MyQT::ExportToFile(*this, fichier, format);
}