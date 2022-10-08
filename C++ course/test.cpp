//
//  test.cpp
//  C++ course
//
//  Created by Kunal Dutta on 13/01/22.


#include <iostream>
#include <algorithm>
#include <math.h>
#define loop(n) for(int i=0; i<n; i++)
using namespace std;
int digits (int z)
{
    int count=0;
    while(z != 0)
    {
        count++;
    }
    return count;
}
bool isAmstrong(int x, int y)
{
  int temp = x;
  int k=0;
  while(x != 0)
  {
    int a = x%10;
    k += pow(a,y);
    x/=10;
  }
    if(k==temp) return true; else return false;
}
int main()
{
    int n;
    cin >> n;
    int a = digits(n);
    if(isAmstrong(n,a))  cout << "yes";
    else cout << "no";
    return 0;
}


