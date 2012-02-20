#include<iostream>
#include<cstdio>
using namespace std;
int r, c, tmp, dp[25][2010];
int main(int argc, char *argv[]) {
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		scanf("%d %d", &r, &c);
		for (int i=0; i<r; i++) 
			for (int j=0; j<c; j++)
				dp[i][j] = -0x7fffffff;
		dp[0][0] = 0;
		for (int i=0; i<r; i++) 
			for (int j=0; j<c; j++) {
				scanf("%d", &tmp);
				dp[i][j] += tmp;
				if (i+1<r) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				if (j+1<c) dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
				for (int k=2; k*(j+1)<=c; k++) 
					dp[i][k*(j+1)-1] = max(dp[i][k*(j+1)-1],dp[i][j]);
			}
		printf("%d\n", dp[r-1][c-1]);
	}
	return 0;
}