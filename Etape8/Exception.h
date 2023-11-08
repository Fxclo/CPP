#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

using namespace std;

class Exception
{
protected:
	string UserMessage;

public:

	Exception() throw();
	virtual ~Exception() throw();
	Exception(string message);
	Exception(const Exception& exept);

	string getMessage() const;
	void setMessage(string message);
};

#endif