#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION

#include<iostream>
#include<string>
#include<exception>

using namespace std;

class NotFoundException : public exception
{
public:
    NotFoundException(const string& msg = "");
}

NotFoundException::NotFoundException(const string& msg) : exception("Not Found Exception: " + msg)
{
    
}

#endif