#include <stdio.h>
#include <stdlib.h>

int w[10],x[10],d;

void Sum_Subset(int s,int k,int r)
{
    int i;
    static int b=1;
    x[k]=1;
    if(w[k]+s==d)
    {
        printf("\nSolution %d=",b++);
        for(i=1;i<=k;i++)
        {
            if(x[i]==1)
                printf("%d\t",w[i]);
        }
        printf("\n");
    }
    else if(s+w[k]+w[k+1]<=d)
          Sum_Subset(s+w[k],k+1,r-w[k]);
    if(s+r-w[k]>=d && s+w[k+1]<=d)
    {
        x[k]=0;
        Sum_Subset(s,k+1,r-w[k]);
    }
    if(b==1)
    {
        printf("\nNo Solutions");
        exit(0);
    }
}

void main()
{
    int i,n,sum=0;
    printf("Read number of elements\n");
    scanf("%d",&n);
    printf("Read elements in increasing order\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        sum=sum+w[i];
    }
    printf("Read value for d:");
    scanf("%d",&d);
    Sum_Subset(0,1,sum);
    return 0;
}
