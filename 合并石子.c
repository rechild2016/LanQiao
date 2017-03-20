#include <stdio.h>

#define MAXN (1000+10)

int stone[MAXN]={0};
int start,finish;
unsigned long long cost=0;
void merge(int *a,int len)
{
	int i=0,temp;
	for(;i<len-1;i++)
	{
		if(a[i]==0)
		{
			a[i]=a[i+1];
			a[i+1]=0;
		}
	}
}


int main()
{
	int n,i;
	int min=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&stone[i]);	
	}
	finish=n;
	while(finish>1)
	{	
		min=(stone[0]+stone[1]);
		start=0; 
		for(i=1;i<finish-1;i++)//找最小的合并费用 
		{
			if(min>stone[i]+stone[i+1])
			{
				min=(stone[i]+stone[i+1]);
				start=i;
			}
		}
		
		cost+=(stone[start]+stone[start+1]);//统计费用 
		stone[start]+=stone[start+1];//合成一堆 
		stone[start+1] =0;
		merge(stone,finish);
		finish--; 
	}
	
	printf("%d",cost);
	return 0;
}
