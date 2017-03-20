#include <stdio.h>
#include <string.h>

int CharToInt(char str[])
{
	int i=0,j=0;
	int temp=0,len;
	len=strlen(str);
	
	while(i< len)
	{
		if(str[i]>='0' &&str[i]<='9')
		{
			temp *= 10;
			temp+=str[i]-'0';
		}
		i++;
	}
	return temp;
}
int main()
{
	int i,j,n,way=0;
	int **a;
	char str[300];
	scanf("%d",&n);		//三角形层数

	a=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)//分层填数字
	{
		a[i]=(int *)malloc((i+1)*sizeof(int *));		//第i层的个数
		for(j=0;j<i+1;j++)
		{
			scanf("%s",&str);		//每次遇到空格就结束
			a[i][j]=CharToInt(str);
		}
	}//n行数组填写完毕
	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
		{
			if(j>=way && j<=way+1)//只能在斜线范围内
			{

			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}