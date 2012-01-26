#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Edge{
	int to,last;
}edge[2001];
int head[1001],cnt,low[1001],dfn[1001],num_low[1001];
int min(int a,int b){return a>b?b:a;}
void tarjan(int now,int from)
{
	dfn[now]=low[now]=++cnt;bool flag=false;
	for (int i=head[now]; i!=-1; i=edge[i].last) {
		if(edge[i].to==from&&!flag){flag=true;continue;}
		if(!dfn[edge[i].to])tarjan(edge[i].to,now);
		low[now]=min(low[edge[i].to],low[now]);
	}
}
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int n,r,i,j;
	while (scanf("%d %d",&n,&r)!=EOF) {
		cnt=0;
		memset(head, -1, sizeof(head));
		memset(dfn, 0, sizeof(dfn));
		memset(num_low, 0, sizeof(num_low));
		while (r--) //from 1
		{
			int f,t;
			scanf("%d %d",&f,&t);
			edge[cnt].to=t;
			edge[cnt].last=head[f];
			head[f]=cnt;cnt++;
			edge[cnt].to=f;
			edge[cnt].last=head[t];
			head[t]=cnt;cnt++;
		}
		cnt=0;
		for(i=1;i<=n;i++)if(!dfn[i])tarjan(i,-1);
		for (i=1; i<=n; i++) 
			for(j=head[i];j!=-1;j=edge[j].last)
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
