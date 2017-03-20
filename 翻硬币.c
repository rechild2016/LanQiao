#include <stdio.h>
#include <string.h>
#define Turn(a) a=='o'?'*':'o'
#define MAXN (1000+10)

char CoinInit[MAXN];	//³õÊ¼×´Ì¬ 
char CoinTaget[MAXN];	//Ä¿±ê×´Ì¬ 

int main()
{
	int i,len;
	int twice=0;
	scanf("%s",CoinInit);
	scanf("%s",CoinTaget);
	len=strlen(CoinInit);
	for(i=0;i<len-1;i++)
	{
		if(CoinInit[i] != CoinTaget[i])
		{
			twice++;
			CoinInit[i]=Turn(CoinInit[i]);
			CoinInit[i+1]=Turn(CoinInit[i+1]);
		}
	}
//	printf("%s\n",CoinInit);
	
	printf("%d",twice);
	return 0;
} 
