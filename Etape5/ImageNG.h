#ifndef IMAGENG_H
#define IMAGENG_H
#include "Dimension.h"
#include "Image.h"

class MyQT;

class ImageNG : public Image
{

  public:

  ImageNG();                                            // constructeur par défaut
  ~ImageNG();                                           // destructeur
  ImageNG(int id, const char* N);                       // constructeur d'initialisation
  ImageNG(const ImageNG& image1);                       // constructeur de copie
  ImageNG(int id, const char* N, const Dimension& dim); // constructeur d'initialisation complet
  ImageNG(const char* fichier);                         // construteur par initialisation avec le path du fichier

  void setPixel(int x, int y, int val);
  void setBackground(int val);
  int getPixel(int x, int y) const;

  void Affiche() const;
  void Dessine() const;
  void importFromFile(const char* fichier);
  void exportToFile(const char* fichier, const char* format);

  int getLuminance() const;
  int getMinimum() const;
  int getMaximum() const;
  float getContraste() const;

  ImageNG& operator=(const ImageNG& image);
  ImageNG operator+(int val);
  ImageNG operator-(int val);
  ImageNG operator++(); // pré
  ImageNG operator++(int sertARien); // post
  ImageNG operator--(); // pré
  ImageNG operator--(int sertARien); // post
  ImageNG operator-(const ImageNG& image);
  bool operator<(const ImageNG& image) const;
  bool operator>(const ImageNG& image) const;
  bool operator==(const ImageNG& image) const;

  friend std::ostream& operator<<(std::ostream& s,const ImageNG& image);
  friend ImageNG operator+(int val, ImageNG image);

  private:

  int matrice[L_MAX][H_MAX];

};

#endif