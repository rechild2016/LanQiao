#include <stdio.h>

#define Max(a,b) (a)>(b)?(a):(b)

int main()
{
	int a,b,c;
	int i,k;
	scanf("%d %d %d",&a,&b,&c);
	i=Max(a,b);
	i=Max(i,c);
	k=a*b*c;
	for(;i<k;i++)
	{
		if(i%a==0 && i%b==0 && i%c==0)
		break;
	}
	printf("%d",i);
	return 0;
 } 
