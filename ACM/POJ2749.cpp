#include <iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#define SIZE 2000
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
struct Edge {
	int to,last;
}e[1000000];
int len[SIZE][2];
int low[SIZE],dfn[SIZE],head[SIZE],s[2][2],cnt;
int f[SIZE][2],h[SIZE][2],n,a,b,dis;
int sta[SIZE],head_s;
bool instack[SIZE];
void insert(int f,int t)
{e[cnt].to=t;e[cnt].last=head[f];head[f]=cnt++;}
int belong[SIZE],cntnum;
void tarjan(int now)
{
	dfn[now]=low[now]=++cnt;
	instack[now]=true;sta[head_s++]=now;
	for (int i=head[now]; i!=-1; i=e[i].last) {
		if(!dfn[e[i].to])
		{
			tarjan(e[i].to);
			low[now]=min(low[e[i].to], low[now]);
		}else if(instack[e[i].to])
			low[now]=min(low[now], dfn[e[i].to]);
	}
	if(dfn[now]==low[now])
	{
		int tmp;
		do {
			tmp=sta[--head_s];
			instack[tmp]=false;
			belong[tmp]=cntnum;
		} while (tmp!=now);
		cntnum++;
	}
}
bool check(int key)
{
	cnt=0;head_s=0;int i,j;
	memset(dfn, 0, sizeof(dfn));
	memset(head, -1, sizeof(head));
	for (i=0; i<a; i++) {
		insert(h[i][0], h[i][1]+n);insert(h[i][0]+n, h[i][1]);
		insert(h[i][1], h[i][0]+n);insert(h[i][1]+n, h[i][0]);
	}
	for (i=0; i<b; i++) {
		insert(f[i][0], f[i][1]);insert(f[i][0]+n, f[i][1]+n);
		insert(f[i][1], f[i][0]);insert(f[i][1]+n, f[i][0]+n);
	}
	for (i=1; i<=n; i++) 
		for (j=i+1; j<=n; j++) 
		{
			if(len[i][0]+len[j][0]>key)insert(i, j+n),insert(j, i+n);
			if(len[i][1]+len[j][1]>key)insert(i+n, j),insert(j+n, i);
			if(dis+len[i][0]+len[j][1]>key) insert(i, j),insert(j+n, i+n);
			if(dis+len[i][1]+len[j][0]>key) insert(i+n, j+n),insert(j, i);
			
		}
	cnt=0;cntnum=0;
	for (i=1; i<=n+n; i++) if(!dfn[i])tarjan(i);
	for (i=1; i<=n; i++) 
		if(belong[i]==belong[i+n])
			return false;
	return true;
}
int main () {
	int i,Min,Max;
	scanf("%d %d %d",&n,&a,&b);
	Min=0x7fffffff;Max=-1;
	scanf("%d %d %d %d",&s[0][0],&s[0][1],&s[1][0],&s[1][1]);
	dis=abs(s[0][0]-s[1][0])+abs(s[0][1]-s[1][1]);
	for (i=1; i<=n; i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		len[i][0]=abs(x-s[0][0])+abs(y-s[0][1]);
		len[i][1]=abs(x-s[1][0])+abs(y-s[1][1]);
		Min=min(Min,min(len[i][0],len[i][1]));
		Max=max(Max,max(len[i][0],len[i][1]));
	}
	for (i=0; i<a; i++) scanf("%d %d",&h[i][0],&h[i][1]);
	for (i=0; i<b; i++) scanf("%d %d",&f[i][0],&f[i][1]);
	int l=2*Min;int r=2*Max+dis;
	int ans=0x7fffffff;
	while (l<=r) {
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;if(mid<ans)ans=mid;
		}else
			l=mid+1;
	}
	if(ans==0x7fffffff)
		printf("-1\n");
	else
		printf("%d\n",ans);
    return 0;
}
