#ifndef IMAGE_H
#define IMAGE_H
#include "Dimension.h"

class ImageNG
{

private:

  int id;
  char* nom;

  Dimension dimension;

  int matrice[L_MAX][H_MAX];

public:

  static const int L_MAX;
  static const int H_MAX;

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
  int getPixel(int x, int y) const

  Dimension getDimension()const;
  int getId()const;
  const char* getNom()const;

  void Affiche()const;

};

#endif