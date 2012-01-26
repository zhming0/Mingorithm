#include <iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int grid[201][201];
int w[201],deg[201];
int main (int argc, char * const argv[]) {
	int cases,i,j,n,m;
	bool flag;
	scanf("%d",&cases);
	while (cases--) {
		int done=0;
		scanf("%d %d",&n,&m);
		flag=true;
		int max=n;
		memset(grid, 0, sizeof(grid));
		memset(deg, 0, sizeof(deg));
		memset(w, 0, sizeof(w));
		for (i=0; i<m; i++) 
		{
			int a,b;
			scanf("%d %d",&a,&b);
			if(grid[b][a]==1||a==b)
				flag=false;
			if(grid[a][b]!=1)
			{
				grid[a][b]=1;
				deg[a]++;
			}
		}
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		
		while(1)
		{
			bool haveunused=false;
			bool canCal=false;
			for (i=n; i>0; i--) {
				bool reset=false;
				if(w[i]==0)haveunused=true;
				if(deg[i]==0&&w[i]==0)
				{
					canCal=true;
					w[i]=max;
					done++;
					for (j=1; j<=n; j++) 
					{
						if(grid[j][i]==1)
						{
							deg[j]--;
							//grid[j][i]=0;
							reset=true;
						}
					}
					max--;
				}
				if(reset)break;
			}
			if(done==n)
				break;
			if(haveunused&&!canCal)
			{
				flag=false;
				break;
			}
			//printf("done=%d\n",done);
		}
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
		for (i=1; i<=n; i++) 
			printf("%d ",w[i]);
		printf("\n");
		//printf("deg[5]=%d,w[5]=%d\n",deg[5],w[5]);
	}
    return 0;
}
