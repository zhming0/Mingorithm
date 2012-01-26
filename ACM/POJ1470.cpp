#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
#define SIZE 1024
using namespace std;
vector<int> son[SIZE];
map<int,int> mp;
int memory[SIZE][SIZE];
int fa[SIZE],depth[SIZE];
void dfs(int now,int level){
	depth[now]=level;
	for (int i=0; i<son[now].size(); i++) 
		dfs(son[now][i],level+1);
}
int lca(int u,int v)
{
	int tmpu=u,tmpv=v;
	if(memory[tmpu][tmpv]!=-1)return memory[tmpu][tmpv];
	if (depth[u]>depth[v]) swap(u, v);
	while (depth[u]<depth[v]) 
	{
		v=fa[v];
		if(memory[u][v]!=-1) return memory[u][v];
	}
	while (u!=v) {
		if(fa[u]!=-1)u=fa[u];
		if(fa[v]!=-1)v=fa[v];
		if(memory[u][v]!=-1) return memory[u][v];
	}
	memory[tmpu][tmpv]=memory[tmpv][tmpu]=u;
	return u;
}
int main (int argc, char * const argv[]) {
	//freopen("backup.txt", "r", stdin);
	int n,m,i;
	while (scanf("%d",&n)!=EOF) {
		for(i=0;i<SIZE;i++)son[i].clear();
		mp.clear();
		memset(fa, -1, sizeof(fa));
		memset(memory, -1, sizeof(memory));
		for (i=0; i<n; i++) {
			int father,sum,tmp;
			scanf("%d",&father);
			scanf("%*[^(](%d)",&sum);
			for (int j=0; j<sum; j++) {
				scanf("%d",&tmp);
				son[father].push_back(tmp);
				fa[tmp]=father;
			}
		}
		for (i=1; i<=n; i++) 
			if(fa[i]==-1)
				break;
		dfs(i, 0);
		scanf("%d",&m);
		while (m--) {
			int u,v;
			scanf("%*[^(](%d %d)",&u,&v);
			int res=lca(u, v);
			mp[res]++;
		}
		for (i=1; i<=n; i++) 
			if(mp[i])
				printf("%d:%d\n",i,mp[i]);
	}
    return 0;
}
