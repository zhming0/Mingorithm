#include<stdio.h>
#include<string.h>

int n;
int cost[20][3];
int dp[20][3];

int min(int a,int b)
{
	return a<b? a:b;
}

int main (int argc, char * const argv[]) 
{
	int cases;
	int i,j;
	scanf("%d",&cases);
	while (cases--) 
	{
		scanf("%d",&n);
		for (i=0; i<n; i++) 
			scanf("%d %d %d",&cost[i][0],&cost[i][1],&cost[i][2]);
		
		//memset(dp, 0, sizeof(dp));
		dp[0][0]=0;
		dp[0][1]=0;
		dp[0][2]=0;
		
		for (i=1; i<=n; i++) 
		{
			for (j=0; j<3;j++)
			{
				dp[i][j]=min(dp[i-1][(j+2)%3]+cost[i-1][j],dp[i-1][(j+4)%3]+cost[i-1][j]);
			}
		}
		int min=dp[n][2];
		for (i=0; i<3; i++) {
			min=min<dp[n][i]? min:dp[n][i];
		}
		printf("%d\n",min);
	}
    return 0;
}
