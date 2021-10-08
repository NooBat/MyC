#include<bits/stdc++.h>

using namespace std;

string highAndLow(const string& numbers)
{
  //your code here
  string temp;
  string max; 
  string min;
  
  int i = 0;
  while (numbers[i] != ' ')
  {
    i++;  
  }
  
  max = numbers.substr(0, i);
  min = numbers.substr(0, i);
  
  i++;
  for (; i < (int)numbers.length(); i++)
  {
    int j = i;
    while (numbers[i] && numbers[i] != ' ') 
    {
      i++;
    }
    
    temp = numbers.substr(j, i - j);
    if (stoi(temp) > stoi(max)) 
    {
      max.clear();
      max = temp;
    }
    if (stoi(temp) < stoi(min))
    {
      min.clear();
      min = temp;
    }
    
    temp.clear();
  }
  
  return max + " " + min;
}
int main()
{
    string input = "8 3 -5 42 -1 0 0 -9 4 7 4 -4";

    cout << highAndLow(input);

    return 0;
}
