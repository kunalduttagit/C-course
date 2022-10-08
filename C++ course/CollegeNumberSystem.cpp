//
//  College.cpp
//  C++ course
//
//  Created by Kunal Dutta on 25/08/22.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <math.h>
#include <vector>
#define loop(n) for(int i=2; i<n; i++)
using namespace std;

void oct_to_bin(int n);
int dec_to_binary(int n, bool flag);
void hexadec_to_binary (string s);
void dec_to_octal(int n);
int octal_to_dec (int n);


int main()
{
    int choice;
    cout << "1.Decimal Number to Binary\n2.Hexadecimal to Decimal\n3.Decimal to Octal\n4.Octal to Binary"<<'\n';
    cin >> choice;
    
    if(choice == 1)
    {
        int n;
        cin >> n;
        dec_to_binary(n, false);
    }
    if(choice == 2)
    {
        string s;
        cin >> s;
        hexadec_to_binary(s);
    }
    if(choice == 3)
    {
        int n;
        cin >> n;
        dec_to_octal(n);
    }
    if(choice == 4)
    {
        int n;
        cin >> n;
        oct_to_bin(n);
    }
}


int dec_to_binary(int n, bool flag) {
    int bin = 0, i=0;

    while( n != 0)
    {
        int bit = n & 1;
        bin += bit * pow(10, i);

        n >>= 1;
        i++;
    }

    if(flag) {
        return bin;
    }
    else {
        cout << bin;
        return 0;
    }
}

void hexadec_to_binary (string s)
{
    int dec = 0;
    int k = 0;
    for(int i = s.length() - 1; i>=0; i--)
    {
        if(s[i]>= '0' && s[i]<='9')
        {
            dec += ((s[i]-48)*pow(16, k));
            k++;
        }
        if(s[i]>= 'A' && s[i]<='F')
        {
            dec += ((s[i]-55)*pow(16, k));
            k++;
        }
        if(s[i]>= 'a' && s[i]<='f')
        {
            dec += ((s[i]-87)*pow(16, k));
            k++;
        }
    }
    cout << dec;
}

void dec_to_octal(int n) {
    int oct = 0, i=0;

    while( n != 0)
    {
        while (n != 0)
        {
            oct  += ((n%8)*pow(10, i));
            n/=8;
            i++;
        }
    }

    cout << oct;
}


void oct_to_bin(int n)
{
    int x = octal_to_dec(n);
    //cout << x<< endl;
    int bin = dec_to_binary(x, true);
    
    cout << bin;
}

int octal_to_dec (int n)
{
    int dec = 0;
    int k = 0;
    while(n != 0)
    {
        dec += (n%10)*pow(8, k);
        n/=10;
        k++;
    }
    return dec;
}
