#ifndef _PRECOND_VIOLATED_EXCEPTION
#define _PRECOND_VIOLATED_EXCEPTION

#include<stdexcept>
#include<string>

using namespace std;

class PrecondViolatedException : public logic_error {
public:
    PrecondViolatedException(const string& message = "");
};

PrecondViolatedException::PrecondViolatedException(const string& message) :
                          logic_error("Precondition Violated Exception: " + message) {

}
                    

#endif