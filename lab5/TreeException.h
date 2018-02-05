/**
	@file	TreeException.h
	exceptions
	@author	Brady Helkenn
	@date	12/07/2014
*/
#ifndef TREE_EXCEPTION
#define TREE_EXCEPTION

#include<stdexcept>
#include<string>
using namespace std;

class TreeLogicException: public logic_error
{
public:
	TreeLogicException(const string& Message = ""): logic_error(Message.c_str())
	{}
};
#endif