#include <stdio.h>


int gcd(int x, int y)
{
    int i=0, greatest=0;
    for(i=2;i<=x && i<=y; i++)
    {
        if(x%i==0 && y%i==0)
        greatest=i;
    }
    return greatest;
}


 int main(){
     int x=0, y=0;
     printf("Enter two integers: ");
     scanf("%d %d", &x, &y);
     printf("GCD of %d and %d is: %d \n", x, y, gcd(x,y));
 }
