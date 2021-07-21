#include<stdio.h>

int ary[10][10],completed[10],n,cost=0;

void Input()
{
	int i,j;

	printf("Enter the number of cities: ");
	scanf("%d",&n);

	printf("\nEnter the Cost Matrix:\n");

	for(i=0;i < n;i++)
	{
		printf("\nEnter Elements of Row: %d\n",i+1);

		for( j=0;j < n;j++)
			scanf("%d",&ary[i][j]);

		completed[i]=0;
	}

	printf("\n\nThe cost list is:");

	for( i=0;i < n;i++)
	{
		printf("\n");

		for(j=0;j < n;j++)
			printf("\t%d",ary[i][j]);
	}
}

void mincost(int city)
{
	int i,ncity;

	completed[city]=1;

	printf("%d--->",city+1);
	ncity=least(city);

	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);
		cost+=ary[city][ncity];

		return;
	}

	mincost(ncity);
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;

	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}

	if(min!=999)
		cost+=kmin;

	return nc;
}

int main()
{
	Input();

	printf("\n\nThe Path is:\n");
	mincost(0);

	printf("\n\nMinimum cost is %d\n ",cost);

	return 0;
}

/*
4
0 2 3 4
2 0 8 3
5 8 0 1
7 3 1 0
*/
/*
output:
Enter the number of cities: 4

Enter the Cost Matrix:

Enter Elements of Row: 1
0 2 3 4

Enter Elements of Row: 2
2 0 8 3

Enter Elements of Row: 3
5 8 0 1

Enter Elements of Row: 4
7 3 1 0


The cost list is:
        0       2       3       4
        2       0       8       3
        5       8       0       1
        7       3       1       0

The Path is:
1--->2--->4--->3--->1

Minimum cost is 11
*/
