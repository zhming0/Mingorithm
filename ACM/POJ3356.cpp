#include <iostream>
#include<string>
#include<string.h>
using namespace std;
int dp[1005][1005];
int min(int a, int b)
{return a>b?b:a;}
int main (int argc, char * const argv[]) {
	int l1,l2,i,j;
	string s1,s2;
	while (cin>>l1>>s1) {
		cin>>l2>>s2;
		memset(dp, 0, sizeof(dp));
		for (i=1; i<=l1; i++)
		{
			dp[i][0]=i;
			for (j=1; j<=l2; j++) {
				dp[0][j]=j;
				if(s1[i-1]==s2[j-1])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
				//cout << dp[i][j]<<endl;
			}
		}
		cout << dp[l1][l2]<<endl;
	}
    return 0;
}
