#include<stdio.h>
int n,a[1000][1000],d[1000][1000],v=1,k,not[100];
int mini(int i)
{
    int l=1,min=1000;
    for(int j=1;j<=n;j++)
    {
        if(not[j]!=0)
                continue;
        if(min>d[i][j])
        {
            min=d[i][j];
            l=j;
        }
    }
    not[l]++;
    return l;
}
int mi(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    printf("Enter no. of vertices: \n");
    scanf("%d",&n);
    printf("Enter adjacency matrix: \n");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
                scanf("%d",&a[i][j]);
                if(a[i][j]==0)
                    a[i][j]=1000;
        }
    printf("Enter the staring vertex: \n");
    scanf("%d",&v);
    k=v;
    for(int i=1;i<=n;i++)
    {
        if(i>1)
            v=mini(i-1);
        for(int j=1;j<=n;j++)
        {
            if(i==1)
            {
                d[i][j]=a[v][j];
            }
            else
            {
                    if(j==k)
                        d[i][j]=1000;
                    else
                        d[i][j]=mi(d[i-1][j],d[i-1][v]+a[v][j]);
            }
        }
    }
    d[n-1][k]=0;
    for(int j=1;j<=n;j++)
    {
        if(d[n-1][j]!=1000)
            printf("distance from %d -> %d = %d\n",k,j,d[n-1][j]);
        else
            printf("distance from %d -> %d=infinity\n",k,j);
    }
}
/*
9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
1
*/
/*
output:
Enter no. of vertices:
9
Enter adjacency matrix:
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
Enter the staring vertex:
1
distance from 1 -> 1 = 0
distance from 1 -> 2 = 4
distance from 1 -> 3 = 12
distance from 1 -> 4 = 19
distance from 1 -> 5 = 21
distance from 1 -> 6 = 11
distance from 1 -> 7 = 9
distance from 1 -> 8 = 8
distance from 1 -> 9 = 14
*/
