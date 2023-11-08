#include "ImageB.h"
#include "MyQT.h"
#include <iostream>
#include <string.h>
#include "XYException.h"


using namespace std;

Couleur ImageB::couleurTrue(255, 255, 255); 
Couleur ImageB::couleurFalse(0, 0, 0); 

/********************************************************************/
/* CONSTRUCTEUR ET DESTRUCTEUR                                      */
/********************************************************************/

ImageB::ImageB() : Image()
{
	setBackground(false);

	cout << "--Constructeur par défaut ImageB--" << endl;
}

ImageB::~ImageB() // destructeur
{
  cout << "--Destructeur ImageB--" << endl;
}

ImageB::ImageB(int id, const char* N) : Image(id, N)  // constructeur d'initialisation
{
  	setBackground(false);

  	cout << "--Constructeur init. ImageB--" << endl;
}

ImageB::ImageB(const ImageB& image1) : Image(image1) // constructeur de copie
{
  	for(int i = 0; i < dimension.getLargeur(); i++)
    	for(int j = 0; j < dimension.getHauteur(); j++) matrice[i][j] = image1.matrice[i][j];

    cout << "--Constructeur de copie ImageB--" << endl;
}

ImageB::ImageB(int id, const char* N, const Dimension& dim) : Image(id, N, dim) 
{
		setBackground(false);

		cout << "--Constructeur init. complet ImageB--" << endl;
}

ImageB::ImageB(const char* fichier) : Image(fichier)
{
  	
}


/********************************************************************/
/* SETTERS ET GETTERS                                               */
/********************************************************************/

void ImageB::setBackground(bool valeur)
{
  for(int i = 0; i < dimension.getLargeur(); i++)
  {
    for(int j = 0; j < dimension.getHauteur(); j++) matrice[i][j] = valeur;
  }
}

void ImageB::setPixel(int x, int y, bool valeur)
{
  if (x < 0 && y < 0) throw XYException('d', "coordonnées x et y invalides!");
  else if (x < 0) throw XYException('x', "coordonnée x invalide!");
  else if (y < 0) throw XYException('y', "coordonnée y invalide!");

  if (x > dimension.getLargeur() && y > dimension.getHauteur()) throw XYException('d', "coordonnées x et y invalides!");
  else if (x > dimension.getLargeur()) throw XYException('x', "coordonnée x invalide!");
  else if (y > dimension.getHauteur()) throw XYException('y', "coordonnée y invalide!");

  matrice[x][y] = valeur; 
}

bool ImageB::getPixel(int x, int y) const
{
  if (x < 0 && y < 0) throw XYException('d', "coordonnées x et y invalides!");
  else if (x < 0) throw XYException('x', "coordonnée x invalide!");
  else if (y < 0) throw XYException('y', "coordonnée y invalide!");

  if (x > dimension.getLargeur() && y > dimension.getHauteur()) throw XYException('d', "coordonnées x et y invalides!");
  else if (x > dimension.getLargeur()) throw XYException('x', "coordonnée x invalide!");
  else if (y > dimension.getHauteur()) throw XYException('y', "coordonnée y invalide!");

  return matrice[x][y]; 
}


/********************************************************************/
/* METHODE QUI PERMET D'AFFICHER                                    */
/********************************************************************/

void ImageB::Affiche() const
{
  cout << "Nom : " << getNom() << endl;
  cout << "ID : " << getId() << endl;
  dimension.Affiche();
}

void ImageB::Dessine() const
{
  MyQT::ViewImage(*this);
}

void ImageB::exportToFile(const char* fichier, const char* format)
{
  MyQT::ExportToFile(*this, fichier, format);
}


/********************************************************************/
/* METHODE AVEC LES OPERATEURS                                      */
/********************************************************************/

ImageB& ImageB::operator=(const ImageB& image) // on return une reference d'un objet
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

ostream& operator<<(ostream& s,const ImageB& image)
{
 s << "nom : " << image.nom << " | id : " << image.id  << " | dimension : " << image.dimension.getLargeur() << "/" << image.dimension.getHauteur() << endl;

 return s;
}

/********************************************************************/
/* METHODE AVEC LES FICHIERS                                        */
/********************************************************************/

void ImageB::Save(ofstream& fichier) const
{
  int identifiant = getId();
  fichier.write((char*)&identifiant, sizeof(int));

  int lgChaine = strlen(nom); // taille du nom
  fichier.write((char*)&lgChaine, sizeof(int));

  char *nomTemp = new char[lgChaine + 1]; 
  strcpy(nomTemp, getNom());
  fichier.write(nomTemp, lgChaine);

  dimension.Save(fichier);

  bool pixel;
  for (int i = 0; i < dimension.getLargeur(); i++)
  {
    for (int j = 0; j < dimension.getHauteur(); j++)
    {
      pixel = matrice[i][j];
      fichier.write((char*)&pixel, sizeof(bool));
    }
  }
}

void ImageB::Load(ifstream& fichier)
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
            bool pixel;
            fichier.read((char*)&pixel, sizeof(bool));
            matrice[i][j] = pixel;
        }
    }
}