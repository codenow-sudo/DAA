#include<stdio.h>
#include <stdlib.h>
int x[100],count=0;

void print(int n){
    int i,j;
    count++;
    printf("\n\nSolution #%d:\n",count);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(x[i]==j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}
int Place(int k,int i){
    for(int j=1;j<=k-1;j++){
        if((x[j]==i) || ( abs(x[j]-i)==abs(j-k))){
            return 0;
        }
    }
    return 1;
}

void Nqueens(int k,int n){
    for(int i=1;i<=n;i++){
        if(Place(k,i)){

            x[k]=i;

            if(k == n){
                print(n);
            }else{
                Nqueens(k+1,n);
            }
        }

    }

}

int main(){
    int n,k=1;
    printf("Enter n value : ");
    scanf("%d",&n);
    Nqueens(k,n);
    printf(" Total Solutions: %d",count);
    return 0;
}

/*
4
*/
/*
output:
Enter n value : 4


Solution #1:
*       Q       *       *
*       *       *       Q
Q       *       *       *
*       *       Q       *


Solution #2:
*       *       Q       *
Q       *       *       *
*       *       *       Q
*       Q       *       *
 Total Solutions: 2
*/
