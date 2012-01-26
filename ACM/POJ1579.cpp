#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc, const char * argv[]) {
	int a,b,c;
	int i,j,k;
	int dp[21][21][21];
	while (scanf("%d %d %d",&a,&b,&c)) {
		if (a==-1&&b==-1&&c==-1)
			break;
		if (a<=0||b<=0||c<=0) {
			printf("w(%d, %d, %d) = %d\n",a,b,c,1);
			continue;
		}
		for (i=0; i<21; i++) 
			for (j=0; j<21; j++)
				for (k=0; k<21; k++) {
					if (k==0||i==0||j==0) {
						dp[i][j][k]=1;
						continue;
					}
					if (i<j&&j<k) 
						dp[i][j][k]=dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k];
					else 
						dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j][k-1]+dp[i-1][j-1][k]-dp[i-1][j-1][k-1];
					//printf("dp[%d][%d][%d]=%d\n",i,j,k,dp[i][j][k]);
				}
		if (a>20||b>20||c>20) {
			printf("w(%d, %d, %d) = %d\n",a,b,c,dp[20][20][20]);
		}else {
			printf("w(%d, %d, %d) = %d\n",a,b,c,dp[a][b][c]);
		}
	}
    return 0;
}
