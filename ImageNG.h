#ifndef IMAGE_H
#define IMAGE_H

class ImageNG
{

private:

  int id;
  char* nom;

public:

  ImageNG(); // constructeur par défaut

  ~ImageNG(); // destructeur

  ImageNG(int id, const char* N); // constructeur d'initialisation

  ImageNG(const ImageNG& image1); // constructeur de copie


  void setId(int val);

  void setNom(const char* N);

  int getId() const;

  char* getNom() const;

  void Affiche() const;

};

#endif