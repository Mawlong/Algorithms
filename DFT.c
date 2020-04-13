#include <complex.h>
#include <stdio.h>
#define PI 3.14159
void dft(double a[],double y[], int n)
{
    int i,j;
    double complex w1=1+I*(0),w2=(cos(2*PI/n)+I*(sin(2*PI/n))),s=(0+I*(0));
    for(i=0;i<n;i++)
    {
        s=a[n-1]+I*(0);
        for(j=n-2;j>=0;j--)
        {
            s=s*w1+a[j];
        }
        y[i]=creal(s);
        w1=w1*w2;
    }
}

int main()
{
    int n,i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    printf("Enter the value of the coefficients:\n");
    double a[n],y[n];
    for(i=0;i<n;i++)
        scanf("%lf",&a[i]);
    dft(a,y,n);
    for(i=0;i<n;i++)
        printf("%lf ",y[i]);
}
