#include <iostream>
#include<stdio.h>
#include<string>
#include<string.h>
int max(int a,int b)
{return a>b?a:b;}
using namespace std;
int dp[10010][2];
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int num[10010],n,cases=0,i,j;
	while (1) {
		memset(dp, 0, sizeof(dp));
		cases++;
		int temp;
		n=0;
		while (cin>>temp) {
			if(temp==-1)
				break;
			num[n++]=temp;
		}
		if(n==0)break;
		dp[0][0]=0;dp[0][1]=0;
		dp[1][0]=0;dp[1][1]=1;
		for (i=2; i<=n; i++) {
			for (j=1; j<i; j++) 
			{
				if(num[i-1]<=num[j-1])
					dp[i][1]=max(dp[i][1],dp[j][1]+1);
			}
			if(dp[i][1]<1)dp[i][1]=1;
			dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
		}
		int ans=max(dp[n][0], dp[n][1]);
		printf("Test #%d:\n",cases);
		printf("  maximum possible interceptions: %d\n",ans);
		printf("\n");
	}
    return 0;
}
