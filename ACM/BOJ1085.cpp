#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
int dp[60][100000];
int w[60][60], c[60][60];
const int MAX = 100000000;
int main (int argc, const char * argv[])
{
    int n, m, d;
    while (~scanf("%d %d %d", &n, &m, &d)) {
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) 
                scanf("%d",&c[i][j]);
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) 
                scanf("%d",&w[i][j]);
        
        for(int i=1; i <= d ; i++)
            dp[0][i]=MAX;
        dp[0][0]=0;
        
        for (int i=1; i<=n; i++) {
            for (int j=0; j<=d; j++) 
            {
                dp[i][j]=MAX;
                for (int k=0; k<m; k++) {
                    if (j-c[i-1][k]<0) 
                        continue;
                    dp[i][j]=min(dp[i][j], dp[i-1][j-c[i-1][k]]+w[i-1][k]);
                }
            }
        }
        int ans = MAX;
        for (int j=0; j<=d; j++) 
            ans=min(ans, dp[n][j]);
        printf("%d\n", ans);
    }
    return 0;
}

