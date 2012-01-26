// Dinic alogorithm 

#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define src 0
#define des 20001
#define INF 0x7fffffff
struct edge {
	int to,cap,next;
}e[200000<<3];
int head[20002],cnt;
int dist[20002],que[20002],front,tail,temp_head[20002];
void addEdge(int from,int to,int cap)
{
	e[cnt].to=to;e[cnt].cap=cap;
	e[cnt].next=head[from];head[from]=cnt++;
}
bool bfs_dinic()
{
	memset(dist, -1, sizeof(dist));
	front=tail=0;
	que[tail++]=src;dist[src]=0;
	while (tail>front) {
		int now=que[front++];
		for (int i=head[now]; i!=-1; i=e[i].next) 
			if (dist[e[i].to]<0&&e[i].cap>0)
			{
				dist[e[i].to]=dist[now]+1;
				que[tail++]=e[i].to;
			}
	}
	return (dist[des]>0);
}
int dfs_dinic(int now,int exp)
{
	if (now==des) return exp;
	int tmp,w=0;
	for (int i=head[now]; i!=-1&&w<exp; i=e[i].next) {
		if (e[i].cap>0&&dist[e[i].to]==dist[now]+1&&(tmp=dfs_dinic(e[i].to,min(exp-w, e[i].cap)))) {
			e[i].cap-=tmp;
			e[i^1].cap+=tmp;
			w+=tmp;
		}
	}
	if(!w)dist[now]=-1;
	return w;
}
int dinic()
{
	int ret=0,delta;
	while (bfs_dinic()) 
		while (delta=dfs_dinic(src,INF)) 
			ret+=delta;
	return ret;
}
int main (int argc, char * const argv[]) {
	int n,m,a,b,c;
	while (~scanf("%d%d",&n,&m)) {
		memset(head, -1, sizeof(head));
		cnt=0;
		for (int i=1; i<=n; i++) {
			scanf("%d%d",&a,&b);
			addEdge(src, i, a);
			addEdge(i, src, 0);
			addEdge(i, des, b);
			addEdge(des, i, 0);
		}
		for (int i=0; i<m; i++) {
			scanf("%d%d%d",&a,&b,&c);
			addEdge(a, b, c);
			addEdge(b, a, c);
		}
		printf("%d\n",dinic());
	}
    return 0;
}
// Dinic alogorithm 