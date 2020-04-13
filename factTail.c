//Factorial using tail recurrsion
#include<stdio.h>
int a = 1;
void fact(int n, int b)
{    
    if( n==1 || n==0 )
        a=b;
    else
    {
        a = n*a;
        fact((n-1),a);
    }
}

int main()
{
    int n;
    printf("\n\n\n\n\nPlease enter the number whose factorial is to be calculated: ");
    scanf("%d",&n);
    fact(n,1);
    printf("\nThe factorial of %d is %d \n\n\n\n",n,a);
    return 0;
}