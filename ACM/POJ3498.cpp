#include <iostream>
#include<cstring>
#include<cstdio>
#define INF 0x7fffffff
#define SIZE 400000
#define src 201
using namespace std;
struct edge {
	int to,cap,last;
}e[SIZE];
struct Point {
	float x,y;
}p[211];
int n,head[211],cnt,que[10000],front,tail,pre[211];
int temp_cap[SIZE];
float d;
bool visited[211];
//float fabs(float a){return a>0?a:-a;}
void addEdge(int from,int to,int cap)
{
	e[cnt].to=to;e[cnt].cap=cap;
	e[cnt].last=head[from];head[from]=cnt++;
}
bool findRoad(int des)
{
	memset(visited, false, sizeof(visited));
	front=tail=0;
	que[tail++]=src;visited[src]=true;
	while (tail>front) {
		int now=que[front++];
		for (int i=head[now]; i!=-1; i=e[i].last) 
			if(!visited[e[i].to]&&e[i].cap>0)
			{
				pre[e[i].to]=now;
				if(e[i].to==des)
					return true;
				visited[e[i].to]=true;
				que[tail++]=e[i].to;
			}
	}
	return false;
}
int maxflow(int des)
{
	int ans=0,min=0x7fffffff;
	while (findRoad(des)) {
		for (int i=des; i!=src; i=pre[i]) 
			for (int j=head[pre[i]]; j!=-1; j=e[j].last) 
				if(e[j].to==i)
				{
					min=min<e[j].cap?min:e[j].cap;
					//if(e[j].cap==0)printf("From %d to %d, shit happened\n",pre[i],i);
					break;
				}
		ans+=min;
		//printf("min=%d\n",min);
		for (int i=des; i!=src; i=pre[i]) 
			for (int j=head[pre[i]]; j!=-1; j=e[j].last) 
				if(e[j].to==i)
				{
					e[j].cap-=min;
					e[j^1].cap+=min;
					break;
				}
	}
	return ans;
}
int main (int argc, char * const argv[]) {
	//freopen("a.txt", "r", stdin);
	int cases;
	cin>>cases;
	while (cases--) {
		//printf("new Case\n");
		cin>>n>>d;
		int tot=0;
		int ans[201],head_ans=0;
		cnt=0;
		memset(head, -1, sizeof(head));
		for (int i=0; i<n; i++) {
			int num,cp;
			cin>>p[i].x>>p[i].y>>num>>cp;
			addEdge(i, i+100, cp);
			addEdge(i+100, i, 0);
			if(num>0){
				addEdge(src, i, num);
				addEdge(i, src, 0);
				tot+=num;
			}
		}
		for (int i=0; i<n; i++) 
			for (int j=i+1; j<n; j++) 
			{
				if(((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y))-(d*d)>0)
					continue;
				addEdge(i+100, j, INF);
				addEdge(j, i+100, 0);
				addEdge(j+100, i, INF);
				addEdge(i, j+100, 0);
			}
		for (int j=0; j<cnt; j++) 
			temp_cap[j]=e[j].cap;
		for (int i=0; i<n; i++)
		{
			if (tot-maxflow(i)==0&&tot!=0)
				ans[head_ans++]=i;
			for (int j=0; j<cnt; j++) 
				e[j].cap=temp_cap[j];
		}
		for (int i=0; i<head_ans; i++) {
			printf("%d",ans[i]);
			if(i!=head_ans-1)
				printf(" ");
		}
		if(head_ans==0)
			printf("-1");
		printf("\n");
	}
    return 0;
}
