#include<iostream>
using namespace std;
int main()
{
    double n;
    scanf("%lf",&n);
    double l = -n, r = n;
    while(r - l > 1e-8)
    {
        double mid = ( r + l )/ 2;
        if(mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%.6lf",r);
    return 0;

}