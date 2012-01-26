#include <iostream>
#include<cstring>
using namespace std;
bool vst[201];
int grid[201][201],queue[201],tail,head;
int n,m,pre[201];
bool bfs(){
	memset(vst, false, sizeof(vst));tail=head=0;
	queue[tail++]=1;
	while (tail>head) {
		int j=queue[head++];
		for (int i=1; i<=m; i++) 
			if(!vst[i]&&grid[j][i]>0)
			{
				pre[i]=j;
				vst[i]=true;
				if(i==m)return true;
				queue[tail++]=i;
			}
	}
	return false;
}
int findMax()
{
	int res=0;
	while (bfs()) {
		int Min=0x7fffffff;
		for (int i=m; i!=1; i=pre[i]) 
			Min=min(Min,grid[pre[i]][i]);
		res+=Min;
		for (int i=m; i!=1; i=pre[i]) {
			grid[pre[i]][i]-=Min;
			grid[i][pre[i]]+=Min;
		}
	}
	return res;
}
int main (int argc, char * const argv[]) {
	//freopen("backup.txt", "r", stdin);
	int i,a,b,temp;
	while (cin>>n>>m) {
		memset(grid, 0, sizeof(grid));
		for (i=0; i<n; i++) {
			cin>>a>>b>>temp;
			grid[a][b]+=temp;
			//grid[b][a]-=temp;
		}
		cout << findMax()<<endl;
	}
    return 0;
}
