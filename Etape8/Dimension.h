#ifndef DIMENSION_H
#define DIMENSION_H
#include <iostream>
#include <fstream>

using namespace std;

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

  friend std::ostream& operator<<(std::ostream& s,const Dimension& dim);
  friend std::istream& operator>>(std::istream& s, Dimension& dim);

  bool operator==(const Dimension& dim) const;
  bool operator!=(const Dimension& dim) const;

  void Save(ofstream& fichier) const;
  void Load(ifstream& fichier);



};

#endif