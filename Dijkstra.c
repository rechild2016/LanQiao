#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 9
#define INFINITY 1<<30


typedef int Patharc[MAXVEX]; //存储最短路径下标的数组
typedef int ShotPathTable[MAXVEX];//存储各点到最短路径的权值和

typedef struct{
    int numVertexes;
    int arc[MAXVEX][MAXVEX];
}MGraph;

MGraph G;

void ShottestPath(MGraph G,int V0, Patharc *P,ShotPathTable *D)
{
    int v,w,k,min;
    int final[MAXVEX];
    for(v=0;v<G.numVertexes;v++)
    {
        final[v]=0;             //全部顶点初始化为 未找到最短路径
        (*D)[v]=G.arc[V0][v];   //将与V0有连线的顶点加上权值
        (*P)[v]=0;              //初始化路径数组P为0
    }
    (*D)[V0]=0;//V0到V0路径为0
    final[V0]=1;//不需要求路径

    //开始主循环，每次求得V0到某个顶底的最短路径
    for(v=1;v<G.numVertexes;v++)
    {
        min=INFINITY;
        for(w=0;w<G.numVertexes;w++)
        {
            if(!final[w] && (*D)[w]<min)
            {
                k=w;
                min=(*D)[w];
            }
        }
        final[k]=1;//目前找到V0到Vk的最小路径

        //修正当前最短路径及距离
        for(w=0;w<G.numVertexes;w++)
        {
            //如果经过顶点V的路径比现在这条路径的长度短的话 更新
            if(!final[w] && (min+G.arc[k][w]<(*D)[w]) )
            {
                (*D)[w]=min+G.arc[k][w];//修改当前路径长度
                (*P)[w]=k;//存放前驱顶点
            }
        }
        //得到一个顶点的最短路径
    }
}



int main()
{

    int i,j;
    int P[9],D[9];
    G.numVertexes=9;
    int a[9][9]={
        {0,1,5,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY},
        {1,0,3,7,5,INFINITY,INFINITY,INFINITY,INFINITY},
        {5,3,0,INFINITY,1,7,INFINITY,INFINITY,INFINITY},
        {INFINITY,7,INFINITY,0,2,INFINITY,3,INFINITY,INFINITY},
        {INFINITY,5,1,2,0,3,6,9,INFINITY},
        {INFINITY,INFINITY,7,INFINITY,3,0,INFINITY,5,INFINITY},
        {INFINITY,INFINITY,INFINITY,3,6,INFINITY,0,2,7},
        {INFINITY,INFINITY,INFINITY,INFINITY,9,5,2,0,4},
        {INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,7,4,0}
    };
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            G.arc[i][j]=a[i][j];
     ShottestPath(G,0,P,D);
     for(i=0;i<9;i++)
     printf("%d\t%d\n",P[i],D[i]);    
    return 0;
}
