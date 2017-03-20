#include <stdio.h>
int main()
{
	char a;
	int b,c;
	scanf("%c %d %d",&a,&b,&c);
	switch(a)
	{
		case '+':printf("%d",b+c);break;
		case '-':printf("%d",b-c);break;
		case '*':printf("%d",b*c);break;
		case '/':printf("%d",b/c);break;
	}
	return 0;
 } 
