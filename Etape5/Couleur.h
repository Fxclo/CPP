#ifndef COULEUR_H
#define COULEUR_H

#include <iostream>

class Couleur
{
	private:

	int rouge;
	int vert;
	int bleu;

	public:

	Couleur();
	~Couleur();
	Couleur(int r, int v, int b);
	Couleur(const Couleur& color);

	void setRouge(int rouge);
	void setVert(int vert);
	void setBleu(int bleu);

	int getRouge() const;
	int getVert() const;
	int getBleu() const;

	void Affiche() const;

	friend std::ostream& operator<<(std::ostream& s,const Couleur& color);

	static const Couleur ROUGE;
	static const Couleur VERT;
	static const Couleur BLEU;
	static const Couleur BLANC;
	static const Couleur NOIR;
};

#endif