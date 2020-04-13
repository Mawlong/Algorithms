#include<stdio.h>

void merge(int arr[], int beg, int mid, int end)
{
    int size = sizeof(arr)/sizeof(arr[0]);
    int i=beg, j=mid+1, index=beg, temp[size], k=0;
    while((i<=mid) && (j<=end))
    {
        if(arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
            
        }
        else
        {
            temp[index] = arr[j];
            j++;
            
        }
        index++;
    }
    if(i>mid)
    {
        while(j<=end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++)
        arr[k]=temp[k];
}



void merge_sort(int arr[], int beg, int end){
    int mid;
    if(beg<end)
    {
        mid = (beg+end)/2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
}



int main()
{
    printf("\n****************************************************************\n\t\tWELCOME TO MERGE SORT\n\n");
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int arr[size], i=0;
    printf("\nEnter the elements of the array: \n");
    for(i=0;i<size;i++)
            scanf("%d", &arr[i]);
    merge_sort(arr, 0, size-1);
    printf("\n The sorted array is: \n");
    for(i=0;i<size;i++)
        printf(" %d ", arr[i]);
    printf("\n\n\t\tTHANK YOU!\n****************************************************************\n\n\n");
}
