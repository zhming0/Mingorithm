#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b)
{return a>b?a:b;}
int main (int argc, const char * argv[]) {
	freopen("a.txt", "r", stdin);
	int n,i,j;
	int dp[5010];
	int p[5010];
	int num[5010];
	while (scanf("%d",&n)!=EOF) {
		if (n==0) {
			printf("0 0\n");
			continue;
		}
		memset(num,0,sizeof(num));
		int longest=1;
		int ans=0;
		for (i=0; i<n; i++) 
			scanf("%d",&p[i]);
		dp[0]=1;
		num[0]=1;
		for (i=1; i<n; i++) {
			dp[i]=1;
			num[i]=0;
			for (j=0; j<i; j++)
			{
				if (p[i]<p[j]) 
					dp[i]=max(dp[i],dp[j]+1);
			}
			longest=max(longest, dp[i]);
			for (j=i-1; j>=0; j--) {
				if (p[i]<p[j]&&dp[i]==dp[j]+1) {
					num[i]+=num[j];
				}
			}
			if (num[i]==0) {
				num[i]=1;
			}
			printf("p[%d]=%d,num[%d]=%d,dp[%d]=%d\n",i,p[i],i,num[i],i,dp[i]);
		}
		for (i=0; i<n; i++) {
			if (dp[i]==longest) {
				ans+=num[i];
			}
		}
		printf("%d %d\n",longest,ans);
	}
    return 0;
}
