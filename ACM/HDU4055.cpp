#include<cstring>
#include <iostream>
#include<cstdio>
#define MOD 1000000007
using namespace std;
int dp[1010][1010];
int main (int argc, const char * argv[])
{
    string s;
    while (cin >> s) {
        int n=(int)s.length()+1;
        memset(dp, 0, sizeof(dp));
        dp[1][1]=1;
        for (int i=2; i<=n; i++) 
        {
            if(s[i-2]=='?')
            {
                int sum=0;
                for (int j=1; j<i; j++) 
                    sum=(sum+dp[i-1][j])% MOD;
                for (int j=1; j<=i; j++)
                    dp[i][j]=sum;
            }
            if (s[i-2]=='I') {
                dp[i][1]=0;
                for (int j=2; j<=i; j++) {
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])% MOD;
                }
            }
            if (s[i-2]=='D') {
                dp[i][i]=0;
                for (int j=i-1; j>=1; j--) 
                    dp[i][j]=(dp[i][j+1]+dp[i-1][j])% MOD;
            }
        }
        int ret=0;
        for (int i=1; i<=n; i++) 
            ret=(ret+dp[n][i])% MOD;
        printf("%d\n", ret);
    }
    return 0;
}

