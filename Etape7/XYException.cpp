#include "XYException.h"
#include <iostream>
#include <string.h>

using namespace std;

XYException::XYException() : Exception()
{
	setCoordonnee('d');

	cout << "--Constructeur par défaut XYException--" << endl;
}

XYException::~XYException()
{
	cout << "--Destructeur XYException--" << endl;
}


XYException::XYException(char coord, string message) : Exception(message) 
{
	setCoordonnee(coord);

	cout << "--Constructeur d'init XYException--" << endl;
}

/*
XYException::XYException(const XYException& except) 
{
	setMessage(except.UserMessage);

	cout << "--Constructeur de copie XYException--" << endl;
}*/

char XYException::getCoordonnee() const
{
    return coordonnee;
}

void XYException::setCoordonnee(char coord) 
{
    coordonnee = coord;
}