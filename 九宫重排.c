#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define up 0
#define down 1
#define left 2
#define right 3

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

int main()
{
	char start[10],finish[10];
	scanf("%s",start);
	scanf("%s",finish);
	move(start,search(start),up);
	printf("%s\n",start);
	printf("%s\n",finish);
	return 0;
}
 
