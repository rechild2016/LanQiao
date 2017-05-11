#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 9
#define INFINITY 1<<30


typedef int Patharc[MAXVEX]; //�洢���·���±������
typedef int ShotPathTable[MAXVEX];//�洢���㵽���·����Ȩֵ��

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
        final[v]=0;             //ȫ�������ʼ��Ϊ δ�ҵ����·��
        (*D)[v]=G.arc[V0][v];   //����V0�����ߵĶ������Ȩֵ
        (*P)[v]=0;              //��ʼ��·������PΪ0
    }
    (*D)[V0]=0;//V0��V0·��Ϊ0
    final[V0]=1;//����Ҫ��·��

    //��ʼ��ѭ����ÿ�����V0��ĳ�����׵����·��
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
        final[k]=1;//Ŀǰ�ҵ�V0��Vk����С·��

        //������ǰ���·��������
        for(w=0;w<G.numVertexes;w++)
        {
            //�����������V��·������������·���ĳ��ȶ̵Ļ� ����
            if(!final[w] && (min+G.arc[k][w]<(*D)[w]) )
            {
                (*D)[w]=min+G.arc[k][w];//�޸ĵ�ǰ·������
                (*P)[w]=k;//���ǰ������
            }
        }
        //�õ�һ����������·��
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
