#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int count;
int partition(int A[SIZE],int l,int r)
{

    int i,j,pivot,temp;
    pivot=A[l];
    i=l+1;
    j=r;
    while(1)
    {
        while(pivot>=A[i] && i<=r)
        {
            count++;
            i++;
        }
        while(pivot<A[j])
        {
            count++;
            j--;
        }
        count++;
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
        else
        {
            temp=A[j];
            A[j]=A[l];
            A[l]=temp;
            return j;
        }
    }
}

void quicksort(int A[SIZE],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(A,l,r);
        quicksort(A,l,s-1);
        quicksort(A,s+1,r);
    }
}

void main()
{
    int A[SIZE],i,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    quicksort(A,0,n-1);
    printf("\nSorted Array is\n");
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("\nCount=%d",count);
    return 0;
}
