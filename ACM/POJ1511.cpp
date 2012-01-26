#include <iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=1e9,L=1000001;
struct node{
	int to,cost,last;
}edge[2][L];
queue<int> que;
int head[2][L],dist[2][L],n;
bool flag[2][L];
long long ans;
int min(int a,int b){return a>b?b:a;}
void spfa(int mode)
{
	while (!que.empty()) que.pop();
	que.push(1);
	while (!que.empty()) 
	{
		int current=que.front();
		que.pop();
		flag[mode][current]=false;
		int i=head[mode][current];
		while (i!=-1)
		{
			int to=edge[mode][i].to;
			int cost=edge[mode][i].cost;
			if(dist[mode][to]>(dist[mode][current]+cost))
			{
				dist[mode][to]=dist[mode][current]+cost;
				if(!flag[mode][to])
				{
					que.push(to);
					flag[mode][to]=true;
				}
			}
			i=edge[mode][i].last;
		}
	}
	for (int i=1; i<=n; i++) ans+=dist[mode][i];
		//printf("dist[%d][%d]=%d\n",mode,i,dist[mode][i]);
}
int main (int argc, char * const argv[]) {
	int cases,q,i,j,f,t,c;
	scanf("%d",&cases);
	while (cases--) 
	{
		ans=0;
		scanf("%d %d",&n,&q);
		for (i=0; i<2; i++) 
			for (j=1; j<=n; j++) 
			{
				head[i][j]=-1;
				flag[i][j]=false;
				dist[i][j]=MAX;
			}
		dist[0][1]=0;dist[1][1]=0;
		for(i=0;i<q;i++)
		{
			scanf("%d %d %d",&f,&t,&c);
			edge[0][i].last=head[0][f];
			edge[0][i].cost=c;
			edge[0][i].to=t;
			head[0][f]=i;
			
			edge[1][i].last=head[1][t];
			edge[1][i].to=f;
			edge[1][i].cost=c;
			head[1][t]=i;
		}
		spfa(0);
		spfa(1);
		cout << ans<<endl;
	}
    return 0;
}
