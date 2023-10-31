#include <stdlib.h>
#include <iostream>
#include "Dimension.h"

using namespace std;

const Dimension Dimension::VGA(640,480); //VGA vient de la classe Dimension de type Dimension et constante
const Dimension Dimension::HD(1280,720);
const Dimension Dimension::FULL_HD(1920,1080);

Dimension::Dimension()
{
  setLargeur(400);
  setHauteur(300);
}

Dimension::Dimension(int l, int h)
{
  setLargeur(l);
  setHauteur(h);
}

Dimension::Dimension(const Dimension& objet)
{
  setLargeur(objet.largeur);
  setHauteur(objet.hauteur);
}

Dimension::~Dimension()
{
  cout << "--Destructeur Dimension--" << endl;
}

void Dimension::setLargeur(int vL)
{
  if(vL < 0) return;
  largeur = vL;
}

void Dimension::setHauteur(int vH)
{
  if(vH < 0) return;
  hauteur = vH;
}

int Dimension::getLargeur() const
{
  return largeur;
}

int Dimension::getHauteur() const
{
  return hauteur;
}

void Dimension::Affiche() const
{
  cout << "Largeur : " << getLargeur() << endl;
  cout << "Hauteur : " << getHauteur() << endl;
}

ostream& operator<<(ostream& s,const Dimension& dim)
{
 s << dim.hauteur << "/" << dim.largeur;

 return s;
}

istream& operator>>(istream& s, Dimension& dim)
{
 int h, l;

 // Saisie de h, l et verification de leur valeurs

 do
 {
   cout << "hauteur : ";
   cin >> h;

 }while(h < 0);

  do
  {
    cout << "largeur : ";
    cin >> l;

  }while(l < 0);

 dim.largeur = l;
 dim.hauteur = h;

 return s;
}

bool Dimension::operator==(const Dimension& dim) const 
{
    return (hauteur == dim.getHauteur() && largeur == dim.getLargeur());
}

bool Dimension::operator!=(const Dimension& dim) const 
{
    return !(*this == dim);
}

