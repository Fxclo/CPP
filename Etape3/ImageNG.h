#ifndef IMAGE_H
#define IMAGE_H
#include "Dimension.h"

class MyQT;

class ImageNG
{

  public:

  static const int L_MAX = 500;
  static const int H_MAX = 500;

  ImageNG(); // constructeur par défaut
  ~ImageNG(); // destructeur
  ImageNG(int id, const char* N); // constructeur d'initialisation
  ImageNG(const ImageNG& image1); // constructeur de copie
  ImageNG(int id, const char* N, const Dimension& dim); // constructeur d'initialisation complet

  void setDimension(const Dimension& dim);
  void setId(int val);
  void setNom(const char* N);

  void setPixel(int x, int y, int val);
  void setBackground(int val);
  int getPixel(int x, int y) const;

  Dimension getDimension() const;
  int getId() const;
  const char* getNom() const;

  void Affiche() const;

  void Dessine() const;

  void importFromFile(const char* fichier);
  void exportToFile(const char* fichier, const char* format);


  private:

  int id;
  char* nom;

  Dimension dimension;

  int matrice[L_MAX][H_MAX];
};

#endif