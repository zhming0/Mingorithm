#include <iostream>
#include<cstdio>
#include<cstring>
#define MAX 200010
using namespace std;
struct Edge {
	int to,last;
}e[2*MAX];
int head[MAX],fa[MAX],level[MAX],dfn[MAX],low[MAX];
int ans,cnt;
bool isBridge[MAX];
int min(int a,int b)
{return a>b?b:a;}
void insert(int f,int t)
{e[cnt].last=head[f];e[cnt].to=t;head[f]=cnt++;}
void tarjan(int now,int from,int depth)
{
	low[now]=dfn[now]=++cnt;
	level[now]=depth;fa[now]=from;bool flag=false;
	for (int i=head[now]; i!=-1; i=e[i].last) {
		if(from==e[i].to&&!flag)flag=true;
		else if(!dfn[e[i].to])
		{
			tarjan(e[i].to,now,depth+1);
			low[now]=min(low[e[i].to], low[now]);
			if(dfn[now]<low[e[i].to])
			{
				isBridge[e[i].to]=true;
				ans++;
			}
		}
		else
			low[now]=min(low[now], dfn[e[i].to]);
	}
}
void lca(int u,int v)
{
	if(level[u]<level[v]){int tem=u;u=v;v=tem;}
	while (level[u]>level[v]) {
		if(isBridge[u])
		{
			isBridge[u]=false;
			ans--;
		}
		u=fa[u];
	}
	while (u!=v) {
		if (isBridge[u]) {
			isBridge[u]=false;
			ans--;
		}
		u=fa[u];
		if (isBridge[v]) {
			isBridge[v]=false;
			ans--;
		}
		v=fa[v];
	}
}
int main (int argc, char * const argv[]) {
	int n,m,q,i,f,t,cases=0;
	while (scanf("%d %d",&n,&m)!=EOF&&(n!=0||m!=0)) {
		memset(head, -1, sizeof(head));
		memset(isBridge, false, sizeof(isBridge));
		memset(dfn, 0, sizeof(dfn));
		cnt=0;ans=0;
		for (i=0; i<m; i++) {
			scanf("%d %d",&f,&t);
			insert(f,t);insert(t,f);
		}
		cnt=0;
		tarjan(1, -1, 0);
		scanf("%d",&q);
		printf("Case %d:\n",++cases);
		while(q--) {
			scanf("%d %d",&f,&t);
			lca(f, t);
			printf("%d\n",ans);
		}
		printf("\n");
	}
    return 0;
}
