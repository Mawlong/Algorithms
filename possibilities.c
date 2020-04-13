#include <stdio.h>
int c1=0;
void place(int a[],int i,int j,int n,int k)
{
    int t,y,b[n],p,q,temp;
    if(i==n-1)
    {
        for(t=j;t<=k;t++)
         {
             a[i]=t;
             for(y=0;y<n;y++)
                 b[y]=a[y];
    
             
        for(p=0;p<n;p++)
        {
            for(q=0;q<n;q++)
            {
                if(b[p]<b[q])
                {
                    temp=b[p];
                    b[p]=b[q];
                    b[q]=temp;
                }
            }
        }

        for(y=0;y<n;y++)
            printf("%d",b[y]);
        printf("\n");
        c1++;
         }
    }

    else
    {
        int z=j;
        for(t=j;t<=k;t++)
        {
            a[i]=j;
            place(a,i+1,j,n,k);
            j++;
        }
    }


}

int main()
{
    int n,k,p,q,temp;
    printf("enter the size\n");
    scanf("%d",&n);
    printf("enter the number of digits\n");
    scanf("%d",&k);
    if (k>n)
    {
        printf("\nWrong input\n");
        return 0;
    }
    int a[n],i;
    for(i=0;i<k;i++)
        a[i]=i+1;
    if(i<n)
        place(a,i,1,n,k);
    else
    {
        for(p=0;p<n;p++)
        {
            for(q=0;q<n;q++)
            {
                if(a[p]<a[q])
                {
                    temp=a[p];
                    a[p]=a[q];
                    a[q]=temp;
                }
            }
        }
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
        c1++;
    }
    printf("count=%d\n\n",c1);
}
