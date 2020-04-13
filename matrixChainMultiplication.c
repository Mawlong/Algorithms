#include<stdio.h>
#include<limits.h>

#define size 10

void print_optimal_parens(int s[size][size], int i,int j)
{
    if(i==j)
        printf("A%d ",i);
    else
    {
        printf("(");
        print_optimal_parens(s,i,s[i][j]);
        print_optimal_parens(s,s[i][j]+1,j);
        printf(")");
    }
}

void matrix_chain_order(int p[], int n)
{
    int l,k, j,q, i, s[size][size],m[size][size];
    for(i=1;i<=n;i++)
    {
        m[i][i]=0;
    }
    for(l=2;l<=n;l++) //l = level
    {
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i][j] = INT_MAX;
            for(k=i;k<=j-1;k++) //i<=k<j
            {
                q = m[i][k] + m[k+1][j] +  p[i-1]* p[k]* p[j] ;
                if(q<m[i][j])
                {
                    m[i][j]= q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\nSolution: ");
    print_optimal_parens(s,1,n);
    printf("\n");

    printf("\nThe matrix containing total number of products\n\n");
    for(i=n;i>=1;i--)
    {
        for(j=n; j>=i; j--)
            printf("%d ",m[i][j]);
        printf("\n");
    }

    printf("\n\nThe matrix containing the total value of k\n\n");
    for(i=n-1; i>=1; i--)
    {
        for(j=n;j>=i+1;j--)
            printf("%d ",s[i][j]);
        printf("\n");
    }
}


int main()
{
    int n,i,p[size];
    printf("\nPlease enter the number of matrices to be checked:\n");
    scanf("%d",&n);
    printf("\nEnter the dimensions consecutively\n");
    for(i=0;i<=n;i++){
        scanf("%d",&p[i]);
    }
    matrix_chain_order(p,n);
}


