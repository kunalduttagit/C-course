//
//  reccursion.c
//  C++ course
//
//  Created by Kunal Dutta on 18/08/22.
//

#include <stdio.h>
#include <math.h>

double factorial (int k) {
    if(k==1) return 1;
    return factorial(k-1)*k;
}

double sinof(double x, int n)
{
    static double p=1, f=1;;
    
    if(n==1)
        return x;
    else {
      
        double ans = sinof(x, n-1);
        p *= x*x;
        f *= ((2*n)-1)*((2*n)-2);
        if(n%2 == 0)
        return ans - p/f;
        else return ans + p/f;
    }
}


int main(){
    printf("%lf\n", sinof(0.5,7));
    printf("%lf",sin(0.5));
    return 0;
}
