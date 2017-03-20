#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,n,temp;
	for(i=0;i<32;i++)
	{
		temp=i%32;
		printf("%d",temp/16);
		temp=temp%16;
		printf("%d",temp/8);
		temp=temp%8;
		printf("%d",temp/4);
		temp=temp%4;
		printf("%d",temp/2);
		temp=temp%2;
		printf("%d",temp/1);
		printf("\n");
	}
	return 0;
 } 
