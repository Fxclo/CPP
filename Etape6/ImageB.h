#ifndef IMAGEB_H
#define IMAGEB_H
#include "Dimension.h"
#include "Image.h"
#include "Couleur.h"

class MyQT;

class ImageB : public Image
{
	private:
	
	bool matrice[L_MAX][H_MAX];

	public:

	static Couleur couleurTrue;
	static Couleur couleurFalse;

	ImageB(); 												// constructeur par défaut
  	~ImageB(); 												// destructeur
  	ImageB(int id, const char* N); 							// constructeur d'initialisation
  	ImageB(const ImageB& image1); 							// constructeur de copie
  	ImageB(int id, const char* N, const Dimension& dim); 	// constructeur d'initialisation complet
  	ImageB(const char* fichier); 							// construteur par initialisation avec le path du fichier

  	void setBackground(bool valeur);
  	void setPixel(int x, int y, bool valeur);
  	bool getPixel(int x, int y) const;

  	void Affiche() const;
  	void Dessine() const;
  	void exportToFile(const char* fichier, const char* format);

  	ImageB& operator=(const ImageB& image);
  	friend std::ostream& operator<<(std::ostream& s,const ImageB& image);
};

#endif