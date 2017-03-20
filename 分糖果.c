#include <stdio.h>
#include <stdlib.h>

int (*a)[3]={NULL};
int swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

int sort(int a[][3], int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = 0 ; j < len-1; j++)
		{
			if (a[j][0] > a[j+1][0])
			{
				swap(&a[j ][0], &a[j+1][0]);
				swap(&a[j][1], &a[j+1][1]);
				swap(&a[j ][2], &a[j+1][2]);

				a[j ][1]+= a[j ][2];
				a[j+1][1] += a[j+1][2];

				a[j][2]++;
				a[j+1][2]++;
			}
		}
	}
	return 0; 
}
int main()
{
	int n;
	int i;
	int sum = 0;
	scanf("%d", &n);
	a = (int (*)[3])malloc(sizeof(int *)*n);
	for (i = 0; i < n; i++)
	{
		scanf(" %d", &a[i][0]);
		a[i][1] = 0;
		a[i][2] = 1;
	}
	sort(a, n);
	for (i = 0; i < n; i++)
	{
		sum+=a[i][1];
	}
	printf("%d",sum);
	free(a);
	
	return 0;
}
