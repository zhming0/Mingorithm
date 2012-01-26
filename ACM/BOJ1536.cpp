#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int a,int b){
	return (a>b)?b:a;
}
int main (int argc, const char * argv[]) {
	int cases,i,j;
	scanf("%d",&cases);
	while (cases--) {
		int n,nextLeft,nextRight;
		int ini;
		int inf=1<<30;
		int addr[60];
		int maxTime[60];
		int dp[60][60][2];//0->right 1->left
		scanf("%d",&n);
		for (i=0; i<n; i++) 
			scanf("%d",&addr[i]);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&maxTime[i]);
		scanf("%d",&ini);
		addr[n]=ini;
		maxTime[n]=0;
		for (i=0; i<=n; i++) 
			for (j=i+1; j<=n; j++) 
				if (addr[i]>addr[j]) {
					int t=addr[i];
					addr[i]=addr[j];addr[j]=t;
					t=maxTime[i];
					maxTime[i]=maxTime[j];maxTime[j]=t;
				}
		for (i=0; i<=n; i++) 
			if (maxTime[i]==0&&addr[i]==ini) 
				ini=i;
		for (i=0; i<60; i++) 
			for (j=0; j<60; j++) {
				dp[i][j][0]=inf;
				dp[i][j][1]=inf;
			}
		dp[ini][ini][0]=0;
		dp[ini][ini][1]=0;
		for (i=ini; i>=0; i--) 
			for (j=ini; j<=n; j++) {
				if (i<ini) {
					nextLeft=addr[i+1]-addr[i]+dp[i+1][j][1];
					if (maxTime[i]>=nextLeft) 
						dp[i][j][1]=min(dp[i][j][1], nextLeft);
					nextLeft=addr[j]-addr[i]+dp[i+1][j][0];
					if (maxTime[i]>=nextLeft) 
						dp[i][j][1]=min(dp[i][j][1], nextLeft);
				}
				if (j>ini) {
					nextRight=addr[j]-addr[j-1]+dp[i][j-1][0];
					if (maxTime[j]>=nextRight) 
						dp[i][j][0]=min(dp[i][j][0], nextRight);
					nextRight=addr[j]-addr[i]+dp[i][j-1][1];
					if (maxTime[j]>=nextRight) 
						dp[i][j][0]=min(dp[i][j][0], nextRight);
				}
			}
		int ans=min(dp[0][n][0], dp[0][n][1]);
		if(ans!=inf)
			printf("%d\n",ans);
		else
			printf("%d\n",-1);
	}
    return 0;
}
