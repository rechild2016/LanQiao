#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define up 0
#define down 1
#define left 2
#define right 3

int finishpos;
char start[10],finish[10];
int search(char *a)//�ҵ��ո�λ��
{
	int i=-1;
	for( i=0;i<9;i++)
	{
		if(a[i]=='.')
		return i;
	}
}
void swap(char *a,char *b)//������������
{
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int move(char *a,int pos,int dir)//�ƶ��ո�
{
	if(pos<3 && dir == up)return 0;//�ƶ�ʧ��
	else if(pos>5 && dir == down)return 0;//�ƶ�ʧ��
	else if((pos%3==0) && dir == left)return 0;//�ƶ�ʧ��
	else if((pos%3==2) && dir == right)return 0;//�ƶ�ʧ��
	else{
		switch(dir)
		{
			case up:	swap(&a[pos],&a[pos-3]);break;
			case down:	swap(&a[pos],&a[pos+3]);break;
			case left:	swap(&a[pos],&a[pos-1]);break;
			case right:	swap(&a[pos],&a[pos+1]);break;
			default :return 0;
		}
	}
	return 1;
}
int solve(char* a,int n)
{
	int pos=search(a);
	if(pos==finishpos)//���ܳɹ���
	{
		if(strcmp(a,finish)==0)
		printf("%d",n);
		return 1;
	}
	else if(n<1000)
	{
		if(move(a,pos,up))
		{
			if(solve(a,n+1)==0)
			move(a,search(a),down);//��ԭ
			else return 1;
		}
		else if(move(a,pos,down))
		{
			if(solve(a,n+1)==0)
			move(a,search(a),up);//��ԭ
			else return 1;
		}
		else if(move(a,pos,left))
		{
			if(solve(a,n+1)==0)
			move(a,search(a),right);//��ԭ
			else return 1;
		}
		else if(move(a,pos,right))
		{
			if(solve(a,n+1)==0)
			move(a,search(a),left);//��ԭ
			else return 1;
		}
	}
	return 0;
}

int main()
{
	int ans=0;
	scanf("%s",start);
	scanf("%s",finish);
	finishpos=search(finish);
	ans=solve(start,0);
	if(ans==0)
	printf("-1");
	return 0;
}
 
