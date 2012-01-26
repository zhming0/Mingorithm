#include <iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int mod[51][51];
bool used[51][51];
queue<int> q;
int countCastle(int x,int y)
{
	int ans=0;
	if(used[x][y])return -1;
	while(!q.empty())q.pop();
	q.push(x*100+y);
	used[x][y]=true;
	ans++;
	while (!q.empty()) 
	{
		int to=1;
		int now=q.front();
		q.pop();
		x=now/100;y=now%100;
		while (to<=8) 
		{
			if ((to&mod[x][y])<=0) 
			{
				if(to==1&&(y-1)>=0&&(4&mod[x][y-1])<=0&&!used[x][y-1])
				{
					//printf("Go left\n");
					ans++;
					q.push(x*100+y-1);
					used[x][y-1]=true;
				}
				if(to==4&&(y+1)<m&&(1&mod[x][y+1])<=0&&!used[x][y+1])
				{
					//printf("Go right\n");
					ans++;
					q.push(x*100+y+1);
					used[x][y+1]=true;
				}
				if(to==2&&(x-1)>=0&&(8&mod[x-1][y])<=0&&!used[x-1][y])
				{
					//printf("Go north\n");
					ans++;
					q.push((x-1)*100+y);
					used[x-1][y]=true;
				}
				if(to==8&&(x+1)<n&&(2&mod[x+1][y])<=0&&!used[x+1][y])
				{
					//printf("Go south\n");
					ans++;
					q.push((x+1)*100+y);
					used[x+1][y]=true;
				}
			}
			to*=2;
		}
	}
	return ans;
}
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int i,j,ans,biggist;
	while (cin>>n>>m) {
		ans=0;biggist=0;
		memset(mod, 0, sizeof(mod));
		memset(used, false, sizeof(used));
		for (i=0; i<n; i++) 
			for (j=0; j<m; j++) 
				cin>>mod[i][j];
		for (i=0; i<n; i++) 
			for (j=0; j<m; j++) 
			{
				int tmp=countCastle(i, j);
				//cout << tmp<<endl;
				if(tmp!=-1)
					ans++;
				biggist=biggist>tmp?biggist:tmp;
			}
		cout << ans<<endl;
		cout << biggist<<endl;
		//cout << countCastle(0, 0)<<endl;
	}
    return 0;
}
