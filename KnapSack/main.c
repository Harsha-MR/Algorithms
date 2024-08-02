#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int n,w[10],v[10],V[10][10],W,i,j,X[10]={0};
    printf("Read number of objects:");
    scanf("%d",&n);
    printf("\nRead weights of the objects\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("\nRead profits of the objects\n");
    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);
    printf("\nRead Knapsack capacity:");
    scanf("%d",&W);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0||j==0)
                V[i][j]=0;
            else if(j<w[i])
                V[i][j]=V[i-1][j];
            else
                V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i]);
            printf("%d\t",V[i][j]);
        }
        printf("\n");
    }
    printf("\nThe maximum profit is %d",V[n][W]);
    i=n;
    j=W;
    while(i!=0 && j!=0)
    {
        if(V[i][j]!=V[i-1][j])
        {
            X[i]=1;
            j=j-w[i];
        }
        i=i-1;
    }
    printf("\nObjects included are\n");
    for(i=1;i<=n;i++)
    {
        if(X[i]==1)
            printf("\n %d object is included",i);
    }
    return 0;
}
