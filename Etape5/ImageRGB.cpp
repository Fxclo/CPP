#include "ImageRGB.h"
#include "MyQT.h"
#include <iostream>
#include <string.h>

using namespace std;

/********************************************************************/
/* CONSTRUCTEUR ET DESTRUCTEUR                                      */
/********************************************************************/

ImageRGB::ImageRGB() : Image()
{
	setBackground(Couleur::NOIR);

	cout << "--Constructeur par défaut ImageRGB--" << endl;
}

ImageRGB::~ImageRGB() // destructeur
{
  cout << "--Destructeur ImageRGB--" << endl;
}

ImageRGB::ImageRGB(int id, const char* N) : Image(id, N)  // constructeur d'initialisation
{
  	setBackground(Couleur::NOIR);

  	cout << "--Constructeur init. ImageRGB--" << endl;
}

ImageRGB::ImageRGB(const ImageRGB& image1) : Image(image1) // constructeur de copie
{
  	for(int i = 0; i < dimension.getLargeur(); i++)
    	for(int j = 0; j < dimension.getHauteur(); j++) matrice[i][j] = image1.matrice[i][j];

    cout << "--Constructeur de copie ImageRGB--" << endl;
}

ImageRGB::ImageRGB(int id, const char* N, const Dimension& dim) : Image(id, N, dim) 
{
	setBackground(Couleur::NOIR);

	cout << "--Constructeur init. complet ImageRGB--" << endl;
}

ImageRGB::ImageRGB(const char* fichier) : Image(fichier)
{
  	importFromFile(fichier);

  	cout << "--Constructeur avec le path du fichier ImageRGB--" << endl;
}


/********************************************************************/
/* SETTERS ET GETTERS                                               */
/********************************************************************/

void ImageRGB::setBackground(const Couleur& color)
{
  for(int i = 0; i < dimension.getLargeur(); i++)
  {
    for(int j = 0; j < dimension.getHauteur(); j++) matrice[i][j] = color;
  }
}

void ImageRGB::setPixel(int x, int y, const Couleur& color)
{
  if (x < 0) return;
  if (y < 0) return;

  matrice[x][y] = color; 
}

Couleur ImageRGB::getPixel(int x, int y) const
{
  return matrice[x][y]; 
}


/********************************************************************/
/* METHODE QUI PERMET D'AFFICHER                                    */
/********************************************************************/

void ImageRGB::Affiche() const
{
  cout << "Nom : " << getNom() << endl;
  cout << "ID : " << getId() << endl;
  dimension.Affiche();
}

void ImageRGB::Dessine() const
{
  MyQT::ViewImage(*this);
}

void ImageRGB::importFromFile(const char* fichier) 
{
  MyQT::ImportFromFile(*this, fichier);
}

void ImageRGB::exportToFile(const char* fichier, const char* format)
{
  MyQT::ExportToFile(*this, fichier, format);
}


/********************************************************************/
/* METHODE AVEC LES OPERATEURS                                      */
/********************************************************************/

ImageRGB& ImageRGB::operator=(const ImageRGB& image) // on return une reference d'un objet
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

ostream& operator<<(ostream& s,const ImageRGB& image)
{
 s << "nom : " << image.nom << " | id : " << image.id  << " | dimension : " << image.dimension.getHauteur() << "/" << image.dimension.getLargeur() << endl;

 return s;
}