#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define SIZE 1000
using namespace std;
struct Box{
	int w, l, h;
}box[600];
struct edge {
	int to,next;
}e[SIZE * SIZE];
int head[SIZE], cnt, pre[SIZE];
bool vst[SIZE];
void addEdge(int from,int to)
{
	e[cnt].to=to;
	e[cnt].next=head[from];
	head[from]=cnt++;
}
bool findPath(int from)
{
	for (int i=head[from]; i!=-1; i=e[i].next) {
		if (vst[e[i].to]) continue;
		vst[e[i].to] = true;
		if (pre[e[i].to]==0 || findPath(pre[e[i].to])) {
			pre[e[i].to] = from;
			return true;
		}
	}
	return false;
}
int main () {
	int n;
	while (~scanf("%d", &n) && n) {
		memset(head, -1, sizeof(head));
		memset(pre, 0, sizeof(pre));
		cnt=0;
		for (int i=1; i<=n; i++) 
			scanf("%d %d %d", &box[i].w, &box[i].l, &box[i].h);
		for (int i=1; i<=n; i++) 
			for (int j = 1 ; j<=n; j++) 
				if (box[i].l < box[j].l && box[i].w < box[j].w && box[i].h < box[j].h) 
					addEdge(i, j);
		int ret = 0;
		for (int i=1; i<=n; i++)
		{
			memset(vst, false, sizeof(vst));
			if (findPath(i))
				ret++;
		}
		printf("%d\n", n-ret);
	}
    return 0;
}
// Dinic alogorithm 