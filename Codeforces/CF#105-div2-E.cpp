#include <iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int dp[110][10010], max_demage[110][110], num[110], value[110];
int b[110], c[110];
int main(int argc, char *argv[]) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) {
		scanf("%d", &num[i]);
		b[0] = c[num[i]+1] = 0;
		for (int j=1; j<=num[i]; j++) {
			scanf("%d", &value[j]);
			b[j] = b[j-1] + value[j];
		}
		for (int j=num[i]; j; j--) 
			c[j] = c[j+1] + value[j];
		for (int j=1; j<=num[i]; j++) 
			for (int k=0; k<=j; k++) 
				max_demage[i][j] = max(max_demage[i][j], b[k] + c[num[i]-j+k+1]);
	}
	for (int i=1; i<=n; i++) 
		for (int j=0; j<=num[i]; j++) 
			for (int k=j; k<=m; k++) 
				dp[i][k] = max(dp[i-1][k-j]+max_demage[i][j], dp[i][k]);
	printf("%d\n", dp[n][m]);
	return 0;
}