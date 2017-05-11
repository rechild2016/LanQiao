#include<stdio.h>  
#include<time.h>  
  
#define H 3     // �������һ��������ֻȡ����С��2���������Ƕ�8���������������Խ�ʡ�ܶ�ʱ��  
    
int fx[8] = {-2,-1,1,2,2,1,-1,-2}, fy[8] = {1,2,2,1,-1,-2,-2,-1}, f[8] = {-15,-6,10,17,15,6,-10,-17};  
                        // fx[] �� fy[] ��ʾ���ڶ�ά�İ˸����򣬸���ά����x��y�ã�f[]��ʾһά�İ˸����򣬸�����a�á�    
int dep = 1;            // dep Ϊ�ݹ����ȣ������ڵ�ǰλ�����Ѿ����˶��ٲ�    
int count, z = 0, zz  = 0;            // count ��ʾĿ��Ҫ�����ֽⷨ���� z ��¼��ǰ����˶����ֽⷨ��zz ��¼�������л��ݵĴ���    
int out[100001][8][8], F[8], a[64];         // out[][][] ��¼���еı���·����a[] ��һά�����¼ 8*8 ��������ı���·��    
  
  
// ������ʼ���꣬�Դ�ű���·��������a���г�ʼ��    
int Prepare()    
{    
    int i, j, n;    
    printf("��������ʼ������꣺\n");    
    printf("x=");    
    scanf("%d", &i);    
    printf("\by=");    
    scanf("%d", &j);    
    printf("��Ҫ�Ľ����Ŀcount=");    
    scanf("%d", &count);    
    n = i * 8 + j - 9;                // ����ʼ��Ķ�ά���� x��y ת����һά���� n ���Ӷ��������� a[64] ��·����¼    
    for(i = 0; i<64; i++)        // a[64] ����� 8*8 ��������ı���·��������֮ǰ�Ƚ��������ʼ��    
        a[i] = 0;    
    a[n] = 1;    
    return n;    
}   
  
  
// Sortint() �����Ե� n ����һ�����С�������һ����ѡ�����������򣬽�������� b[][] ����   
// c ��ʾǰ������ڽ�� n ���ĸ�λ�á�    
void Sorting(int b[64][H], int n, int c)    
{    
    int i, j, x, y, m1, m2, k, k1, l=1, xx, yy;    
    if(c != -1)    
        c = (c + 8 - 4) % 8;    
    for(i=0; i<8; i++)  //���ڵ�ǰ�ڵ�İ˸�����  
    {    
        F[i] = -1;  //F��¼�˸��������һ��������һ���ж��ٸ�  
        m1 = n + f[i];    
        x = n / 8 + fx[i];    
        y = n % 8 + fy[i];  //������һ��������  
        if(c!=i && x>=0 && x<8 && y>=0 && y<8 && a[m1]==0)  //�����һ������  
        {    
            F[i]++;    
            for(j=0; j<8; j++)  //������һ���İ˸�����  
            {    
                m2 = m1 + f[j];    
                xx = x + fx[j];    
                yy = y + fy[j];  //��������һ��������  
                if(xx>=0 && xx<8 && yy>=0 && yy<8 && a[m2]==0)  //�������һ������  
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
  
    
// ��������·��    
void Running(int n)    
{    
    int i, j, k;    
    int b[64][H], s[64];         // b[][] ���������һ�������к����������    
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
                    printf("\n��ɣ���\n");    
                    printf("���ݵĴ�����%d\n", zz);    
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
    
  
// ������еı���·��    
void Output()    
{    
    int i, j, k;    
    printf("\n\n����'1'չʾ��ϸ����������'0'�˳�����");    
    scanf("%d", &count);    
    if(count)    
    {    
        for(i=0; i<z; i++)    
        {    
            printf("��%d���⣺\n", i+1);    
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
    printf("����ʱ�䣺%.3f ms\n",(finish-start));  
    Output();   
}  
