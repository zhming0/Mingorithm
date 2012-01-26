#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
#define	src 801
#define INF 0x7fffffff
using namespace std;
struct edge{
	int to,cap,last;
}e[50000];
int head[810],n,d,m,cnt,pre[810],que[810];
int front,tail;
bool visited[810];
string grid[21];
void addEdge(int from,int to,int cap)
{
	e[cnt].to=to;e[cnt].cap=cap;
	e[cnt].last=head[from];head[from]=cnt++;
	//.....
	e[cnt].to=from;e[cnt].cap=0;
	e[cnt].last=head[to];head[to]=cnt++;
}
bool findRoad()
{
	front=tail=0;
	memset(visited, false, sizeof(visited));
	que[tail++]=src;
	visited[src]=true;
	pre[src]=-1;
	while (tail>front) {
		int now=que[front++];
		for (int i=head[now]; i!=-1; i=e[i].last) {
			if(!visited[e[i].to]&&e[i].cap>0)
			{
				pre[e[i].to]=now;
				if(e[i].to==0)return true;
				que[tail++]=e[i].to;
				visited[e[i].to]=true;
			}
		}
	}
	return false;
}
int maxflow()
{
	int ans=0;
	while (findRoad()) {
		ans+=1;
		for (int i=0; i!=src; i=pre[i]) 
			for (int j=head[pre[i]]; j!=-1; j=e[j].last) 
				if (e[j].to==i) 
				{
					e[j].cap-=1;
					e[j^1].cap+=1;
					break;
				}
	}
	return ans;
}
int main (int argc, char * const argv[]) {
	//freopen("a.txt", "r", stdin);
	//freopen("backup.txt", "r", stdin);
	int cases,T=0;
	cin>>cases;
	while (cases--) {
		cin>>n>>d;
		int tot=0;
		cnt=0;
		memset(pre, 0, sizeof(pre));
		memset(head, -1, sizeof(head));
		for (int i=0; i<n; i++) {
			cin>>grid[i];
			m=grid[i].length();
			for (int j=0; j<m; j++) 
			{
				addEdge(i*m+j+1,i*m+j+1+400,grid[i][j]-'0');
				if(i<d||j<d||(n-i-1)<d||(m-j-1)<d)
					addEdge(i*m+j+1+400, 0, INF);
				for (int p=-1; p<=1; p++) 
					for (int k=-1; k<=1; k++) {
						if(k==0&&p==0)continue;
						for (int q=1; q<=d; q++) 
						{
							int x=i+p*q;
							int y=j+k*q;
							if(abs(x-i)+abs(y-j)>d)continue;
							if(x<0||x>=n)continue;
							if(y<0||y>=m)continue;
							addEdge(i*m+j+1+400, x*m+y+1, INF);
						}
					}
			}
		}
		for (int i=0; i<n; i++) {
			cin>>grid[i];
			for (int j=0; j<m; j++) 
				if(grid[i][j]=='L')
				{
					tot++;
					addEdge(src, i*m+j+1, 1);
				}
		}
		int ans=tot-maxflow();
		if(ans==0)
			printf("Case #%d: no lizard was left behind.\n",++T,ans);
		else if(ans==1)
			printf("Case #%d: 1 lizard was left behind.\n",++T,ans);
		else 
			printf("Case #%d: %d lizards were left behind.\n",++T,ans);
	}
    return 0;
}
