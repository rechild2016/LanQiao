#include <stdio.h>
#include <stdlib.h>
int n;
int **wall;

int Paint(int row ,int col)
{
	int temp=0;
	int i,sum=0;
	if( col<0 || col>=n)return 0;
	else if(wall[row][col]==1)return 0;
	 wall[row][col]=1;
	
	for(i=0;i<n;i++)
	{
		if(wall[0][i]==0 || wall[1][i]==0)break;
	}
	if(i==n)	return 1;
	
	if(row==1)
		temp= Paint(row-1,col-1)+Paint(row-1,col)+Paint(row-1,col+1)
			+Paint(row,col-1)+Paint(row,col+1);
	else if(row==0)
		temp= Paint(row+1,col-1)+Paint(row+1,col)+Paint(row+1,col+1)
			+Paint(row,col-1)+Paint(row,col+1);
			
	wall[row][col]=0;//¹éÁã 
	return temp%1000000007;
}

int main()
{
	

//	int (*wall)[2];
	int i,j;
	scanf("%d",&n);
	wall=(int **)malloc(sizeof(int *) * n);
	for(i=0;i<n;i++)
	wall[i]=(int *)malloc(2*sizeof(int));
	
//	wall=(int (*)[2])malloc(sizeof(int *) * n);
	for(i=0;i<n;i++)
	{
		wall[0][i]=0;
		wall[1][i]=0;
	}

		printf("%d  ",Paint(1,0));
		printf("\n");
	
	
	
	//ÊÍ·ÅÄÚ´æ	
	for(i=0;i<n;i++)		
	  {
	  	free(wall[i]);
	  	wall[i]=NULL;
	  }
	free(wall); 
	wall=NULL;
	return 0;
 } 
