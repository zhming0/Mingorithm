#include <iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int grid[27][27],n;
int deg[27],queue[27],head,tail;
int DAG()
{
	bool isOk=true;
	head=0,tail=0;
	int i,j;
	int deg_tmp[27];
	memcpy(deg_tmp, deg, sizeof(deg_tmp));
	while (1)
	{
		int count=0;
		for (i=0; i<n; i++) 
			if(deg_tmp[i]==0)
			{
				deg_tmp[i]=-1;
				count++;
			}
		if(count==0)return -1;//circle
		if(count>1) isOk=false;//return 0;// ambiguous
		for (i=0; i<n; i++) 
		{
			if (deg_tmp[i]!=-1)continue;
			deg_tmp[i]=-2;
			queue[tail++]=i;
			for (j=0; j<n; j++) 
				if (grid[i][j]==1)
					deg_tmp[j]--;
			//break;
		}
		if (tail==n&&isOk)
			return 1;
		else if(tail==n&&!isOk)
			return 0;
	}
	return 0;
}
int main (int argc, char * const argv[]) {
	//freopen("a.txt", "r", stdin);
	int m,i;
	bool isConsistent,isClear;
	string s;
	while (cin>>n>>m) {
		if(n==0&&m==0)break;
		int ans=0;
		isConsistent=true;
		isClear=false;
		memset(grid, 0, sizeof(grid));
		memset(deg, 0, sizeof(deg));
		for (i=0; i<m; i++) {
			cin>>s;
			if (!isConsistent||isClear) continue;
			grid[s[0]-'A'][s[2]-'A']=1;
			deg[s[2]-'A']++;
			if (grid[s[2]-'A'][s[0]-'A']==1) 
			{
				ans=i+1;
				isConsistent=false;
			}
			if (!isConsistent||isClear) continue;
			int temp=DAG();
			//printf("temp=%d\n",temp);
			if (temp==-1) {
				isConsistent=false;
				ans=i+1;
			}
			else if(temp==0)
				continue;
			else
			{
				isClear=true;
				ans=i+1;
			}
		}
		//cout << DAG()<<endl;
		if (isClear) {
			printf("Sorted sequence determined after %d relations: ",ans);
			while (tail>head) 
				printf("%c",'A'+queue[head++]);
			printf(".\n");
		}else if (!isConsistent) 
			printf("Inconsistency found after %d relations.\n",ans);
		else 
			printf("Sorted sequence cannot be determined.\n");
	}
    return 0;
}
