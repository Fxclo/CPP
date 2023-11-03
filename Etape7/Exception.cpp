#include "Exception.h"
#include <iostream>
#include <string.h>

using namespace std;

Exception::Exception() throw()
{
	setMessage("");

	cout << "--Constructeur par défaut Exception--" << endl;
}

Exception::~Exception() 
{
    cout << "--Destructeur Exception--" << endl;
}

Exception::Exception(string message) 
{
	setMessage(message);

	cout << "--Constructeur d'init Exception--" << endl;
}

Exception::Exception(const Exception& except) 
{
	setMessage(except.UserMessage);

	cout << "--Constructeur de copie Exception--" << endl;
}

string Exception::getMessage() const
{
    return UserMessage;
}

void Exception::setMessage(string message) 
{
    UserMessage = message;
}