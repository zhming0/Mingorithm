#include <iostream>
#include<cstring>
#include<cstdio>
struct node{
	int to,last;
}edge[10002];
int n,m;
int dfn[5002],low[5002],head[5002],head_edge=0;
int cnt,num,num_low[5002];
int min(int a,int b){return a>b?b:a;}
void dfs(int now,int from)
{
	dfn[now]=low[now]=++cnt;bool flag=false;
	for (int i=head[now]; i!=-1; i=edge[i].last) 
	{
		if(edge[i].to==from&&!flag){flag=true;continue;}
		if(!dfn[edge[i].to])dfs(edge[i].to,now);
		low[now]=min(low[now], low[edge[i].to]);
	}
}
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int i,j;
	while (scanf("%d %d",&n,&m)!=EOF) {
		memset(num_low, 0, sizeof(num_low));
		memset(dfn, 0, sizeof(dfn));
		memset(head, -1, sizeof(head));
		head_edge=0;num=0;cnt=0;
		for (i=0; i<m; i++) {
			int f,t;
			scanf("%d %d",&f,&t);
			edge[head_edge].last=head[f];
			edge[head_edge].to=t;
			head[f]=head_edge;
			head_edge++;
			
			edge[head_edge].last=head[t];
			edge[head_edge].to=f;
			head[t]=head_edge;
			head_edge++;
		}
		for (i=1; i<=n; i++) 
			if(!dfn[i])
				dfs(i,-1);
		//printf("cnt=%d\n",cnt);
		for (i=1; i<=n; i++) 
			for (j=head[i];j!=-1; j=edge[j].last) 
				if(low[i]!=low[edge[j].to])
					num_low[low[i]]++;
		int ans=0;
		for (i=1; i<=n; i++) 
			if(num_low[i]==1)
				ans++;
		printf("%d\n",(ans+1)/2);
	}
    return 0;
}
