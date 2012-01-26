#include <iostream>
#include<cstdio>
#define INF 0x7fffffff
struct edge{
	int to,next;
}e[500000];
int head[110],cnt,src,des,capa[500000],temp_capa[500000];
int n,m,que[110],pre[110],front,tail;
bool visited[110];
void addEdge(int from,int to,int cap)
{
	e[cnt].to=to;e[cnt].next=head[from];capa[cnt]=cap;head[from]=cnt++;
	e[cnt].to=from;e[cnt].next=head[to];capa[cnt]=0;head[to]=cnt++;	
}

bool bfs()
{
	memset(visited, false, sizeof(visited));
	front=tail=0;
	que[tail++]=src;visited[src]=true;
	while (tail>front) {
		int now=que[front++];
		for (int i=head[now]; i!=-1; i=e[i].next) {
			if(!visited[e[i].to]&&temp_capa[i]>0)
			{
				pre[e[i].to]=now;
				visited[e[i].to]=true;
				que[tail++]=e[i].to;
				if(e[i].to==des)return true;
			}
		}
	}
	return false;
}

int maxflow()
{
	int ret=0;
	//printf("Enter\n");
	while (bfs()) {
		int min=INF;
		//printf("src=%d,des=%d\n",src,des);
		for (int i=des; i!=src; i=pre[i]) 
		{
			//printf("%d->%d\n",pre[i],i);
			for (int j=head[pre[i]]; j!=-1; j=e[j].next) {
				if (e[j].to==i) {
					min=min<temp_capa[j]?min:temp_capa[j];
					break;
				}
			}
		}
		//printf("min=%d\n",min);
		if (min==INF) {
			return n;
		}
		ret+=min;
		//printf("ret=%d\n",ret);
		for (int i=des; i!=src; i=pre[i]) 
			for (int j=head[pre[i]]; j!=-1; j=e[j].next) 
				if (e[j].to==i) {
					temp_capa[j]-=min;
					temp_capa[j^1]+=min;
					break;
				}
	}
	return ret;
}

int main (int argc, char * const argv[]) {
	//freopen("backup.txt", "r", stdin);
	while (~scanf("%d%d",&n,&m)) {
		cnt=0;
		memset(head, -1, sizeof(head));
		for (int i=0; i<n; i++) 
			addEdge(i, i+n, 1);
		for (int i=0; i<m; i++) {
			int a,b;char tmp;
			while(scanf("%c",&tmp)&&tmp!='(');
			scanf("%d,%d)",&a,&b);
			addEdge(a+n, b, INF);
			addEdge(b+n, a, INF);
		}
		int ans=INF;
		for (int i=0; i<n; i++) 
			for (int j=i+1; j<n; j++) 
			{
				if(i==j)continue;
				src=i+n;
				des=j;
				for (int k=0; k<cnt; k++) 
					temp_capa[k]=capa[k];
				int tmp=maxflow();
				//printf("tmp=%d\n",tmp);
				//if(tmp==0)tmp=n;
				ans=ans<tmp?ans:tmp;
			}
		if(ans==INF)
			printf("%d\n",n);
		else
			printf("%d\n",ans);
	}
    return 0;
}
