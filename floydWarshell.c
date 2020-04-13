#include<stdio.h>
int main()
{
    int n,i,j,k;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);

    int AM[n][n],d[n][n],pi[n][n];
    

    printf("\nEnter the Adjacency matrix with infinity as 9999\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&AM[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            d[i][j] = AM[i][j]; 
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(AM[i][j]==0 || AM[i][j]==9999)
                pi[i][j] = 0;
            else
                pi[i][j] = i;
        }
    }

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(d[i][k]+ d[k][j]< d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }


    printf("\n\nThe all pair shortest path is :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    

    printf("\n\n");
    printf("The path followed is :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                printf("INF ");
            else
                printf("%d ", pi[i][j]+1);
        }
        printf("\n");
    }
}