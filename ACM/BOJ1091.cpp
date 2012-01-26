#include<cstring>
#include<cstdio>
#include <iostream>
using namespace std;
struct Edge{
    int to, last;
}e[100020];
int head[100020], cnt;
int n, d;
int que[100020], front, tail;
int ret=0;
static void addEdge(int from, int to){
    e[cnt].to=to;
    e[cnt].last=head[from];
    head[from]=cnt++;
}
static void bfs(int origin){
    front=tail=0;
    que[tail++]=origin;
    while (front<tail) {
        int num=0;
        int current=que[front++];
        for (int i=head[current]; i!=-1; i=e[i].last) {
            //visited[e[i].to]=1;
            que[tail++]=e[i].to;
            num++;
        }
        while (num>d) {
            ret+=num/d;
            num= (num/d) + (num%d==0 ? 0 : 1);
        }
    }
}
int main (int argc, const char * argv[])
{
    while (~scanf("%d %d", &n, &d)) {
        memset(head, -1, sizeof(head));
        cnt=ret=0;
        for (int i=1; i<=n; i++) {
            int tmp;
            scanf("%d",&tmp);
            addEdge(tmp, i);
        }
        bfs(0);
        printf("%d\n", ret);
    }
    return 0;
}

