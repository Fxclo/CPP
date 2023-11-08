#include "ImageNG.h"
#include "MyQT.h"
#include <iostream>
#include <string.h>
#include "RGBException.h"
#include "XYException.h"

using namespace std;

/********************************************************************/
/* CONSTRUCTEUR ET DESTRUCTEUR                                      */
/********************************************************************/

ImageNG::ImageNG() : Image()  // constructeur par défaut
{
  setBackground(0);

  cout << "--Constructeur par défaut ImageNG--" << endl;
}

ImageNG::~ImageNG() // destructeur
{
  cout << "--Destructeur ImageNG--" << endl;
}

ImageNG::ImageNG(int id, const char* N) : Image(id, N)  // constructeur d'initialisation
{
  setBackground(0);

  cout << "--Constructeur init. ImageNG--" << endl;
}

ImageNG::ImageNG(const ImageNG& image1) : Image(image1) // constructeur de copie
{
  for(int i = 0; i < dimension.getLargeur(); i++)
    for(int j = 0; j < dimension.getHauteur(); j++) matrice[i][j] = image1.matrice[i][j];

  cout << "--Constructeur de copie ImageNG--" << endl;
}

ImageNG::ImageNG(int id, const char* N, const Dimension& dim) : Image(id, N, dim) 
{
  setBackground(0);

  cout << "--Constructeur init. complet ImageNG--" << endl;
}

ImageNG::ImageNG(const char* fichier) : Image(fichier)
{
  importFromFile(fichier); // j'importe les dimensions de l'image

  cout << "--Constructeur avec path du fichier ImageNG--" << endl;
}


/********************************************************************/
/* SETTERS ET GETTERS                                               */
/********************************************************************/

void ImageNG::setBackground(int val)
{
  if(val < 0) throw RGBException(val, "Le niveau de gris ne peut pas être négatif!");
  
  for(int i = 0; i < dimension.getLargeur(); i++)
  {
    for(int j = 0; j < dimension.getHauteur(); j++) matrice[i][j] = val; // je mets tous les pixels au meme niveau de gris
  }
}

void ImageNG::setPixel(int x, int y, int val)
{
  if (x < 0 && y < 0) throw XYException('d', "coordonnées x et y invalides!");
  else if (x < 0) throw XYException('x', "coordonnée x invalide!");
  else if (y < 0) throw XYException('y', "coordonnée y invalide!");

  if (x > dimension.getLargeur() && y > dimension.getHauteur()) throw XYException('d', "coordonnées x et y invalides!");
  else if (x > dimension.getLargeur()) throw XYException('x', "coordonnée x invalide!");
  else if (y > dimension.getHauteur()) throw XYException('y', "coordonnée y invalide!");

  if (val < 0) throw RGBException(val, "Le niveau de gris ne peut pas être négatif!");
  if (val > 255) throw RGBException(val, "Le niveau de gris ne peut pas aller au delà de 255!");

  matrice[x][y] = val; // je donne un niveau de gris à un pixel précis de la matrice
}

int ImageNG::getPixel(int x, int y) const
{
  if (x < 0 && y < 0) throw XYException('d', "coordonnées x et y invalides!");
  else if (x < 0) throw XYException('x', "coordonnée x invalide!");
  else if (y < 0) throw XYException('y', "coordonnée y invalide!");

  if (x > dimension.getLargeur() && y > dimension.getHauteur()) throw XYException('d', "coordonnées x et y invalides!");
  else if (x > dimension.getLargeur()) throw XYException('x', "coordonnée x invalide!");
  else if (y > dimension.getHauteur()) throw XYException('y', "coordonnée y invalide!");

  return matrice[x][y]; // je retourne le niveau de gris du pixel
}

int ImageNG::getLuminance() const
 {
  int somme = 0, moyenne = 0;

  for(int i = 0; i < dimension.getLargeur(); i++)
  {
    for(int j = 0; j < dimension.getHauteur(); j++) somme = somme + matrice[i][j];
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

  int min = getMinimum();
  int max = getMaximum();

  if(!min && !max) return 0;

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
  if (dimension.getLargeur() != image.dimension.getLargeur()) throw XYException('x', "Largeurs inégales!");
  if (dimension.getHauteur() != image.dimension.getHauteur()) throw XYException('y', "Hauteurs inégales!");

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
  if (dimension.getLargeur() != image.dimension.getLargeur()) throw XYException('x', "Largeurs inégales!");
  if (dimension.getHauteur() != image.dimension.getHauteur()) throw XYException('y', "Hauteurs inégales!");

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
  if (dimension.getLargeur() != image.dimension.getLargeur()) throw XYException('x', "Largeurs inégales!");
  if (dimension.getHauteur() != image.dimension.getHauteur()) throw XYException('y', "Hauteurs inégales!");

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
  if (dimension.getLargeur() != image.dimension.getLargeur()) throw XYException('x', "Largeurs inégales!");
  if (dimension.getHauteur() != image.dimension.getHauteur()) throw XYException('y', "Hauteurs inégales!");

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
 s << "nom : " << image.nom << " | id : " << image.id  << " | dimension : " << image.dimension.getLargeur() << "/" << image.dimension.getHauteur() << " | Luminance : " << image.getLuminance() << " | Contraste : " << image.getContraste() << endl;

 return s;
}

/********************************************************************/
/* METHODE AVEC LES FICHIERS                                        */
/********************************************************************/

void ImageNG::Save(ofstream& fichier) const
{
  int identifiant = getId();
  fichier.write((char*)&identifiant, sizeof(int));

  int lgChaine = strlen(nom); // taille du nom
  fichier.write((char*)&lgChaine, sizeof(int));

  char *nomTemp = new char[lgChaine + 1]; 
  strcpy(nomTemp, getNom());
  fichier.write(nomTemp, lgChaine);

  dimension.Save(fichier);

  int pixel;
  for (int i = 0; i < dimension.getLargeur(); i++)
  {
    for (int j = 0; j < dimension.getHauteur(); j++)
    {
      pixel = matrice[i][j];
      fichier.write((char*)&pixel, sizeof(int));
    }
  }
}

void ImageNG::Load(std::ifstream& fichier)
{
    int identifiant;
    fichier.read((char*)&identifiant, sizeof(int));
    setId(identifiant);

    int lgChaine;
    fichier.read((char*)&lgChaine, sizeof(int));

    char* nomTemp = new char[lgChaine+1];
    fichier.read(nomTemp, lgChaine);
    setNom(nomTemp);
    delete [] nomTemp;

    dimension.Load(fichier);

    for (int i = 0; i < dimension.getLargeur(); i++) 
    {
        for (int j = 0; j < dimension.getHauteur(); j++) 
        {
            int pixel;
            fichier.read((char*)&pixel, sizeof(int));
            matrice[i][j] = pixel;
        }
    }
}



  