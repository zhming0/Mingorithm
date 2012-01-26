#include<cstring>
#include <iostream>
#include<cstdio>
using namespace std;
int dp[2050][2050];
int main (int argc, const char * argv[])
{
    string s1, s2;
    while(cin>>s1>>s2)
    {
        for (int i=0; i<=s1.length(); i++) dp[i][0] = i;
        for (int j=0; j<=s2.length(); j++) dp[0][j] = j;
        for (int i=1; i<=s1.length(); i++)
            for (int j=1; j<=s2.length(); j++) {
                dp[i][j] = 0x7fffffff;
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j-1]+1;
                dp[i][j] = min(dp[i][j], min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        printf("%d\n", dp[s1.length()][s2.length()]);
    }
    return 0;
}

