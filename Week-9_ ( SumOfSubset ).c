#include <stdio.h>
#include <stdlib.h>
static int m=0;
int w[100],x[100];

void sos(int s,int k,int r)
{
    int i=0;
    x[k]=1;
    if(s+w[k] == m)
    {
        printf("\n");
        for(i=1;i<=k;i++)
        {
            printf("\t %d",x[i]);
        }

    }
    else if(s+w[k]+w[k+1]<=m){
        sos(s+w[k],k+1,r-w[k]);
    }

    if((s+r-w[k])>=m && (s+w[k+1])<=m)
    {
        x[k]=0;
        sos(s,k+1,r-w[k]);
    }
}


void main()
{
    int i=0,sum=0,n;
    printf("enter size:\n");
    scanf("%d",&n);
    printf("enter %d elements :",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        sum=sum+w[i];
        x[i]=0;
    }
    printf("enter the sum to be obtained:");
    scanf("%d",&m);
    if(sum<m)
    {
        printf("not possible to obtain any subset \n");
        exit(1);
    }
    printf("possible subsets are (0 indicates exclusion and 1 indicates inclusion):");
    sos(0,1,sum);
}

/*
5
1 2 3 4 5
5
*/

/*
output:
enter size:
5
enter 5 elements :1 2 3 4 5
enter the sum to be obtained:5
possible subsets are (0 indicates exclusion and 1 indicates inclusion):
         1       0       0       1
         0       1       1
         0       0       0       0       1
*/
