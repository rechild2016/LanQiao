#include <stdio.h>

#define Max(a,b) (a)>(b)?(a):(b)
#define Min(a,b) (a)<(b)?(a):(b)

int main()
{
	unsigned long long m,n,p;
	unsigned long long i,ret=0,len;
	unsigned long long *F=NULL;
	
	scanf("%d %d %d",&n,&m,&p);
	len=Max(n,m);
	F=(unsigned long long *)malloc(sizeof( unsigned long long)*(len+2));

	F[0]=0;	F[1]=1;
	for(i=2;i<=len;i++)
	{
		F[i]=F[i-2]+F[i-1];
	}
	/*printf("last=%I64u\n",F[len]);
	printf("len=%I64d\n",len);
	printf("F[n]=%I64u\n",F[n]);
	printf("F[m]=%I64u\n",F[m]);*/
	ret=0;
	for(i=1;i<=n;i++)
	{
		//printf("%-5d",F[i]);
			
		ret+=F[i];
		ret%=(Max(F[m],p));
	}
	
	ret%=(Min(F[m],p));	
	printf("%I64u",ret);
	free(F);
	return 0;
 } 
