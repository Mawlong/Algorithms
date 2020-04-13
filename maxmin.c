#include<stdio.h>
int max,min;
void maxmin(int,int);
int a[100];
void main(){
	int n,i;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	max=min=a[0];
	maxmin(0,n-1);
	printf("Tha max element is:%d\n",max);
	printf("The min element is:%d",min);
}
void maxmin(int i,int j){
	int max1, min1, mid;
 if(i==j)
 {
  max = min = a[i];
 }
 else
 {
  if(i == j-1)
  {
   if(a[i] <a[j])
   {
    max = a[j];
    min = a[i];
   }
   else
   {
    max = a[i];
    min = a[j];
   }
  }
  else
  {
   mid = (i+j)/2;
   maxmin(i, mid);
   max1 = max; min1 = min;
   maxmin(mid+1, j);
   if(max <max1)
    max = max1;
   if(min > min1)
    min = min1;
  }
 }
}
