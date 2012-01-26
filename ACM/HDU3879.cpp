#include <iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define INF 0x7fffffff
#define SIZE 60001
struct Edge {
	int to,last,cap;
}e[10000000];
int src,des;
int n,m;
int head[SIZE],cnt,que[SIZE],front,tail,dist[SIZE],temp_head[SIZE];
void addEdge(int from,int to,int cap)
{
	e[cnt].to=to;e[cnt].cap=cap;e[cnt].last=head[from];head[from]=cnt++;
	e[cnt].to=from;e[cnt].cap=0;e[cnt].last=head[to];head[to]=cnt++;
}
int min(int a,int b){return a>b?b:a;}
int bfs()
{
	memset(dist, -1, sizeof(dist));
	front=tail=0;que[tail++]=src;
	dist[src]=0;
	while (tail>front) {
		int now=que[front++];
		for (int i=head[now]; i != -1; i=e[i].last) 
		{
			if(dist[e[i].to]<0&&e[i].cap>0)
			{
				que[tail++]=e[i].to;
				dist[e[i].to]=dist[now]+1;
			}
		}
	}
	return dist[des]>=0;
}
int dfs(int now,int exp)
{
	if(now==des)return exp;
	for (int& i=temp_head[now]; i!=-1; i=e[i].last) {
		int temp;
		if(e[i].cap>0&&dist[e[i].to]==dist[now]+1&&(temp=dfs(e[i].to,min(exp, e[i].cap)))>0)
		{
			e[i].cap-=temp;
			e[i^1].cap+=temp;
			return temp;
		}
	}
	return 0;
}
int maxflow()
{
	int res=0;
	while (bfs()) {
		for (int i=0; i<des+1; i++) temp_head[i]=head[i];
        while (1) {
            int delta = dfs(src, INF);
            if (delta == 0) break;
            res += delta;
        }
	}
	return res;
}

int main (int argc, char * const argv[]) {
	//freopen("0.in", "r", stdin);
	//freopen("a.txt", "r", stdin);
	while (scanf("%d%d",&n,&m)!=EOF) {
		memset(head, -1, sizeof(head));
		cnt=0;src=n+m;des=n+m+1;
		int ans=0;
		for (int i=0; i<n; i++) {
			int temp;
			scanf("%d",&temp);
			addEdge(src, i, temp);
		}
		for (int i=0; i<m; i++) {
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			a--,b--;
			addEdge(a, n+i, INF);
			addEdge(b, n+i, INF);
			addEdge(n+i, des, c);
			ans+=c;
		}
		//printf("Hey man~\n");
		printf("%d\n",ans-maxflow());
	}
    return 0;
}
