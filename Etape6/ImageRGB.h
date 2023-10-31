#ifndef IMAGERGB_H
#define IMAGERGB_H
#include "Dimension.h"
#include "Image.h"
#include "Couleur.h"

class MyQT;

class ImageRGB : public Image
{
	private:
	
	Couleur matrice[L_MAX][H_MAX];

	public:

	ImageRGB(); 											// constructeur par défaut
  	~ImageRGB(); 											// destructeur
  	ImageRGB(int id, const char* N); 						// constructeur d'initialisation
  	ImageRGB(const ImageRGB& image1); 						// constructeur de copie
  	ImageRGB(int id, const char* N, const Dimension& dim); 	// constructeur d'initialisation complet
  	ImageRGB(const char* fichier); 							// construteur par initialisation avec le path du fichier

  	void setBackground(const Couleur& color);
  	void setPixel(int x, int y, const Couleur& color);
  	Couleur getPixel(int x, int y) const;

  	void Affiche() const;
  	void Dessine() const;
  	void importFromFile(const char* fichier);
  	void exportToFile(const char* fichier, const char* format);

  	ImageRGB& operator=(const ImageRGB& image);
  	friend std::ostream& operator<<(std::ostream& s,const ImageRGB& image);
};

#endif