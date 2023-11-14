#include "Couleur.h"
#include "RGBException.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

const Couleur Couleur::ROUGE(255, 0, 0);
const Couleur Couleur::VERT(0, 255, 0);
const Couleur Couleur::BLEU(0, 0, 255);
const Couleur Couleur::BLANC(255, 255, 255);
const Couleur Couleur::NOIR(0, 0, 0);

Couleur::Couleur()
{
	setRouge(100);
	setVert(100);
	setBleu(100);
}

Couleur::Couleur(int r, int v, int b)
{
	setRouge(r);
	setVert(v);
	setBleu(b);
}

Couleur::Couleur(const Couleur& color)
{
	setRouge(color.getRouge());
	setVert(color.getVert());
	setBleu(color.getBleu());
}

Couleur::~Couleur()
{
	
}

void Couleur::setRouge(int r)
{
	if(r < 0) throw RGBException(r, "La composante rouge ne peut pas être négative!"); // création d'une instance qui permet d'effectuer le catch en cas de souci
	if(r > 255) throw RGBException(r, "La composante rouge ne peut pas aller au delà de 255!");

	rouge = r;
}

void Couleur::setVert(int v)
{
	if(v < 0) throw RGBException(v, "La composante verte ne peut pas être négative!");
	if(v > 255) throw RGBException(v, "La composante verte ne peut pas aller au delà de 255!");

	vert = v;
}

void Couleur::setBleu(int b)
{
	if(b < 0) throw RGBException(b, "La composante bleue ne peut pas être négative!");
	if(b > 255) throw RGBException(b, "La composante bleue ne peut pas aller au delà de 255!");

	bleu = b;
}
	
int Couleur::getRouge() const
{
	return rouge;
}

int Couleur::getVert() const
{
	return vert;
}

int Couleur::getBleu() const
{
	return bleu;
}

void Couleur::Affiche() const
{
	cout << "Rouge : " << getRouge() << endl;
	cout << "Vert  : " << getVert() << endl;
	cout << "Bleu  : " << getBleu() << endl;
}

ostream& operator<<(ostream& s,const Couleur& color)
{
	s << color.getRouge() << " | " << color.getVert() << " | " << color.getBleu() << endl;

	return s;
}

void Couleur::Save(ofstream& fichier) const
{
	int rouge = getRouge();
	int vert = getVert();
	int bleu = getBleu();

	fichier.write((char*)&rouge, sizeof(int));
	fichier.write((char*)&vert, sizeof(int));
	fichier.write((char*)&bleu, sizeof(int));
}

void Couleur::Load(ifstream& fichier)
{
	int rouge, vert, bleu;

	fichier.read((char*)&rouge, sizeof(int));
	fichier.read((char*)&vert, sizeof(int));
	fichier.read((char*)&bleu, sizeof(int));

	setRouge(rouge);
	setVert(vert);
	setBleu(bleu);
}