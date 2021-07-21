#include <stdio.h>
#include<stdlib.h>
struct job{
    int j,d,profit;
};
int min(int a,int b)
    {
        if(a>b)
            return b;
        else
            return a;
    }
int main()
{
    int n,dmax=0;
    printf("Enter no of jobs: ");
    scanf("%d",&n);
    struct job arr[n];
     printf("Enter data:\nJob\tDeadline\tProfit\n");
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&arr[i].j,&arr[i].d,&arr[i].profit);
        if(dmax<arr[i].d){
            dmax=arr[i].d;
        }
    }
    /*printf("Display:\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",arr[i].j,arr[i].d,arr[i].profit);
    }*/
    struct job temp;
    //SORTING
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].profit<arr[j+1].profit){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Display:\nJob\tDead\tprofit\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",arr[i].j,arr[i].d,arr[i].profit);
    }
    int ti[dmax+1],maxprofit=0;
    for(int i=0;i<=dmax;i++){
        ti[i]=0;
    }
    int k;
    for(int i=0;i<n;i++){
        k=min(dmax,arr[i].d);
        while(k>=1){
            if (ti[k]==0){
               // printf("---k=%d\t%d\n",k,arr[i].j);
                ti[k]=arr[i].j;
                maxprofit+=arr[i].profit;
                break;
            }
            k=k-1;
        }
    }
    printf("\n");
    for(int i=1;i<=dmax;i++){
        printf("%d\t",ti[i]);

    }
    printf("\nMaxprofit=%d",maxprofit);
    return 0;
}
/*
input:
6
1 5 200
2 3 180
3 3 190
4 2 300
5 4 120
6 2 100

*/

/*
output:
Enter no of jobs: 6
Enter data:
Job     Deadline        Profit
1 5 200
2 3 180
3 3 190
4 2 300
5 4 120
6 2 100
Display:
Job     Dead    profit
4       2       300
1       5       200
3       3       190
2       3       180
5       4       120
6       2       100

2       4       3       5       1
Maxprofit=990
*/
