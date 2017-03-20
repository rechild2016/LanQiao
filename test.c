#include <stdio.h>

void swap(int a,int b)
{
	int t;
	t=a;
	a=b;
	b=t;	
}
int main()
{
	int n,m; 
	int i,j;
	int k;
	int *a;
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));//¶¯Ì¬·ÖÅäÄÚ´æ
	 for(i=0;i<n;i++)
	 {
	 	scanf(" %d",&a[i]);
	 }

	return 0;
}
