#include <iostream>
#include<cstdio>
#include<cstring>
struct edge{
	int to,next;
}e[6001];
int con[6001],head[6001],cnt;
int dp[6001][2];
bool isroot[6001];
int max(int a,int b)
{
	return a>b?a:b;
}
void addEdge(int from, int to)
{
	e[cnt].to=to;e[cnt].next=head[from];head[from]=cnt++;
}
void tree_dp(int num)
{
	dp[num][0]=0;
	dp[num][1]=con[num];
	for (int i=head[num]; i!=-1; i=e[i].next) {
		tree_dp(e[i].to);
		dp[num][0]+=(dp[e[i].to][1]>dp[e[i].to][0]?dp[e[i].to][1]:dp[e[i].to][0]);
		dp[num][1]+=dp[e[i].to][0];
	}
}
int main (int argc, char * const argv[]) {
	int n;
	while (~scanf("%d",&n)) {
		int root=0;
		memset(head, -1, sizeof(head));
		memset(isroot, true, sizeof(isroot));
		cnt=0;
		for (int i=1; i<=n; i++) scanf("%d",&con[i]);
		for (int i=0; i<n; i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			if (a==0&&b==0)break;
			isroot[a]=false;
			addEdge(b, a);
		}
		for (int i=1; i<=n; i++) 
			if (isroot[i]) {
				root=i;
				break;
			}
		tree_dp(root);
		printf("%d\n",max(dp[root][0],dp[root][1]));
	}
    return 0;
}
