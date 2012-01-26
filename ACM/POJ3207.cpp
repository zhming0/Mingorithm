#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Edge {
	int to,last;
}edge[200000];
int low[1100],dfn[1100],e[510][2],head[1100],cnt,ind;
void insert(int f,int t)
{edge[cnt].to=t;edge[cnt].last=head[f];head[f]=cnt++;}
void tarjan(int now)
{
	dfn[now]=low[now]=++ind;
	for (int i=head[now]; i!=-1; i=edge[i].last) 
	{
		if(!dfn[edge[i].to])
			tarjan(edge[i].to);
		low[now]=min(low[now], low[edge[i].to]);
	}
}
int main (int argc, char * const argv[]) {
	int n,m,i,j;
	while (scanf("%d %d",&n,&m)!=EOF) {
		bool ans=true;
		memset(dfn, 0, sizeof(dfn));
		memset(head, -1, sizeof(head));
		for (i=0; i<m; i++) 
		{
			scanf("%d %d",&e[i][0],&e[i][1]);
			if(e[i][0]>e[i][1])swap(e[i][0], e[i][1]);
		}
		cnt=0;
		for (i=0; i<m; i++) 
			for (j=i+1; j<m; j++) 
				if((e[i][0]>e[j][0]&&e[i][0]<e[j][1]&&e[i][1]>e[j][1])||
				   (e[i][0]<e[j][0]&&e[i][1]>e[j][0]&&e[i][1]<e[j][1]))
				{
					insert(i, j+m);
					insert(j, i+m);
					insert(i+m, j);
					insert(j+m, i);
				}
		ind=0;
		for(i=0;i<2*m;i++)
			if(!dfn[i])
				tarjan(i);
		for (i=0; i<m; i++) 
			if(low[i]==low[i+m])
				ans=false;
		if(ans)
			printf("panda is telling the truth...\n");
		else
			printf("the evil panda is lying again\n");
		
	}
    return 0;
}
