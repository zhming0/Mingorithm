#include <iostream>
#include<string.h>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main (int argc, char * const argv[]) {
    int cases,i,j,n,maxsum;
	int num[51],sum,dp[51];
	cin>>cases;
	while (cases--) {
		cin>>n;
		sum=0;
		maxsum=0;
		memset(num, 0, sizeof(num));
		memset(dp, 0, sizeof(dp));
		for (i=0; i<n; i++)
		{
			cin>>num[i];
			dp[i]=num[i];
			sum+=num[i];
		}
		maxsum=dp[0];
		for (i=1; i<n; i++) {
			for (j=0; j<i;j++) {
				if (num[i]>=num[j])
					dp[i]=max(dp[i], dp[j]+num[i]);
			}
			maxsum=max(maxsum,dp[i]);
		}
		cout << sum-maxsum<<endl;
	}
    return 0;
}
