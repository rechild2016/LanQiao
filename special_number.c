#include <stdio.h>

int main()
{
	int n,i,temp,max,sum,min;
	int *a;
	scanf("%d",&n);	
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)max=a[i];
		if(a[i]<min)min=a[i];
		sum+=a[i];
	}
	printf("%d\n",max);
	printf("%d\n",min);
	printf("%d\n",sum);
	return 0;
 } 
