#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int len[65], n, sum, length, cnt;
bool vst[65];
bool cmp(const int& a, const int& b)
{
    return b < a;
}
bool dfs(int leftlen, int now, int complete)
{
    if (leftlen==0) {
        //Important optimization (+2)
        if (complete + 2 == cnt) return true;
        for (now=0; vst[now]; now++)
            ;
        //Important optimization
        vst[now] = true;
        if (dfs(length - len[now], now + 1, complete + 1))
            return true;
        vst[now] = false;
    }else {
        if (now == n ) return false;
        for (int i = now; i < n; i++)
        {
            if (vst[i] || len[i] > leftlen) continue;
            if (len[i] == len[i-1] && !vst[i-1]) continue;
            vst[i] = true;
            if(dfs(leftlen - len[i], i + 1, complete))
                return true;
            vst[i] = false;
        }
    }
    return false;
}
int main() {
    while(~scanf("%d", &n) && n)
    {
        sum = 0;
        memset(vst, false, sizeof(vst));
        bool flag = false;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &len[i]);
            sum += len[i];
        }
        sort(len, len+n, cmp);
        for (int i=len[0]; i<=sum/2; i++)
        {
            if (sum%i) continue;
            cnt = sum / i;
            length = i;
            vst[0] = true;
            if (dfs(length - len[0], 1, 0))
            {
                flag = true;
                printf("%d\n", length);
                break;
            }
            vst[0] = false;
        }
        if (!flag)
            printf("%d\n", sum);
    }
    return 0;
}

