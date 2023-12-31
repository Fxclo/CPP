#include "RGBException.h"
#include <iostream>
#include <string.h>

using namespace std;

RGBException::RGBException() : Exception()
{
	setValeur(0);

	cout << "--Constructeur par défaut RGBException--" << endl;
}

RGBException::~RGBException()
{
	cout << "--Destructeur RGBException--" << endl;
}


RGBException::RGBException(int val, string message) : Exception(message) 
{
	setValeur(val);

	cout << "--Constructeur d'init RGBException--" << endl;
}

/*
RGBException::RGBException(const RGBException& except) : Exception(except)
{
	setMessage(except.UserMessage);
	setValeur(except.valeur);

	cout << "--Constructeur de copie RGBException--" << endl;
}*/

int RGBException::getValeur() const
{
    return valeur;
}

void RGBException::setValeur(int val) 
{
    valeur = val;
}