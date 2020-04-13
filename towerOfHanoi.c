#include<stdio.h>
int count = 0;
void tower(int n, char Beg, char Aux, char Last)
{
    if(n==1)
    {
        printf("Move disc 1 from %c to %c \n",Beg, Last);
        count++;
    }
    else
    {
        tower(n-1,Beg,Last,Aux);
        printf("\nMove disk %d from %c to %c\n",n,Beg,Last);
        count++;
        tower(n-1,Aux,Beg,Last);
    }
}
int main()
{
    int n;
    printf("\nPlease enter the number of disks:\n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("\nYou have entered 0 rings. ABORT!\n\n\n");
        return 0;
    }
    tower(n,'A','B','C');
    printf("\nThe total number of steps = %d\n\n",count);
    return 0;
}