#include <iostream>
#include<cstring>
#include<queue>
using namespace std;
bool grid[2][100][100];
int n;
queue<int> q;
bool reach(int a,int b,int mode)
{
	if(a==b)return false;
	bool used[100];
	int i;
	memset(used, false, sizeof(used));
	while(!q.empty())q.pop();
	q.push(a);
	used[a]=true;
	while (!q.empty()) 
	{
		int now=q.front();
		q.pop();
		if(now==b)return true;
		for (i=1; i<=n; i++) 
			if(!used[i]&&grid[mode][now][i])
			{
				used[i]=true;
				q.push(i);
			}
	}
	return false;
}
int main (int argc, char * const argv[]) {
	int cases,m,i,j,k,ans;
	cin>>cases;
	while (cases--) {
		ans=0;
		memset(grid, false, sizeof(grid));
		cin>>n>>m;
		k=(n+1)/2;
		for (i=0; i<m; i++) {
			int a,b;
			cin>>a>>b;
			grid[0][a][b]=true;
			grid[1][b][a]=true;
		}
		for (i=1; i<=n; i++) 
		{
			int num1=0,num2=0;
			for (j=1; j<=n; j++) 
			{
				if(reach(i,j,0))
					num1++;
				if(reach(i,j,1))
					num2++;
			}
			if(num1>(k-1)||num2>(k-1))
				ans++;
		}
		cout << ans<<endl;
	}
	
    return 0;
}
