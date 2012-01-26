#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
#define MAX 200

using namespace std;

/*typedef struct person{
	vector<int> foe;
	int now;
}person;*/

vector<int> group;
int m,n;
int ans;
vector<int>::iterator it;
int grid[101][101];

void dfs(int num)
{
	ans=(group.size()>ans) ? group.size() : ans;
	if (num>n) 
		return;
	bool ok=true;
	for (int p=0; p<group.size(); p++) 
	{
		/*it=find(group.begin(), group.end(), man[num].foe[p]);
		if (it!=group.end()) 
		{
			ok=false;
			break;
		}*/
		if (grid[group[p]][num]) 
		{
			ok=false;
			break;
		}
		
	}
	if (ok) 
	{
		group.push_back(num);
		dfs(num+1);
		group.pop_back();
	}
	dfs(num+1);
}

int main (int argc, char * const argv[]) {

	int i,j;
	int p,q;
	ans=0;
	//bool ok=true;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(grid, 0, sizeof(grid));
		//person man[MAX];
		
		for (i=0; i<m; i++) 
		{
			scanf("%d %d",&p,&q);

			//man[p].foe.push_back(q);
			//man[q].foe.push_back(p);
			grid[p][q]=1;
			grid[q][p]=1;
		}
		
		/*for (i=1; i<=n; i++) 
		{
			group.push_back(i);
			for (j=1; j<=n; j++) 
			{
				if (j==i) 
					continue;
				for (p=0; p<man[j].foe.size(); p++) 
				{
					it=find(group.begin(), group.end(), man[j].foe[p]);
					if (it!=group.end()) 
					{
						ok=false;
						break;
					}
				}
				if (ok) 
					group.push_back(j);
				ok=true;
			}
			
			//printf("This time group.size()=%d\n",group.size());
			num=(group.size()>num) ? group.size() : num;
			group.clear();
			
			dfs(man, 1);
			
		}*/
		
		dfs( 1);
	
	
		printf("%d\n",ans);
		ans=0;
	}
	
    return 0;
}
