#include<stdio.h>
int max(int a,int b){
    return a>b?a:b;
}

int main(){
    int n,m;
    printf("Enter no. of items(n) and Knapsack weight(m) : \n");
    scanf("%d %d",&n,&m);
    int p[n],wt[n],k[n+1][m+1];
    for(int i=0;i<n;i++){
        printf("Enter profit(p) and weight(w) of %d item : ",i+1);
        scanf("%d %d",&p[i],&wt[i]);
    }

    for(int i=0;i<=n;i++){
        for(int w=0;w<=m;w++){
            if(i==0 || w==0){
                k[i][w]=0;
            }
            else if(wt[i]<=w){
                k[i][w]=max((p[i]+k[i-1][w-wt[i]]),k[i-1][w]);
            }
            else{
                k[i][w]=k[i-1][w];
            }
        }
    }
    printf("----------------\nmax Profit = %d\n",k[n][m]);

}
/*input:
4 7

1 1
4 3
5 4
7 5
*/
/*
output:
Enter no. of items(n) and Knapsack weight(m) :
4 7
Enter profit(p) and weight(w) of 1 item : 1 1
Enter profit(p) and weight(w) of 2 item : 4 3
Enter profit(p) and weight(w) of 3 item : 5 4
Enter profit(p) and weight(w) of 4 item : 7 5
----------------
max Profit = 9
*/
