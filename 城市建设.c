#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
���ű� ���н���
    n������m���ɽ���ĵ�· ������С������
*/
#define VNUM 10
#define INFITY 65535
/*int edge[VNUM][VNUM]={
    {0,	7,	INFITY,	5,	INFITY,	INFITY,	INFITY},
    {7,	0,	8,	9,	7,	INFITY,	INFITY},
    {INFITY,	8,	0,	INFITY,	5,	INFITY,	INFITY},
    {5,	9,	INFITY,	0,	15,	6,	INFITY},
    {INFITY,	7,	5,	15,	0,	8,	9},
    {INFITY,	INFITY,	INFITY,	6,	8,	0,	11},
    {INFITY,	INFITY,	INFITY,	INFITY,	9,	11,	0},
};  */  
int edge[VNUM][VNUM];   
int lowcost[VNUM];          //��¼Vnew��ÿ���㵽V���ڽӵ����̱�
int addvnew[VNUM];          //���ĳ���Ƿ����Vnew
int adjecent[VNUM]={0};     //��¼V����Vnew���ڽ��ĵ�
int Pier[VNUM];             //��¼��ͷ����    
int n,m;

int Prime(int start)
{
    int sumweight=0;
    int i,j,k=0;
    for( i=0;i<n;i++)        
    {
        lowcost[i]=edge[start][i];
        addvnew[i]=-1;       //�����е�����Vnew֮�⣬����ֻҪ��Ӧ��Ϊ-1���ͱ�ʾ��Vnew֮��
    }
    addvnew[start]=0;      //�����start����Vnew
    adjecent[start]=start;

    for(i=0;i<n-1;i++)
    {
        int min=INFITY;
        int v=-1;
        for(j=1;j<n;j++)
        {
            if(addvnew[j] == -1 && lowcost[j] < min)//��Vnew֮��Ѱ�����·��
            {
                min=lowcost[j];
                v=j; 
            }
        }
        if(Pier[adjecent[v]]>0 && Pier[v]>0 && lowcost[v]>Pier[adjecent[v]]+Pier[v])
        {
        	lowcost[v]=Pier[adjecent[v]]+Pier[v];
        	Pier[adjecent[v]]=0;
        	Pier[v]=0;
		}
        if(v!=-1)
        {
            addvnew[v]=0;   //��v����Vnew��
          //  printf("%d-->%d\t%d\n",v+1,adjecent[v]+1,lowcost[v]);
            sumweight += lowcost[v];
            for(j=0;j<n;j++)
            {
                if(addvnew[j]==-1 && edge[v][j]<lowcost[j])
                {
                    lowcost[j]=edge[v][j];  //�����������㵽Vnew���ϵ�lowcost
                    adjecent[j]=v;
                }
            }
        }

    }
    return sumweight;
}

int main()
{
    int i,j;
    int a,b,c;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		edge[i][j]=INFITY; 
	}
    for(i=0;i<m;i++)
    {
    	scanf("%d %d %d",&a,&b,&c);//��·������
    	edge[a-1][b-1]=c;
    	edge[b - 1][a - 1] = c;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&Pier[i]);//��ͷ����
		edge[i][i]=0;
	}

	m=Prime(0);
    printf("%d",m);

    return 0;
}
