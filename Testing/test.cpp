#include<bits/stdc++.h>

using namespace std;

int main()
{  
    int number;

    cin >> number;
    int temp = number;
    int digit = 0;

    int result = 0;
    if (temp == 0) cout << number << endl;
    else 
    {
        while (temp > 0)
        {
            temp /= 10;
            digit++;
        }

        for (int i = 0; i < digit; i++)
        {
            
        }
    }

    

    return 0;
}
