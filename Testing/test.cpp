#include<bits/stdc++.h>

using namespace std;

int main()
{  
    int n;
    cin >> n;
    int arr[n];
    bool checked[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        checked[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        if (!checked[i])
        {
            for (int j = i; j < n; j++)
            {
                if (arr[j] == arr[i])
                {
                    checked[j] = true;
                    count++;
                }
            }

            cout << "Frequency of " << arr[i] << ": " << count << endl;
        }
    }

    return 0;
}
