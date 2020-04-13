#include<stdio.h>

int partition(int a[], int beg, int end)
{
    int left, right, temp, loc, flag;
    loc = left = beg;
    right = end;
    flag = 0;
    while( flag != 1)
    {
        while((a[loc] <= a[right]) && (loc!=right))
            right--;
        if(loc==right)
            flag =1;
        else if(a[loc]>a[right])
        {
            temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;
            loc = right;
        }
        if(flag!=1){
            while((a[loc] >= a[left]) && (loc!=left))
                left++;
            if(loc==left)
                flag =1;
            else if(a[loc] <a[left]){
                temp = a[loc];
                a[loc] = a[left];
                a[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}


void quick_sort(int a[], int beg, int end)
{
    int loc;
    if(beg<end)
    {
        loc = partition(a, beg, end);
        quick_sort(a, beg, loc-1);
        quick_sort(a, loc+1, end);
    }
}

int main()
{
    printf("\n****************************************************************\n\t\tWELCOME TO QUICK SORT\n\n");
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int arr[size], i=0;
    printf("\nEnter the elements of the array: \n");
    for(i=0;i<size;i++)
        scanf("%d", &arr[i]);
    quick_sort(arr, 0, size-1);
    printf("\n The sorted array is: \n");
    for(i=0;i<size;i++)
        printf(" %d ", arr[i]);
    printf("\n\n\t\tTHANK YOU!\n****************************************************************\n\n\n");

}
