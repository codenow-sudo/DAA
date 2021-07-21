#include <stdio.h>
#include <string.h>

int i, j, m, n, LCS_table[20][20];
char S1[20] , S2[20] , b[20][20];

int lcsAlgo() {


  for (i = 0; i <= m; i++)
    LCS_table[i][0] = 0;
  for (i = 0; i <= n; i++)
    LCS_table[0][i] = 0;

  for (i = 1; i <= m; i++){
    for (j = 1; j <= n; j++) {
      if (S1[i - 1] == S2[j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
        b[i][j]='C';
      }
      else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]) {
        LCS_table[i][j] = LCS_table[i - 1][j];
        b[i][j]='U';
      }
      else {
        LCS_table[i][j] = LCS_table[i][j - 1];
        b[i][j]='L';
      }
    }
  }
   return 0;

}
void print_lcs(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='C')
    {
        print_lcs(i-1,j-1);
        printf("%c",S1[i-1]);

    }
    else if(b[i][j]=='U')
    {
        print_lcs(i-1,j);
    }
    else{
        print_lcs(i,j-1);
    }

}


int main() {
    printf("Enter strings s1 and s2:\n");
    scanf("%s%s",S1,S2);
     m = strlen(S1);
     n = strlen(S2);
    printf("LCS is: ");
    lcsAlgo();
    print_lcs(m,n);
    printf("\nLCS length is : %d",LCS_table[m][n]);

}

/*
acfghd
abfhd
*/
/*
output:
Enter strings s1 and s2:
acfghd
abfhd
LCS is: afhd
LCS length is : 4
*/
