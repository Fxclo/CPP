#ifndef XYEXCEPTION_H
#define XYEXCEPTION_H
#include "Exception.h"

using namespace std;

class XYException : public Exception
{
private:
	char coordonnee;

public:

	XYException();
	~XYException();
	XYException(char coord, string message);
	//RGBException(const RGBException& exept);

	char getCoordonnee() const;
	void setCoordonnee(char coord);
};

#endif