#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 101

int max[MAX][MAX];
int R,C;

int process(int x,int y,int** area)
{
	int longest=0;
	if (max[x][y]>0) 
		return max[x][y];
	if (x-1>=0&&area[x-1][y]<area[x][y]) 
	{
		int temp;
		temp=process(x-1,y,area);
		longest=(longest>temp) ? longest : temp;
	}
	if (x+1<R&&area[x+1][y]<area[x][y]) 
	{
		int temp=process(x+1,y,area);
		longest=(longest>temp) ? longest : temp;
	}
	if (y-1>=0&&area[x][y-1]<area[x][y]) 
	{
		int temp=process(x,y-1,area);
		longest=(longest>temp) ? longest : temp;
	}
	if (y+1<C&&area[x][y+1]<area[x][y]) 
	{
		int temp=process(x,y+1,area);
		longest=(longest>temp) ? longest : temp;
	}
	return max[x][y]=longest+1;
}

int main (int argc, const char * argv[]) {
	int** area;
	int i,j;
	int longest;
	while (scanf("%d %d",&R,&C)!=EOF) 
	{
		longest=0;

		for (i=0; i<MAX; i++) 
		{
			memset(max[i],0,sizeof(max[i]));
		}
		area=(int**)malloc(sizeof(int*)*R);
		for (i=0; i<R; i++) 
		{
			area[i]=(int*)malloc(sizeof(int)*C);
			for (j=0; j<C; j++) 
			{
				scanf("%d",&area[i][j]);
			}
		}
		
		for (i=0; i<R; i++) 
		{
			for (j=0; j<C; j++) 
			{
				process(i,j,area);
			}
		}
		
		for (i=0; i<R; i++) 
		{
			for (j=0; j<C; j++) 
			{
				int temp=max[i][j];
				if (temp>longest) {
					longest=temp;
				}
			}
		}

		printf("%d\n",longest);
		
	}
    return 0;
}
