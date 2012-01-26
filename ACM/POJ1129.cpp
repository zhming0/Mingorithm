#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 30

int grid[MAX][MAX];
int channel[MAX];
int n;

int dfs(int now)
{
	int i;
	int j;
	int flag;
	if (now==n) 
	{
		return 1;
	}
	for (i=0; i<4; i++) 
	{
		flag=1;
		for (j=0; j<n; j++) 
		{
			if (grid[j][now]==1&&channel[j]==i) 
			{
				flag=0;
				break;
			}
		}
		if (flag==0) {
			continue;
		}
		channel[now]=i;
		if (flag==1&&dfs(now+1)==1) 
		{
			return 1;
		}
		
	}
	return 0;
}

int main (int argc, const char * argv[]) {
	int i,j;
	while (scanf("%d",&n)) 
	{
		for (i=0; i<MAX; i++) 
		{
			memset(grid[i],0,sizeof(grid[i]));
		}
		memset(channel,-1,sizeof(channel));
		if (n==0) 
			break;
		for (i=0; i<n; i++) 
		{
			char letter;
			char temp;
			scanf("%c",&temp);
			scanf("%c",&letter);
			char array[30];
			array[0]=0;
			scanf("%s",array);
			for (j=1; array[j]!=0; j++)
			{
				//printf("%c %c\n",letter,array[j]);
				grid[letter-'A'][array[j]-'A']=1;
				//grid[array[j]-'A'][letter-'A']=1;
			}
		}
		dfs(0);
		int ans=0;
		int num[10];
		memset(num,0,sizeof(num));
		for (i=0; i<n; i++) 
		{
			num[channel[i]]=1;
		}
		for (i=0; i<4; i++) 
		{
			if (num[i]==1) 
			{
				ans++;
			}
		}
		if (ans==1) {
			printf("%d channel needed.\n",ans);
		}
		else {
			printf("%d channels needed.\n",ans);
		}

		
	}
    return 0;
}
