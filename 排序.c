#include <stdio.h>
#include <stdlib.h>

int quicksort(int s[],int l,int r)
 {
 	int i=l,j=r;
 	int x=s[l];
 	
 	if(l>=r)return 0;
	  
 	while(i<j)
 	{
 		while(i<j && s[j]>=x)		//从右向左找第一个小于x的数 
 			j--;
 		if(i<j)
 		 	s[i++]=s[j];
		  
		while(i<j && s[i]<x)		//从左向右找第一个大于等于x的数 
			i++;
		if(i<j)
		 	s[j--]=s[i];
	 }
	 s[i]=x;
	quicksort(s,l,i-1);		//分治法递归 
	quicksort(s,i+1,r);
	
 }
 
int main()
{
	int i,n;
	int key,temp;
	int *a;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
	{	
		scanf(" %d",&temp);
		a[i]=temp;
	}
	
	quicksort(a,0,n-1);	
	
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
		
	}
	printf("\n");
	return 0;	
 } 
 


