#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b){return a>b?a:b;}
int main (int argc, const char * argv[]) {
	int n,p=1,i;
	int dp[50][2];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	dp[0][1]=1;
	for (i=1; i<=45; i++) {
		dp[i][0]=dp[i-1][1]+dp[i-1][0];
		dp[i][1]=dp[i-1][0];
	}
	scanf("%d",&n);
	while (scanf("%d",&i)!=EOF) {
		if(i==0)printf("Scenario #%d:\n%d\n\n",p++,0);
		else printf("Scenario #%d:\n%d\n\n",p++,dp[i-1][0]+dp[i-1][1]);
	}
    return 0;
}
