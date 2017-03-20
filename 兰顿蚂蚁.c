#include <stdio.h>
#include <stdlib.h>

//0为白格  1为黑格 

int x,y,k;
int **a;

char Turn(char dir, int black)
{
	char Dir=0;
	if(black)//黑格
	{
		switch(dir)
		{
			case 'U':Dir='R';break;
			case 'D':Dir='L';break;
			case 'L':Dir='U';break;
			case 'R':Dir='D';break;
		}
	 }
	 else{
	 	switch(dir)
		{
			case 'U':Dir='L';break;
			case 'D':Dir='R';break;
			case 'L':Dir='D';break;
			case 'R':Dir='U';break;
		}
	 } 
	 return Dir;
}
void move(int x,int y, char dir,int k)
{
	if(k==0){//走完要求的步数 
		printf("%d %d",x,y);
		return ;
	}
	dir=Turn(dir,a[x][y]);
	a[x][y]=!a[x][y]; 
	switch(dir)//前进 
	{
		case 'U':x--;break;
		case 'D':x++;break;
		case 'L':y--;break;
		case 'R':y++;break;
	}
	move(x,y,dir,--k);
}
int main()
{
	int m,n;
	int i,j;
	char dir;
	
	scanf("%d %d",&n,&m);

	a=(int **)malloc(sizeof(int*) * m);
	a[0]=(int *)malloc(sizeof(int) * n * m);
	for(i=1;i<n;i++)
	{
		a[i]=a[i-1]+m;
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		scanf(" %d",&a[i][j]); 
		
	scanf(" %d %d %c %d", &x,&y,&dir,&k);	
	move(x,y,dir,k);	
//	printf("%c",Turn('U',0));
//	printf("%d %d %c %d",x,y,dir,k);
	return 0;
 } 
 
