#include<stdio.h>

void heapify(int arr[], int n, int i)
{
    int temp;
    int largest = i;  
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    if (largest != i)
    {
        temp = arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i=n-1; i>=0; i--)
    {
        temp = arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        printf("%d ",arr[i]);
}


int main()
{
    printf("\n****************************************************************\n\t\tWELCOME TO HEAP SORT\n\n");
    int i=0, size=0;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Please enter the Elements of the array \n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    heapSort(arr, size);
    printf("\n\nSorted array is \n");
    printArray(arr, size);
    printf("\n\n\t\tTHANK YOU!\n****************************************************************\n\n\n");
}
