#ifndef RGBEXCEPTION_H
#define RGBEXCEPTION_H
#include "Exception.h"

using namespace std;

class RGBException : public Exception
{
private:
	int valeur;

public:

	RGBException();
	~RGBException();
	RGBException(int valeur, string message);
	//RGBException(const RGBException& exept);

	int getValeur() const;
	void setValeur(int val);
};

#endif