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
class UnclosedBlock : public exception
{
    string mess;

public:
    virtual ~UnclosedBlock() throw() {
        return ;
    }
    UnclosedBlock(int level)
    {
        mess = "UnclosedBlock: " + to_string(level);
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
class UnknownBlock : public exception
{
    string mess;

public:
    virtual ~UnknownBlock() throw() {
        return ;
    }
    UnknownBlock()
    {
        mess = "UnknownBlock";
    }
    const char *what() const throw()
    {
        return mess.c_str();
    }
};
#endif