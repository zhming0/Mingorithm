#include <iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
bool used[2][10001];
vector<int> v[2][10001];
int circle,num_circle[10001],head_c;
int line,num_line[10001],head_l;
int m,n,counts=0;
int deg[2][10001];
int dfs(int mode,int node)
{
	counts++;
	used[mode][node]=true;
	if (deg[mode][node]==0) return 1;
	if(deg[mode][node]==1&&used[mode][v[mode][node][0]])return 1;
	if(deg[mode][node]==2&&used[mode][v[mode][node][0]]&&used[mode][v[mode][node][1]])
		return 2;
	int i,res;
	for (i=0; i<v[mode][node].size(); i++) 
		if (!used[mode][v[mode][node][i]]) 
			res=dfs(mode,v[mode][node][i]);
	return res;
}
int main (int argc, char * const argv[]) {
	int cases,i,j,T=1;
	scanf("%d",&cases);
	while (cases--) {
		bool flag=true;
		for (i=0; i<10001; i++) {
			v[0][i].clear();
			v[1][i].clear();
			deg[0][i]=0;deg[1][i]=0;
			used[0][i]=false;
			used[1][i]=false;
			line=0;
			circle=0;
			head_l=0;head_c=0;
		}
		scanf("%d %d",&n,&m);
		for (i=1; i<=m; i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			if(deg[0][a]<=1)
			{
				v[0][a].push_back(b);
				deg[0][a]++;
			}
			if(deg[0][b]<=1)
			{
				deg[0][b]++;
				v[0][b].push_back(a);
			}
		}
		scanf("%d %d",&n,&m);
		for (i=1; i<=m; i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			if(deg[1][a]<=1)
			{
				v[1][a].push_back(b);
				deg[1][a]++;
			}
			if(deg[1][b]<=1)
			{
				v[1][b].push_back(a);
				deg[1][b]++;
			}
		}
		for (i=1; i<=n; i++) {
			if(used[0][i])continue;
			counts=0;
			int tmp=dfs(0, i);
			if(tmp==1)
			{
				line++;
				num_line[head_l++]=counts;
			}else
			{
				circle++;
				num_circle[head_c++]=counts;
			}
		}
		for (i=1; i<=n; i++) {
			if(used[1][i])continue;
			counts=0;
			int tmp=dfs(1, i);
			if(tmp==1)
			{
				for (j=0; j<head_l; j++) 
					if(num_line[j]==counts)
						break;
				if(j!=head_l)
				{
					num_line[j]=-1;
					line--;
				}
			}else
			{
				for (j=0; j<head_c; j++) 
					if(num_circle[j]==counts)
						break;
				if(j!=head_c)
				{
					num_circle[j]=-1;
					circle--;
				}
			}
			if(!flag)break;
		}
		if(circle!=0||line!=0)flag=false;
		if(flag)
			printf("Case #%d: YES\n",T++);
		else
			printf("Case #%d: NO\n",T++);
	}
    return 0;
}
