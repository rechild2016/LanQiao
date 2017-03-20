#include <stdio.h>

typedef char* String;

void BuildNext(String T,int *next)
{
	int i = 1;
	int j = 0;
	next[1] = 0;

	while(i < T[0])
	{
		if(j == 0 || T[i] == T[j])
		{
			i++;
			j++;
			next[i]=j;
			/*if(T[i] != T[j])
			{
				next[i] = j;
			 } 
			 else
			 {
			 	next[i] = next[j];
			 }*/
		}
		else
		{
			j = next[j];//失配之后回溯j
		}
	}
}
//返回子串T在主串S第pos个字符后的位置
//若不存在 返回0
int Index_KMP(String S,String T,int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	BuildNext(T,next);

	while(i<=S[0] && j<=T[0])
	{
		if( 0== j || S[i] == T[j])
		{
			i++;
			j++;

		}
		else
		{
			j=next[j];
		}
	}
	if(j > T[0])
	{
		return i-T[0];
	} 
	else 
	{
		return 0;
	}
}



int main()
{
	char str[255] = " ababaaaba";
	char str2[10] = "aaa";
	int i=0;
	str[0]=9;
	i=Index_KMP(str,str2,2);
	printf("%d",i);
	return 0;
}
