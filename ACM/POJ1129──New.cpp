#include <iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int grid[26][26];
int color[26],num[4],n;
int dfs(int now)
{
	int i,j;
	bool flag;
	if(now==n)return 1;
	for (i=0; i<4; i++) {
		//if(now==3)printf("i=%d\n",i);
		flag=true;
		for (j=0; j<n; j++) 
			if(grid[now][j]==1&&color[j]==i)
			{
				flag=false;
				break;
			}
		if(!flag)continue;
		color[now]=i;
		if(dfs(now+1)==1)
			return 1;
	}
	return 0;
}
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int i,j;
	string s;
	while (cin>>n) {
		int ans=0;
		if(n==0)break;
		memset(grid, 0, sizeof(grid));
		for (i=0; i<n; i++) 
		{
			cin>>s;
			for (j=2; j<s.length(); j++)
			{
				grid[i][s[j]-'A']=1;
				grid[s[j]-'A'][i]=1;
			}
		}
		memset(num, 0, sizeof(num));
		memset(color, -1, sizeof(color));
		dfs(0);
		for (i=0; i<n; i++)
			num[color[i]]=1;
		for(i=0;i<4;i++)
			if(num[i]==1)
				ans++;
		if(ans==1)
			printf("%d channel needed.\n",ans);
		else
			printf("%d channels needed.\n",ans);
	}
    return 0;
}
