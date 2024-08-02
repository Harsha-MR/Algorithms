#include <stdio.h>
#include <stdlib.h>

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

void Floyds(int A[10][10],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
}

int main()
{
    int n,A[10][10],i,j;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    printf("\nRead Cost Matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&A[i][j]);
    Floyds(A,n);
    printf("\nAll pair shortest path is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}

