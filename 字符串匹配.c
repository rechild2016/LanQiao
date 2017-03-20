#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char s[60];
	char *str;
	int i,j,k,n,l;
	scanf("%d",&n);
	scanf("%s",&s);
	str=(char *)malloc(sizeof(char)*n);
	l=strlen(s);
	for(i=0;i<l-n;i++)
	{
		for(j=i+1;j<l;j++)
		{
			str=&s[j];
			for(k=0;k<n;k++)
			{
				if(str[k]==s[i+k])
				{
					if(k==n-1)
					{
						for(k=0;k<n;k++)
						{
							printf("%c",str[k]);
						}
						return 0; 
					}
				}
				else break;
			}
		}
	}

	return 0;
}
