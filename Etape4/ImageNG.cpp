#include "ImageNG.h"
#include "MyQT.h"
#include <iostream>
#include <string.h>

using namespace std;

/********************************************************************/
/* CONSTRUCTEUR ET DESTRUCTEUR                                      */
/********************************************************************/

ImageNG::ImageNG() // constructeur par défaut
{
  nom = NULL;
  setNom("default");
  setId(1);
  setBackground(0);
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
    for(int j = 0; j < dimension.getHauteur(); j++) matrice[i][j] = image1.matrice[i][j];
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

ImageNG::ImageNG(const char* fichier)
{
  nom = NULL;
  setNom(fichier);
  setId(1);
  importFromFile(fichier); // j'importe les dimensions de l'image
}


/********************************************************************/
/* SETTERS ET GETTERS                                               */
/********************************************************************/

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

int ImageNG::getLuminance() const
 {
  int somme = 0, moyenne = 0;

  for(int i = 0; i<dimension.getHauteur(); i++)
  {
    for(int j = 0; j<dimension.getLargeur(); j++) somme = somme + matrice[i][j];
  }

  moyenne = somme / (dimension.getHauteur() * dimension.getLargeur());

  return moyenne;
 }

int ImageNG::getMinimum() const
 {
  int minimum = 255;

  for(int i = 0; i<dimension.getHauteur(); i++)
  {
    for(int j = 0; j<dimension.getLargeur(); j++)
      {
        if(minimum > matrice[i][j]) minimum = matrice[i][j];
      }
  }

  return minimum;
 }

int ImageNG::getMaximum() const
 {
  int maximum = 0;

  for(int i = 0; i<dimension.getHauteur(); i++)
  {
    for(int j = 0; j<dimension.getLargeur(); j++)
    {
      if(maximum < matrice[i][j]) maximum = matrice[i][j];
    }
  }

  return maximum;
 }

float ImageNG::getContraste() const
{
  float contraste = 0;

  contraste = (float)(getMaximum()-getMinimum()) / (float)(getMaximum()+getMinimum());

  return contraste;
}


/********************************************************************/
/* METHODE QUI PERMET D'AFFICHER                                    */
/********************************************************************/

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


/********************************************************************/
/* METHODE AVEC LES OPERATEURS                                      */
/********************************************************************/

ImageNG& ImageNG::operator=(const ImageNG& image) // on return une reference d'un objet
{
  setNom(image.nom);
  setId(image.id);
  dimension.setHauteur(image.dimension.getHauteur());
  dimension.setLargeur(image.dimension.getLargeur());

  for(int i = 0; i < dimension.getLargeur(); i++)
  {
    for(int j = 0; j < dimension.getHauteur(); j++) matrice[i][j] = image.matrice[i][j];
  }

  return(*this);
}

ImageNG ImageNG::operator+(int val)
{
  ImageNG imageNEW(*this);
  
    for(int i = 0; i < imageNEW.dimension.getLargeur(); i++)
    {
      for(int j = 0; j < imageNEW.dimension.getHauteur(); j++) 
        {
          imageNEW.matrice[i][j] = imageNEW.matrice[i][j] + val;
          if(imageNEW.matrice[i][j] > 255) imageNEW.matrice[i][j] = 255;
          if(imageNEW.matrice[i][j] < 0) imageNEW.matrice[i][j] = 0;
        }
    }
  
  return imageNEW;
}

ImageNG operator+(int val, ImageNG image) // fonction amie
{
  return image + val;
}

ImageNG ImageNG::operator-(int val)
{
  ImageNG imageNEW(*this);

  for(int i = 0; i < imageNEW.dimension.getLargeur(); i++)
  {
    for(int j = 0; j < imageNEW.dimension.getHauteur(); j++) 
      {
        imageNEW.matrice[i][j] = imageNEW.matrice[i][j] - val;
        if(imageNEW.matrice[i][j] < 0) imageNEW.matrice[i][j] = 0;
      }
  }

  return imageNEW;
}

ImageNG ImageNG::operator-(const ImageNG& image)
{
  ImageNG imageNEW(*this);

  for(int i = 0; i < imageNEW.dimension.getLargeur(); i++)
  {
    for(int j = 0; j < imageNEW.dimension.getHauteur(); j++) 
      {
        imageNEW.matrice[i][j] = imageNEW.matrice[i][j] - image.matrice[i][j];
        if(imageNEW.matrice[i][j] < 0) imageNEW.matrice[i][j] = 0;
      }
  }

  return imageNEW;
}

ImageNG ImageNG::operator++() // pré-incrémentation
{
  (*this) = (*this) + 20; 

  return (*this);
}

ImageNG ImageNG::operator++(int AucuneVal) // post-incrémentation
{
  ImageNG temp(*this); // copie de l’objet courant
  (*this) = (*this) + 20;

  return temp;
}

ImageNG ImageNG::operator--() // pré-décrémentation
{
  (*this) = (*this) - 20; 

  return (*this);
}

ImageNG ImageNG::operator--(int AucuneVal) // post-décrémentation
{
  ImageNG temp(*this); // copie de l’objet courant
  (*this) = (*this) - 20;

  return temp;
}

bool ImageNG::operator<(const ImageNG& image) const 
{
    for (int i = 0; i < dimension.getLargeur(); i++) 
    {
        for (int j = 0; j < dimension.getHauteur(); j++) 
        {
            if (matrice[i][j] >= image.matrice[i][j]) return false; // Si au moins un pixel n'est pas <, l'image n'est pas < que l'autre
        }
    }
    return true; // Tous les pixels sont <
}

bool ImageNG::operator>(const ImageNG& image) const 
{
    for (int i = 0; i < dimension.getLargeur(); i++) 
    {
        for (int j = 0; j < dimension.getHauteur(); j++) 
        {
            if (matrice[i][j] <= image.matrice[i][j]) return false; // Si au moins un pixel n'est pas >, l'image n'est pas > que l'autre
        }
    }
    return true; // Tous les pixels sont >
}

bool ImageNG::operator==(const ImageNG& image) const 
{  
    for (int i = 0; i < dimension.getLargeur(); ++i) 
    {
        for (int j = 0; j < dimension.getHauteur(); ++j) 
        {
            if (matrice[i][j] != image.matrice[i][j]) return false; // Si au moins un pixel est différent, les images ne sont pas égales
        }
    }
    return true; // Tous les pixels sont égaux
}

ostream& operator<<(ostream& s,const ImageNG& image)
{
 s << "nom : " << image.nom << " | id : " << image.id  << " | dimension : " << image.dimension.getHauteur() << "/" << image.dimension.getLargeur() << " | Luminance : " << image.getLuminance() << " | Contraste : " << image.getContraste() << endl;

 return s;
}

