#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str[400002]={0},j=0;
int dectobin(int n)
{	
	if(n==0)return 0;
	str[j++]=n%2;
	dectobin(n/2);
	
}
int main()
{
	int n,m,i;
	char string[100000];
	scanf("%s",&string);
	m=strlen(string);
	for(i=m;i>=0;i--)
	{
		if(string[i]=='0')
		{
			j+=4;
			continue;
		}
		else if(string[i]>='0'&&string[i]<='9')dectobin(string[i]-'0');
			else if(string[i]>='A'&&string[i]<='F')dectobin(string[i]-'A'+10);
	}
	for(i=j-1;i>=0;i--)
	{
		
		printf("%d",str[i]);
	}
	return 0;
}
