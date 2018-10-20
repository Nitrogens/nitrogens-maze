#include "stdafx.h"
#include "FileOpenException.h"


FileOpenException::FileOpenException(int _errorNumber):
	errorNumber(_errorNumber)	{}

int FileOpenException::getErrorNumber()
{
	return errorNumber;
}

FileOpenException::~FileOpenException()
{
}
