#ifndef DSA_EXCEPTION_H
#define DSA_EXCEPTION_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
class InvalidInstruction : public exception
{
    string mess;

public:
    virtual ~InvalidInstruction() throw() {
        return ;
    }
    InvalidInstruction(string instruction)
    {
        mess = "Invalid: " + instruction;
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
class TypeMismatch : public exception
{
    string mess;

public:
    virtual ~TypeMismatch() throw() {
        return ;
    }
    TypeMismatch(string instruction)
    {
        mess = "TypeMismatch: " + instruction;
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
class Undeclared : public exception
{
    string mess;

public:
    virtual ~Undeclared() throw() {
        return ;
    }
    Undeclared(string instruction)
    {
        mess = "Undeclared: " + instruction;
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
class Redeclared : public exception
{
    string mess;

public:
    virtual ~Redeclared() throw() {
        return ;
    }
    Redeclared(string instruction)
    {
        mess = "Redeclared: " + instruction;
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
class Unclosedmaze[col][row] : public exception
{
    string mess;

public:
    virtual ~Unclosedmaze[col][row]() throw() {
        return ;
    }
    Unclosedmaze[col][row](int level)
    {
        mess = "Unclosedmaze[col][row]: " + to_string(level);
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
class Unknownmaze[col][row] : public exception
{
    string mess;

public:
    virtual ~Unknownmaze[col][row]() throw() {
        return ;
    }
    Unknownmaze[col][row]()
    {
        mess = "Unknownmaze[col][row]";
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
#endif