#include <iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAX=1000000001;
struct node{
	int to,length,last;
}edge[20002];
int n,m,head[2001];
bool flag[2001];
vector<int> done;
int main (int argc, char * const argv[]) {
	int i,j,h;
	while (scanf("%d %d",&n,&m)!=EOF) 
	{
		h=0;
		int ans=-1;
		for (i=0; i<=n; i++) 
		{
			head[i]=-1;
			flag[i]=false;
		}
		for (i=0; i<m; i++) {
			int from,to,cost;
			scanf("%d %d %d",&from,&to,&cost);
			edge[h].last=head[from];
			edge[h].to=to;
			edge[h].length=cost;
			head[from]=h;
			//printf("edge[1]=%d\n",edge[1].last);
			
			h++;
			
			edge[h].last=head[to];
			edge[h].to=from;
			edge[h].length=cost;
			head[to]=h;
			h++;
		}
		done.push_back(1);
		flag[1]=true;
		while (done.size()<n) 
		{
			int min=MAX;
			int target;
			for (i=0; i<done.size(); i++) 
			{
				j=head[done[i]];
				while (j!=-1) 
				{
					int to=edge[j].to;
					int cost=edge[j].length;
					if(!flag[to]&&min>cost)
					{
						target=to;
						min=cost;
					}
					j=edge[j].last;
				}
			}
			flag[target]=true;
			done.push_back(target);
			ans=ans>min?ans:min;
		}
		cout << ans<<endl;
	}
    return 0;
}
