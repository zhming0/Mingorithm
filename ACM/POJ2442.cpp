#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
int ret[2010], col[2010];
priority_queue<int> que;

int main() {
    //freopen("/home/ming/Desktop/test.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        while (!que.empty())que.pop();
        scanf("%d %d", &m, &n);
        for (int i=0; i<n ;i++)
            scanf("%d", &ret[i]);
        sort(ret, ret+n);
        for (int i=1; i<m; i++)
        {
            for (int j=0; j<n; j++) scanf("%d", &col[j]);
            for (int j=0; j<n; j++)
                que.push(col[j] + ret[0]);
            for (int j=0; j<n; j++)
                for (int k=1; k<n; k++)
                {
                    if (ret[k] + col[j] >= que.top()) break;
                    que.pop();
                    que.push(ret[k]+col[j]);
                }
            for (int i=0; i<n; i++)
                ret[i] = que.top(), que.pop();
            sort(ret, ret+n);
        }
        for (int i=0; i<n-1; i++)
            printf("%d ", ret[i]);
        printf("%d\n", ret[n-1]);
    }
    return 0;
}
