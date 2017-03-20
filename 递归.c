#include <stdio.h>
#include <string.h>
#define N 101 
int a[N]={0};
int b[N]={0};
int c[N]={0};
char str[N];
char str2[N];
//字符串转int数组 
int StringToint(int a[],char str[])
{
	int len,i;
	len=strlen(str);
	for(i=len-1;i>=0;i--)
	{
		a[i]=str[len-1-i]-'0';
	}
	 
	return 0;
}
int CodePuls(int a[],int b[],int c[])
{
	int temp=0,i;
	for(i=0;i<N;i++)
	{
		c[i]=(a[i]+b[i]+temp)%10;
		temp=(a[i]+b[i]+temp)/10;
	}
	return 0;
}
int main()
{
	int n,i,len;
	scanf("%s",&str);
	scanf("%s",&str2);
	StringToint(a,str);
	StringToint(b,str2);
	CodePuls(a,b,c);
	len=(strlen(str)>=strlen(str2))?strlen(str):strlen(str2);//len 的长度取决于最长的一个串 
	if(c[len]!=0)printf("%d",c[len]);
	for(i=len-1;i>=0;i--)
	{
		printf("%d",c[i]);
	}
	return 0;
 } 
