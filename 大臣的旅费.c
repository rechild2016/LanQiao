#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int **city;

int Travel(int start)
{
	int i,j,next;
	for (i = 0; i < n-1; i++)
	{
		if(city[start][i]!=0)
			for (j = i + 1; j < n; j++)
			{
				if (city[start][i] != 0 && city[i][j]==0)
				{
					city[j][i]=city[i][j] = city[start][i] + city[start][j];
				}
			}
	}
}
int main()
{
	int i, j;
	int P, Q, D;
	int max = 0;
	scanf("%d", &n);
	//内存分配
	city = (int **)malloc(sizeof(int*)*n);
	city[0] = (int*)malloc(sizeof(int)*n*n);
	for (i = 1; i < n ; i++)
	{
		city[i] = city[i - 1] + n;
	}
	//初始化为0
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			city[i][j] = 0;
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &P, &Q, &D);
		city[P-1][Q-1] = D;
		city[Q - 1][P - 1] = D;
	}
	for (i = 0; i < n; i++)
		Travel(i);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (max < city[i][j])max = city[i][j];
		}
	}
	max = max * 10 + (1 + max)*max / 2;
	printf("%d", max);
	return 0;
}
