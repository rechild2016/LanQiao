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
	scanf("%d",&n);		//�����β���

	a=(int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)//�ֲ�������
	{
		a[i]=(int *)malloc((i+1)*sizeof(int *));		//��i��ĸ���
		for(j=0;j<i+1;j++)
		{
			scanf("%s",&str);		//ÿ�������ո�ͽ���
			a[i][j]=CharToInt(str);
		}
	}//n��������д���
	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
		{
			if(j>=way && j<=way+1)//ֻ����б�߷�Χ��
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