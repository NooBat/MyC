#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{  
    ifstream myfile;
    ofstream output;
    myfile.open("HINHVE.INP", fstream::in);
    output.open("HINHVE.OUT", fstream::out | fstream::app);

    int n;
    int sc = 0;
    int pc = 0;
    if (myfile.is_open())
    {
        string a;
        getline(myfile, a);
        n = stoi(a);
    }

        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= 1; j--)
            {
                cout << " ";
            }
            if (i == 1)
            {
                cout << "*" << endl;
                sc++;
            }
            else if (i == n)
            {
                for (int j = 1; j <= n * 2 - 1; j++)
                {
                    cout << "*";
                    sc++;
                }
                cout << endl;
            }
            else 
            {
                cout << "*";
                sc++;
                for (int j = 1; j <= 2 * i - 1; j++)
                {
                    cout << "+";
                    pc++;
                }
                cout << "*" << endl;
                sc++;
            }
        }

    return 0;
}
