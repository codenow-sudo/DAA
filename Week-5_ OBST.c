#include<stdio.h>
#include<limits.h>
int a[100],p[100],q[100],w[100][100],c[100][100],r[100][100];

void obst(int n){
    int i,b,j,k,min,min1,temp,root;
   for(i=0; i <= n; i++)
	{
				w[i][i] = q[i];
			 	c[i][i] = 0;
				r[i][i] = 0;
	}
	//printf("\n");
	for(b=0; b < n; b++)
	{
		for(i=0,j=b+1; j < n+1 && i < n+1; j++,i++)
		{
		    if(i!=j && i < j)
			{
				w[i][j] = p[j] + q[j] + w[i][j-1];

				min = INT_MAX;
				for(k = i+1; k <= j; k++)
				{
					min1 = c[i][k-1] + c[k][j] + w[i][j];
					if(min > min1)
					{
						min = min1;
						temp = k;
					}
				}
				c[i][j] = min;
				r[i][j] = temp;
			}
		}
		printf("\n");
	}
	printf("Minimum cost = %d\n",c[0][n]);
	root = r[0][n];
	printf("Root  = %d \n",root);
}
int main(){
    int n;
    printf("Optimal Binary Search Tree\n");
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        printf("p[%d] = ",i);
        scanf("%d",&p[i]);
    }
    for(int i=0;i<=n;i++){
        printf("q[%d] = ",i);
        scanf("%d",&q[i]);
    }
    obst(n);
    return 0;
}

/*
4
10 15 20 25
3 3 1  1
2 3 1 1 1
*/
/*
output:
Optimal Binary Search Tree
Enter the number of nodes: 4
a[1] = 10
a[2] = 15
a[3] = 20
a[4] = 25
p[1] = 3
p[2] = 3
p[3] = 1
p[4] = 1
q[0] = 2
q[1] = 3
q[2] = 1
q[3] = 1
q[4] = 1




Minimum cost = 32
Root  = 2

*/
