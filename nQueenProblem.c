#include<stdio.h>
#include<math.h>
 
int x[20], ansNum;
 
int main()
{
 int n,i,j;
 void NQueen(int k,int n);
 
 printf("\n\nEnter the number of Queen for n Queen Problem: ");
 scanf("%d",&n);
 NQueen(1,n);
 printf("\n\n");
 return 0;
}
 

void print(int n)
{
 int i,j;
 printf("\n\nAnswer %d: \n", ++ansNum);
 printf("(");
 for(i=1;i<=n;i++)
 {
    if(i!=n)
        printf("%d, ", x[i]);
    else
        printf("%d", x[i]);
 }
 printf(")");

}
 
int place(int k,int column)
{
 int i;
 for(i=1;i<=k-1;++i)
 {
  if((x[i]==column) || (abs(x[i]-column)==abs(i-k)))
   return 0;               
 }
 
 return 1;                  
}
 

void NQueen(int k,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(k,column))
  {
   x[k]=column;
   if(k==n) 
    print(n); 
   else 
    NQueen(k+1,n);
  }
 }
}