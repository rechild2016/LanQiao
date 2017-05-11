#include<stdio.h>  
#include<time.h>  
  
#define H 3     // 代表对下一步的排序只取出最小的2个，而不是对8个都排序，这样可以节省很多时间  
    
int fx[8] = {-2,-1,1,2,2,1,-1,-2}, fy[8] = {1,2,2,1,-1,-2,-2,-1}, f[8] = {-15,-6,10,17,15,6,-10,-17};  
                        // fx[] 和 fy[] 表示马在二维的八个方向，给二维坐标x和y用；f[]表示一维的八个方向，给数组a用。    
int dep = 1;            // dep 为递归的深度，代表在当前位置马已经走了多少步    
int count, z = 0, zz  = 0;            // count 表示目标要多少种解法，而 z 记录当前算出了多少种解法，zz 记录在运算中回溯的次数    
int out[100001][8][8], F[8], a[64];         // out[][][] 记录所有的遍历路径，a[] 用一维数组记录 8*8 棋盘中马的遍历路径    
  
  
// 输入起始坐标，对存放遍历路径的数组a进行初始化    
int Prepare()    
{    
    int i, j, n;    
    printf("请输入起始点的坐标：\n");    
    printf("x=");    
    scanf("%d", &i);    
    printf("\by=");    
    scanf("%d", &j);    
    printf("你要的解的数目count=");    
    scanf("%d", &count);    
    n = i * 8 + j - 9;                // 将起始点的二维坐标 x、y 转化成一维坐标 n ，从而方便数组 a[64] 的路径记录    
    for(i = 0; i<64; i++)        // a[64] 存放在 8*8 方格中马的遍历路径，搜索之前先进行清零初始化    
        a[i] = 0;    
    a[n] = 1;    
    return n;    
}   
  
  
// Sortint() 函数对点 n 的下一步进行“后续下一步可选择数”的排序，结果保存在 b[][] 里面   
// c 表示前驱结点在结点 n 的哪个位置。    
void Sorting(int b[64][H], int n, int c)    
{    
    int i, j, x, y, m1, m2, k, k1, l=1, xx, yy;    
    if(c != -1)    
        c = (c + 8 - 4) % 8;    
    for(i=0; i<8; i++)  //对于当前节点的八个方向  
    {    
        F[i] = -1;  //F记录八个方向的下一步的再下一步有多少个  
        m1 = n + f[i];    
        x = n / 8 + fx[i];    
        y = n % 8 + fy[i];  //这是下一步的坐标  
        if(c!=i && x>=0 && x<8 && y>=0 && y<8 && a[m1]==0)  //如果下一步存在  
        {    
            F[i]++;    
            for(j=0; j<8; j++)  //对于下一步的八个方向  
            {    
                m2 = m1 + f[j];    
                xx = x + fx[j];    
                yy = y + fy[j];  //这是再下一步的坐标  
                if(xx>=0 && xx<8 && yy>=0 && yy<8 && a[m2]==0)  //如果再下一步存在  
                    F[i]++;    
            }    
        }    
    }    
    b[n][0] = -1;    
    for(i=1; i<H; i++)    
    {    
        k = 9;    
        for(j=0; j<8; j++)    
        {    
            if(F[j]>-1 && F[j]<k)    
            {    
                k = F[j];  
                k1 = j;    
            }    
        }    
        if(k < 9)    
        {    
            b[n][l++] = k1;    
            F[k1] = -1;    
            b[n][0] = 1;    
        }    
        else    
        {    
            b[n][l++] = -1;    
            break;    
        }    
    }    
}     
  
    
// 搜索遍历路径    
void Running(int n)    
{    
    int i, j, k;    
    int b[64][H], s[64];         // b[][] 用来存放下一步的所有后续结点排序    
    s[0] = n;    
    Sorting(b, n, -1);    
    while(dep >= 0)    
    {    
        if(b[n][0]!=-1 && b[n][0]<H && b[n][b[n][0]]!=-1)    
        {    
            k = b[n][b[n][0]];    
            b[n][0]++;    
            n += f[k];    
            Sorting(b, n, k);    
            a[n] = ++dep;    
            s[dep-1] = n;    
            if(dep == 64)    
            {    
                for(i=0; i<8; i++)    
                    for(j=0; j<8; j++)    
                        out[z][i][j] = a[i*8+j];    
                z++;    
                if(z == count)    
                {    
                    printf("\n完成！！\n");    
                    printf("回溯的次数：%d\n", zz);    
                    break;    
                }    
            }    
        }    
        else    
        {    
            dep--;    
            zz++;    
            a[n] = 0;    
            n = s[dep-1];    
        }    
    }    
}    
    
  
// 输出所有的遍历路径    
void Output()    
{    
    int i, j, k;    
    printf("\n\n输入'1'展示详细遍历，输入'0'退出程序：");    
    scanf("%d", &count);    
    if(count)    
    {    
        for(i=0; i<z; i++)    
        {    
            printf("第%d个解：\n", i+1);    
            for(j=0; j<8; j++)    
            {    
                for(k=0; k<8; k++)    
                    printf("%3d", out[i][j][k]);    
                printf("\n");    
            }    
        }    
    }    
}    
  
void main()    
{    
    int n;    
    double start,finish;  
    n = Prepare();  
    start = clock();  
    Running(n);     
    finish = clock();  
    printf("运行时间：%.3f ms\n",(finish-start));  
    Output();   
}  
