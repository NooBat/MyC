#include "SymbolTable.h"
#include "SymbolTable.cpp"
using namespace std;

void test(string filename)
{
    SymbolTable *st = new SymbolTable();
    try
    {
        st->run(filename);
    }
    catch (exception &e)
    {
        cout << e.what();
    }
    delete st;
}

int main(int argc, char **argv)
{
    string filename = "/Users/danielnguyen/Repo/C++/Assignment1-2/testcase/test5.txt";

    test(filename);
    return 0;
}