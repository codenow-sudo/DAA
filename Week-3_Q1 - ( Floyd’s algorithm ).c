#include<stdio.h>
int a[1000][1000],c[1000][1000],n;
int min(int a,int b)
{
 return a>b?b:a;
}
void floyd()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=c[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]= min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}
int main()
{
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the weighted matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&c[i][j]);
        }
    }
    floyd();
    printf("The shortest path matrix is:\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            printf("%4d ",a[i][j]);
        }
        printf("\n");
    }
}




/*
4

0 99 3 99
2 0 99 99
99 7 0 1
6 99 99 0
*/
/*
output:
Enter the number of vertices:
4
Enter the weighted matrix
0 99 3 99
2 0 99 99
99 7 0 1
6 99 99 0
The shortest path matrix is:
   0   10    3    4
   2    0    5    6
   7    7    0    1
   6   16    9    0
*/
