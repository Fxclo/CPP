#ifndef IMAGE_H
#define IMAGE_H
#include "Dimension.h"

class Image
{
	public:

	static const int L_MAX = 500;
  	static const int H_MAX = 500;

	Image(); 											// constructeur par défaut
	virtual ~Image(); 									// destructeur
	Image(int id, const char* N);						// constructeur d'init. partiel
	Image(const Image& image1); 						// constructeur de copie
  	Image(int id, const char* N, const Dimension& dim); // constructeur d'initialisation complet
  	Image(const char* fichier); 						// construteur par initialisation avec le path du fichier

  	void setDimension(const Dimension& dim);
  	void setId(int val);
  	void setNom(const char* N);

  	Dimension getDimension() const;
  	int getId() const;
  	const char* getNom() const;

  	virtual void Affiche() const = 0;
  	virtual void Dessine() const = 0;
  	virtual void exportToFile(const char* fichier, const char* format) = 0;

	protected:

	int id;
  	char* nom;
  	Dimension dimension;
};

#endif