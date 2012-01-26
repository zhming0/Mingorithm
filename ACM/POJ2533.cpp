#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MIN -1<<30
int max(int a,int b)
{
	return a>b?a:b;
}
int main (int argc, const char * argv[]) {
	int n,i,j;
	int a[1010],dp[1010];
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	while (scanf("%d",&n)!=EOF) {
		int ans=MIN;
		if (n==0) {
			printf("0\n");
			continue;
		}
		for (i=0; i<n; i++) 
			scanf("%d",&a[i]);
		dp[0]=1;
		ans=max(dp[0], ans);
		for (i=1; i<n; i++) {
			dp[i]=1;
			for (j=0;j<i; j++) {
				if (a[i]>a[j]) 
					dp[i]=max(dp[i], dp[j]+1);
			}
			//printf("dp[%d]=%d\n",i,dp[i]);
			ans=max(ans, dp[i]);
		}
		printf("%d\n",ans);
	}
    return 0;
}
