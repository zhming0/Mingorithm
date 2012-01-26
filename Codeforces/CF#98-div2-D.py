#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
static int calc(const string& s){
    int ret = 0;
    for(int i=0; i<s.length(); i++)
        if (s[i]!=s[s.length()-1-i])
            ret++;
    return ret/2;
}
static string toPalin(string s)
{
    for(int i=0; i<s.length(); i++)
        if (s[i]!=s[s.length()-1-i])
            s[i] = s[s.length()-1-i];
    return s;
}

int cnt[510][510];
int dp[510][510];
int pre[510][510];

int main (int argc, const char * argv[])
{
    int n;
    string s;
    cin >> s >> n;
    for(int i=0; i<s.length(); i++)
        for (int j=i+1; j<=s.length(); j++)
            cnt[i][j] = calc(s.substr(i, j-i));
    dp[0][0] = 0;
    memset(pre, 0, sizeof(pre));
    for (int i=1; i<=n; i++) dp[0][i] = 100000000;
    for (int i=1; i<=s.length(); i++) dp[i][0]=100000000;
    for(int i=1; i<=s.length(); i++)
        for(int j=1; j<=n; j++){
            dp[i][j] = 0x7fffffff;
            for (int k = j-1; k<i; k++)
                if (dp[i][j] > dp[k][j-1]+cnt[k][i]) {
                    dp[i][j] = dp[k][j-1] + cnt[k][i];
                    pre[i][j] = k;
                }
        }
    int m = 1;
    for(int i=2; i<=n; i++)
        if (dp[s.length()][i] < dp[s.length()][m])
            m = i;
    printf("%d\n", dp[s.length()][m]);
    int i = (int)s.length(), j = m;
    while(--m) {
        s.insert(pre[i][j], "+");
        i = pre[i][j], j = j-1;
    }
    j = 0;
    for (i = 0; i<s.length(); i++){
        if(s[i] == '+') {
            cout << toPalin(s.substr(j, i-j)) << '+';
            j = i+1;
        }
    }
    cout << toPalin(s.substr(j)) << endl;
    return 0;
}

