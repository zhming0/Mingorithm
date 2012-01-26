#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
struct edge{
    int to, last;
}e[1100];
int cnt, head[110];
int n, m, k;
int cor[110], visited[110];
static void addEdge(int from, int to)
{
    e[cnt].to=to;
    e[cnt].last=head[from];
    head[from]=cnt++;
}
static bool findPath(int from)
{
    for (int i=head[from]; i!=-1; i=e[i].last) {
        if(visited[e[i].to]) continue;
        visited[e[i].to]=1;
        if (!cor[e[i].to] || findPath(cor[e[i].to])) {
            cor[e[i].to]=from;
            return true;
        }
    }
    return false;
}
int main (int argc, const char * argv[])
{
    while (scanf("%d", &n) && n) {
        cnt=0;
        scanf("%d %d",&m, &k);
        memset(head, -1, sizeof(head));
        memset(cor, 0, sizeof(cor));
        while (k--) {
            int from, to, tmp;
            scanf("%d %d %d", &tmp, &from, &to);
            if (from!=0 && to!=0) 
                addEdge(from, to);
        }
        int ans=0;
        for (int i=1; i<n; i++) {
            memset(visited, 0, sizeof(visited));
            if (findPath(i)) 
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

