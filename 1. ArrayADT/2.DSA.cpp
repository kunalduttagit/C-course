//
//  DSA.cpp
//  C++ course
//
//  Created by Kunal Dutta on 08/08/22.
//

#include <stdio.h>
#include <math.h>

int factorial (int k) {
    if(k==1) return 1;
    return factorial(k-1)*k;
}

double cosof(double x, int n)
{
    static double p=1;
    
    if(n==1)
        return 1;
    else {
      
        double ans = cosof(x, n-1);
        p *= x*x;
        double f = factorial((2*n)-2);
        if(n%2 == 0)
        return ans - p/f;
        else return ans + p/f;
    }
}


int main(){
    printf("%lf\n", cosof(1,6));
    printf("%lf",cos(1));
    return 0;
}
