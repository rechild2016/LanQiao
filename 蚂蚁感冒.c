#include <stdio.h>
#include <stdlib.h>
#define MAXN 55

int n;
int coldnum=0;
typedef struct Ant{
	int pos;
	int cold;
}Ant;

Ant ant[MAXN]={0};


//�ж����ϸ�ð��Ⱦ 
void adjust()
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(abs(ant[i].pos) == abs(ant[j].pos))//����һ������ͬһλ�� 
			{
				ant[i].cold=ant[j].cold=(ant[i].cold | ant[j].cold);//��Ⱦ 
				ant[i].pos=-ant[i].pos;
				ant[j].pos=-ant[j].pos; 
			}
			else if(ant[i].pos+ant[j].pos == -1)//���н������л�����
			{
				ant[i].cold=ant[j].cold=(ant[i].cold | ant[j].cold);//��Ⱦ 
				
				if(ant[i].pos>0 && ant[i].pos<100)ant[i].pos--;//�ص���һλ�� 
				else ant[i].pos++;
				
				if(ant[j].pos>0 && ant[j].pos<100)ant[j].pos--;
				else ant[j].pos++;
				
				ant[i].pos=-ant[i].pos;		//�ı䷽�� 
				ant[j].pos=-ant[j].pos; 
			}
		 } 
}
int step(int pos,int status)
{
	if(pos<=100 && pos>-100)
	{
		if(pos<0)//������ 
		{
			if(pos==-1) {
				pos=200;//ֱ���ⲿ 
				coldnum+=status;
			}
			else
			{
				pos++;	
			}
			
		}
		else if(pos>0)//������ 
		{
			if(pos==100){
				pos=200;//ֱ���ⲿ 
				coldnum+=status;
			}
			else pos++;
		}
	}
	return pos;
}
int  action()
{
	int i;
	for(i=0;i<n;i++)
	{
		 ant[i].pos=step(ant[i].pos,ant[i].cold); 		 
	}
	adjust();
}

int main()
{
	int i=0;
	int numlave=1;
	scanf("%d",&n);
	for(;i<n;i++)
	{
		scanf("%d",&ant[i].pos);
		ant[i].cold=0;
	}
	ant[0].cold=1;	//��һ�����ϸ�ð��
	while(numlave !=0)
	{
		action();
		numlave=0;
		for(i=0;i<n;i++)
		{
			if(ant[i].pos>-100 && ant[i].pos<=100)
			numlave++;
		}
	}
	numlave=0;
	for(i=0;i<n;i++)
	{
		if(ant[i].cold==1)
		{
			numlave++;
		//	printf("%d\n",i);
		}
	}
	printf("%d",coldnum);	 
	return 0;
 } 
