#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
蓝桥杯 城市建设
    n个城市m条可建设的道路 计算最小生成树
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
int lowcost[VNUM];          //记录Vnew中每个点到V中邻接点的最短边
int addvnew[VNUM];          //标记某点是否加入Vnew
int adjecent[VNUM]={0};     //记录V中与Vnew最邻近的点
int Pier[VNUM];             //记录码头费用    
int n,m;

int Prime(int start)
{
    int sumweight=0;
    int i,j,k=0;
    for( i=0;i<n;i++)        
    {
        lowcost[i]=edge[start][i];
        addvnew[i]=-1;       //将所有点至于Vnew之外，这里只要对应的为-1，就表示在Vnew之外
    }
    addvnew[start]=0;      //将起点start加入Vnew
    adjecent[start]=start;

    for(i=0;i<n-1;i++)
    {
        int min=INFITY;
        int v=-1;
        for(j=1;j<n;j++)
        {
            if(addvnew[j] == -1 && lowcost[j] < min)//在Vnew之外寻找最短路径
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
            addvnew[v]=0;   //将v加入Vnew中
          //  printf("%d-->%d\t%d\n",v+1,adjecent[v]+1,lowcost[v]);
            sumweight += lowcost[v];
            for(j=0;j<n;j++)
            {
                if(addvnew[j]==-1 && edge[v][j]<lowcost[j])
                {
                    lowcost[j]=edge[v][j];  //更新其他顶点到Vnew集合的lowcost
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
    	scanf("%d %d %d",&a,&b,&c);//道路及费用
    	edge[a-1][b-1]=c;
    	edge[b - 1][a - 1] = c;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&Pier[i]);//码头费用
		edge[i][i]=0;
	}

	m=Prime(0);
    printf("%d",m);

    return 0;
}
