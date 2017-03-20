#include <stdio.h>

int a,b;
int n,s;
int Sequence(int num,int sum)
{
    if(num==0 )
    {
        if(sum == s)
            return 1;
        else 
            return 0;
    }
    num--;
    return (Sequence(num,sum+num*a)+Sequence(num,sum-num*b))%100000007;

}


int main()
{
    int a0=0;
    int max,min;
    int i,sum=0;
    scanf("%d %d %d %d",&n,&s,&a,&b);
    //确定初值的取值范围
    min=(s-(n*n)*a/2)/n;
    max=(s+(n*n)*b/2)/n;
    for(i=min;i<=max;i++)
        sum+=Sequence(n,i*n);
    printf("%d\n",sum);
    return 0;
}
