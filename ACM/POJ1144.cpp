#include <iostream>
#include<sstream>
#include<cstring>
using namespace std;
struct Edge{
	int to,last;
}edge[20010];
int head[110],low[110],dfn[110],cnt,root_son;
bool isTarget[110];
int min(int a,int b){return a>b?b:a;}
void addEdge(int f,int t)
{
	edge[cnt].last=head[f],edge[cnt].to=t,head[f]=cnt++;
}
void tarjan(int now)
{
	dfn[now]=low[now]=++cnt;
	for(int i=head[now];i!=-1;i=edge[i].last){
		if(!dfn[edge[i].to])
		{
			tarjan(edge[i].to);
			low[now]=min(low[now], low[edge[i].to]);
			if(now!=1&&dfn[now]<=low[edge[i].to])
				isTarget[now]=true;//?
			else if(now==1)
				root_son++;
		}else
			low[now]=min(low[now], dfn[edge[i].to]);
	}
}
int main (int argc, char * const argv[]) {
	int n,i,j,f,t;
	string tmp;
	//freopen("b.txt", "r", stdin);
	while (cin>>n) {
		if(n==0)break;
		memset(dfn, 0, sizeof(dfn));
		memset(head, -1, sizeof(head));
		memset(isTarget, false, sizeof(isTarget));
		cnt=0;
		getline(cin,tmp);
		while (1) {
			getline(cin,tmp);
			if(tmp[0]=='0')break;
			istringstream in(tmp);
			in>>f;
			while (in>>t) addEdge(f, t),addEdge(t, f);
		}
		cnt=0;root_son=0;
		//for(i=1; i<=n; i++) if(!dfn[i])tarjan(i, -1);
		//cout << cnt<<endl;
		tarjan(1);
		cnt=0;
		for(i=1;i<=n;i++)
			if(isTarget[i])
				cnt++;
		cnt+=(root_son>1);
		cout << cnt<<endl;
	}
    return 0;
}
