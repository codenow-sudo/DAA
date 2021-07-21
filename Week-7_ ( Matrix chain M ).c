#include <limits.h>
#include <stdio.h>
int i,j,n;
int s[100][100];
void printfunc(int i,int j)
{
  char ch='A';
  if(i==j)
  {
  printf("%c",ch+i-1);
  return ;
  }
  printf("(");
  printfunc(i,s[i][j]);
  printfunc(s[i][j]+1,j);
  printf(")");
}

int Mchain(int p[], int n)
{
    int m[n][n];
    int k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j]=k;
                }
            }
        }
    }
    i=1;j=n-1;
    printf("The optimal arramgement:");
    printfunc(i,j);
    printf("\n");
    return m[1][n - 1];
}

int main()
{
  int mat[100];
  printf("Enter Number of matrices:");
  scanf("%d",&n);
  n+=1;
  printf("Enter dimensions\n");
  for(int i=0;i<n;i++)
  {
    printf("Enter d%d::",i);
    scanf("%d",&mat[i]);
  }
    printf("Minimum number of multiplications is %d ",Mchain(mat,n));
    return 0;
}


/*

4

5
4
6
2
7

*/
/*
output:
Enter Number of matrices:4
Enter dimensions
Enter d0::5
Enter d1::4
Enter d2::6
Enter d3::2
Enter d4::7
The optimal arrangement:((A(BC))D)
Minimum number of multiplications is 158
*/
