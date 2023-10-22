#include "Couleur.h"
#include <iostream>
#include <string.h>

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
	if(r < 0) return;

	rouge = r;
}

void Couleur::setVert(int v)
{
	if(v < 0) return;

	vert = v;
}

void Couleur::setBleu(int b)
{
	if(b < 0) return;

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