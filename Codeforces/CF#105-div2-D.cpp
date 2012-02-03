#include <iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
double dp[1010][1010];
int main(int argc, char *argv[]) {
	int w, b;
	cin >> w >> b;
	memset(dp, 0, sizeof(dp));
	if (w+b==0) {
		printf("0.0\n");
		return 0;
	}
	dp[b][w] = 1.0*w/(w+b);
	for (int i = b-2; i>=0; i--) {
		for (int j = w; j>=0; j--) 
		{
			if (i+j==0) 
				break;
			if (i+3<=b && j>0) {
				dp[i][j] += dp[i+3][j] * double(i+3)/double(j) * double(i+2) * double(i+1)/double(i+2+j)/double(i+1+j);
			}
			if (j+1<=w) {
				dp[i][j] += dp[i+2][j+1] * double(i+2)/double(j+1) * double(i+1) * double(j+1)/double(i+j+2)/double(i+1+j);
			}
			dp[i][j] *= double(j)/double(i+j);
		}
	}
	double ret = 0;
	for (int i=0; i<=b; i++) {
		for (int j=0; j<=w; j++) {
			ret += dp[i][j];
		}
	}
	printf("%.9lf", ret);
	return 0;
}