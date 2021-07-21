#include <stdio.h>
#include <stdlib.h>
int n, adj[100][100];
int x[100]= {-1};
int sol=0;

void printSolution(){
    sol++;
    printf("Solution %d : ", sol);
    for(int i=0; i<n; i++)
        printf("%d\t", x[i]+1);
    printf("1\n\n");
}

void nextVertex(int k){
    int j=0;
    while(1){
        x[k] = x[k]+1;
        if(x[k] == n)
            x[k] = -1;
        if(x[k] == -1)
            return;
        if(adj[x[k-1]][x[k]] == 1){
            for(j=0; j<k; j++){
                if(x[j] == x[k])
                    break;
            }
            if(j == k){
                if(k<n-1 || k==n-1 && adj[x[n-1]][0] == 1)
                    return;
            }
        }
    }
}

void hamiltonian(int k){
    while(1){
        nextVertex(k);
        if(x[k] == -1)
            return;
        if(k == n-1)
            printSolution();
        else
            hamiltonian(k+1);
    }
}

int main()
{
    int i, j;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    x[0] = 0;
    adj[n][n];
    printf("Enter adjacency matrix : \n");
    for(i=0;i<n; i++){
        for(j=0;j<n;j++)
            scanf("%d", &adj[i][j]);
    }
    hamiltonian(1);
    printf("Total number of solutions = %d", sol);
    return 0;
}

/*
6
0 1 1 1 0 0
1 0 1 0 0 1
1 1 0 1 1 0
1 0 1 0 1 0
0 0 1 1 0 1
0 1 0 0 1 0
*/

/*
output:
Enter number of vertices : 6
Enter adjacency matrix :
0 1 1 1 0 0
1 0 1 0 0 1
1 1 0 1 1 0
1 0 1 0 1 0
0 0 1 1 0 1
0 1 0 0 1 0
Solution 1 : 1  2       6       5       3       4       1

Solution 2 : 1  2       6       5       4       3       1

Solution 3 : 1  3       2       6       5       4       1

Solution 4 : 1  3       4       5       6       2       1

Solution 5 : 1  4       3       5       6       2       1

Solution 6 : 1  4       5       6       2       3       1

Total number of solutions = 6
*/
