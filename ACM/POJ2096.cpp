#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
double dp[1010][1010];
int main (int argc, char * const argv[]) {
	double n,s;
	int i,j;
	while (cin>>n>>s) {
		dp[(int)s][(int)n]=0;
		for (i=s; i>=0; i--) {
			for (j=n; j>=0; j--) {
				if(i==s&&j==n)continue;
				dp[i][j]=dp[i+1][j]*(s-i)*j+
						 dp[i+1][j+1]*(s-i)*(n-j)+
						 dp[i][j+1]*i*(n-j);
				dp[i][j]+=n*s;
				dp[i][j]/=((n*s)-(i*j));
			}
		}
		printf("%.4f\n", dp[0][0]);
	}
    return 0;
}
