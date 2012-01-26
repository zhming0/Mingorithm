#include <iostream>
#include<cstring>
#include<cstdio>
#define MIN -1000000000
using namespace std;
int dp[10010][110];
int left_hurt[10010][110];
int bird_hp[10010],ber_hp[100010];
int n,m,k;
static int kill(int hp, int from, int left, int& target)
{
    //printf("hp=%d  from=%d  left=%d\n",hp,from,left);
    int ret=0;
    bool old=false;
    target=0;
    if (left>hp) {
        target=left-hp;
        return 0;
    }
    if (left>0) {
        old=true;
        hp-=left;
        ret++;
        from++;
    }
    if (hp==0) return ret;
    for (int i=from; i<k; i++) {
        if (hp>=ber_hp[i]) {
            hp-=ber_hp[i];
            ret++;
            old=true;
            if(hp==0) {target=0;return ret;}
        }else{
            if (!old) 
                target=ber_hp[i]-hp;
            break;
        }   
    }
    return ret;
}
int main (int argc, const char * argv[])
{
    //freopen("/Users/M/Desktop/backup.txt", "r", stdin);
    while (~scanf("%d %d %d",&n, &m, &k)&&(n||m||k)) {
        for (int i=1; i<=n; i++) scanf("%d",&bird_hp[i]);
        for (int i=0; i<k; i++) scanf("%d",&ber_hp[i]);
        for(int i=1;i<=m; i++) dp[0][i]=MIN;
        dp[0][0]=0;
        left_hurt[0][0]=0;
        for (int i=1; i<=n; i++) 
        {
            dp[i][0]=dp[i-1][0]+kill(bird_hp[i], dp[i-1][0], left_hurt[i-1][0], left_hurt[i][0]);
            for (int j=1; j<=m; j++) 
            {
                if(dp[i-1][j-1]!=MIN && dp[i-1][j]!=MIN)
                {
                    int left1,left2;
                    int k1=kill(bird_hp[i], dp[i-1][j], 
                                left_hurt[i-1][j], left1);
                    int k2=kill(2*bird_hp[i], dp[i-1][j-1], 
                                left_hurt[i-1][j-1], left2);
                    if (dp[i-1][j]+k1>dp[i-1][j-1]+k2||
                        (dp[i-1][j]+k1==dp[i-1][j-1]+k2 && left1>left2)) {
                        dp[i][j]=dp[i-1][j]+k1;
                        left_hurt[i][j]=left1;
                    }else{
                        dp[i][j]=dp[i-1][j-1]+k2;
                        left_hurt[i][j]=left2;
                    }
                }else if(dp[i-1][j-1]==MIN){
                    dp[i][j]=MIN;
                    left_hurt[i][j]=0;
                }else{
                    dp[i][j]=dp[i-1][j-1]+kill(2*bird_hp[i], dp[i-1][j-1], left_hurt[i-1][j-1], left_hurt[i][j]);
                }
            }
        }
        int ret=0;
        for (int i=0; i<=m; i++) 
            ret=max(dp[n][i], ret);
        printf("%d\n", ret);
    }
    return 0;
}
/*
 10 0 20
 8 9 8 7 5 7 5 5 0 2 
 3 0 2 1 7 1 5 5 7 0 6 1 5 6 7 3 1 0 5 8 
 
 10 1 0
 6 0 0 7 7 7 1 7 6 7
 
 2 3 2
 9 2
 12 9
 
 3 3 2
 9 2 2
 12 9
 
 3 3 2
 9 2 3
 12 9
 
 3 3 3
 9 2 2
 12 9 1
 
 0 0 0
 */
