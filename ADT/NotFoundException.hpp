#ifndef _NOT_FOUND_EXCEPTION
#define _NOT_FOUND_EXCEPTION

#include<iostream>
#include<string>
#include<cstring>
#include<stdexcept>

using namespace std;
class NotFoundException : public domain_error
{
public:
    NotFoundException(const string& msg = ""): domain_error("Not Found Exception: " + msg)
    {

    }
};

#endif