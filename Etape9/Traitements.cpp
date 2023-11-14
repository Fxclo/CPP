#include <iostream>
#include "Traitements.h"
#include <sstream>
#include <algorithm>  
#include <vector>     

using namespace std;

ImageB Traitements::Seuillage(const ImageNG& imageIn, int seuil)
{
	int largeur = imageIn.getDimension().getLargeur();
    int hauteur = imageIn.getDimension().getHauteur();

	string ancienNom = string(imageIn.getNom());  // Convertir char* en string
    string nouveauNom = ancienNom + "-seuil" + to_string(seuil); // Modification du nom

	ImageB imageOut(imageIn.getId(), nouveauNom.c_str(), imageIn.getDimension());

	for(int i = 0; i < largeur; i++)
  	{
    	for(int j = 0; j < hauteur; j++)
    	{
    		if(imageIn.getPixel(i, j) > seuil) imageOut.setPixel(i, j, true);
    		else imageOut.setPixel(i, j, false);
    	}
 	}

 	return imageOut;
}

ImageNG Traitements::FiltreMoyenneur(const ImageNG& imageIn, int taille) 
{
    if (taille % 2 == 0 || taille < 3) return imageIn; // si la taille est paire ou < à 3..

    int largeur = imageIn.getDimension().getLargeur();
    int hauteur = imageIn.getDimension().getHauteur();

    string ancienNom = string(imageIn.getNom());  // Convertir char* en string
    string nouveauNom = ancienNom + "-moyenne" + to_string(taille); // Modification du nom

    ImageNG imageOut(imageIn.getId(), nouveauNom.c_str(), imageIn.getDimension());

    for (int i = 0; i < largeur; ++i) 
    {
        for (int j = 0; j < hauteur; ++j) 
        {
            // Calculer la moyenne des pixels autour du pixel (i, j)
            int sommePixels = 0;
            int nombrePixels = 0;

            // Parcourir la zone autour du pixel (i, j) avec le filtre de taille spécifiée
            for (int di = -taille / 2; di <= taille / 2; di++) 
            {
                for (int dj = -taille / 2; dj <= taille / 2; dj++) 
                {
                    int x = i + di;
                    int y = j + dj;

                    // Vérifier si le pixel est à l'intérieur de l'image
                    if (x >= 0 && x < largeur && y >= 0 && y < hauteur) 
                    {
                        sommePixels = sommePixels + imageIn.getPixel(x, y);
                        nombrePixels++;
                    }
                }
            }

            int moyenne = sommePixels / nombrePixels;
            imageOut.setPixel(i, j, moyenne);
        }
    }

    return imageOut;
}


ImageNG Traitements::FiltreMedian(const ImageNG& imageIn, int taille)
{
	if (taille % 2 == 0 || taille < 3) return imageIn; // si la taille est paire ou < à 3..

    int largeur = imageIn.getDimension().getLargeur();
    int hauteur = imageIn.getDimension().getHauteur();

    string ancienNom = string(imageIn.getNom());  // Convertir char* en string
    string nouveauNom = ancienNom + "-median" + to_string(taille); // Modification du nom

    ImageNG imageOut(imageIn.getId(), nouveauNom.c_str(), imageIn.getDimension());

    for (int i = 0; i < largeur; i++)
    {
    	for (int j = 0; j < hauteur; j++)
    	{
    		vector<int> VecPixels; // Vecteur de pixels

    		for (int di = -taille / 2; di <= taille / 2; di++) 
    		{
                for (int dj = -taille / 2; dj <= taille / 2; dj++) 
                {
                    int x = i + di;
                    int y = j + dj;

                    if (x >= 0 && x < largeur && y >= 0 && y < hauteur)  
                    	VecPixels.push_back(imageIn.getPixel(x, y)); // ajout du pixel dans le vecteur
                }
            }

            // Trie le vecteur des pixels
            sort(VecPixels.begin(), VecPixels.end());

            int mediane = VecPixels[VecPixels.size() / 2];
            imageOut.setPixel(i, j, mediane);
    	}
    }

    return imageOut;
}

ImageNG Traitements::Erosion(const ImageNG& imageIn, int taille)
{
	if (taille % 2 == 0 || taille < 3) return imageIn; // si la taille est paire ou < à 3..

    int largeur = imageIn.getDimension().getLargeur();
    int hauteur = imageIn.getDimension().getHauteur();

    string ancienNom = string(imageIn.getNom());  // Convertir char* en string
    string nouveauNom = ancienNom + "-erosion" + to_string(taille); // Modification du nom

    ImageNG imageOut(imageIn.getId(), nouveauNom.c_str(), imageIn.getDimension());

    for (int i = 0; i < largeur; i++)
    {
    	for (int j = 0; j < hauteur; j++)
    	{
    		int min = 255;

    		for (int di = -taille / 2; di <= taille / 2; di++) 
    		{
                for (int dj = -taille / 2; dj <= taille / 2; dj++) 
                {
                    int x = i + di;
                    int y = j + dj;

                    if (x >= 0 && x < largeur && y >= 0 && y < hauteur)
                    {
                    	if (min > imageIn.getPixel(x, y)) min = imageIn.getPixel(x, y);
                    }
                }
            }

            imageOut.setPixel(i, j, min);
    	}
    }

    return imageOut;
}

ImageNG Traitements::Dilatation(const ImageNG& imageIn, int taille)
{
	if (taille % 2 == 0 || taille < 3) return imageIn; // si la taille est paire ou < à 3..

    int largeur = imageIn.getDimension().getLargeur();
    int hauteur = imageIn.getDimension().getHauteur();

    string ancienNom = string(imageIn.getNom());  // Convertir char* en string
    string nouveauNom = ancienNom + "-dilatation" + to_string(taille); // Modification du nom

    ImageNG imageOut(imageIn.getId(), nouveauNom.c_str(), imageIn.getDimension());

    for (int i = 0; i < largeur; i++)
    {
    	for (int j = 0; j < hauteur; j++)
    	{
    		int max = 0;

    		for (int di = -taille / 2; di <= taille / 2; di++) 
    		{
                for (int dj = -taille / 2; dj <= taille / 2; dj++) 
                {
                    int x = i + di;
                    int y = j + dj;

                    if (x >= 0 && x < largeur && y >= 0 && y < hauteur)
                    {
                    	if (max < imageIn.getPixel(x, y)) max = imageIn.getPixel(x, y);
                    } 	
                }
            }

            imageOut.setPixel(i, j, max);
    	}
    }

    return imageOut;
}

ImageNG Traitements::Negatif(const ImageNG& imageIn)
{
    int largeur = imageIn.getDimension().getLargeur();
    int hauteur = imageIn.getDimension().getHauteur();

    string ancienNom = string(imageIn.getNom());  // Convertir char* en string
    string nouveauNom = ancienNom + "-negatif"; // Modification du nom

    ImageNG imageOut(imageIn.getId(), nouveauNom.c_str(), imageIn.getDimension());

    for(int i = 0; i < largeur; i++)
  	{
    	for(int j = 0; j < hauteur; j++)
    	{
    		int NG = 255 - imageIn.getPixel(i, j);
    		imageOut.setPixel(i, j, NG);
    	}
 	}

 	return imageOut;
}