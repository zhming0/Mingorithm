//SPFA!!
#include<cstring>
#include<cstdio>
#include <iostream>
#include<queue>
using namespace std;
struct edge{
    int to, w, last;
}e[100100];
int head[100100], cnt;
bool inqueue[100100];
int dist[100100];
int n, from, to;
static void addEdge(int from, int to, int weight){
    e[cnt].to=to;
    e[cnt].w=weight;
    e[cnt].last=head[from];
    head[from]=cnt++;
}
static void spfa() 
{
	queue<int> que;
	que.push(from);
    dist[from] = 0;
	while (!que.empty()) 
	{
		int current=que.front();
		que.pop();
		inqueue[current]=false;
		for(int i=head[current]; i!=-1; i=e[i].last){
			if(dist[e[i].to] > dist[current]+e[i].w)
			{
				dist[e[i].to] = dist[current]+e[i].w;
				if(!inqueue[e[i].to]){
					que.push(e[i].to);
					inqueue[e[i].to]=true;
				}
			}
		}
	}
}
int main (int argc, const char * argv[])
{
    while (~scanf("%d",&n)) {
        cnt=0;
        memset(head, -1, sizeof(head));
        memset(inqueue, false, sizeof(inqueue));
        for(int i=0; i<n; i++) dist[i] = 0x7fffffff;
        while (~scanf("%d %d", &from, &to) && (from || to)) {
            int w;
            scanf("%d", &w);
            addEdge(from, to, w);
        }
        scanf("%d %d",&from, &to);
        spfa();
        if(dist[to] == 0x7fffffff) printf("-1\n");
        else printf("%d\n", dist[to]);
    }
    return 0;
}

