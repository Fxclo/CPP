#ifndef DIMENSION_H
#define DIMENSION_H

class Dimension
{

private:

  int largeur;
  int hauteur;

public:

  static const Dimension VGA;
  static const Dimension HD;
  static const Dimension FULL_HD;

  Dimension();
  Dimension(int l, int h);
  Dimension(const Dimension& objet);
  ~Dimension();

  void setLargeur(int vL);
  void setHauteur(int vH);

  int getLargeur() const; 
  int getHauteur() const;

  void Affiche() const;

};

#endif