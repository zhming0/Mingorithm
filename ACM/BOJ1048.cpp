#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int r[210][210];
int dp[210];
int main (int argc, char * const argv[]) {
	int n;
	while (~scanf("%d",&n)) {
		for (int i=1; i<=n; i++) 
			for (int j=i+1; j<=n; j++) {
				scanf("%d", &r[i][j]);
				r[j][i]=r[i][j];
			}
		dp[1]=1;
		for (int i=2; i<=n; i++) {
			dp[i]=r[1][i];
			for (int j=1; j<i; j++) 
				dp[i]=min(dp[i], dp[j]+r[j][i]);
		}
		printf("%d\n",dp[n]);
	}
    return 0;
}
