/**
	@file	UnsupportedOperationException.h
	exceptions
	@author	Brady Helkenn
	@date	12/07/2014
*/
#ifndef UNSUPPORTED_OPERATION_EXCEPTION
#define UNSUPPORTED_OPERATION_EXCEPTION

#include<stdexcept>
#include<string>
using namespace std;

class UnsupportedOperationException: public logic_error
{
public:
	UnsupportedOperationException(const string& Message = ""): logic_error(Message.c_str())
	{}
};
#endif