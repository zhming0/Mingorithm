#include <iostream>
#include<cstdio>
#include<queue>
#define size 500010
using namespace std;
int n,m,l;
queue<int> q;
int d[500010],step[500010];
bool check(int len)
{
	if(len>=l)return true;
	while(!q.empty())q.pop();
	int now=upper_bound(d, d+n+1, len)-d-1;
	q.push(now);step[now]=1;
	while (!q.empty()) {
		now=q.front();q.pop();
		if((l-d[now])>(len)*(m-step[now]))return false;
		if((l-d[now])<=len&&step[now]<m)return true;
		if(d[now+1]-d[now]>len)return false;
		/*for (int i=n; i>=0; i--)
			if(d[i]-d[now]<=len)
			{
				q.push(i);
				step[i]=step[now]+1;
				break;
			}*/
		int pos=upper_bound(d, d+n+1, d[now]+len)-d-1;
		step[pos]=step[now]+1;
		q.push(pos);
	}
	return false;
}
int main (int argc, char * const argv[]) {
	while (~scanf("%d%d%d",&l,&n,&m)) {
		int left=1,right=l;
		d[0]=0;
		for (int i=1; i<=n; i++) 
			scanf("%d",&d[i]);
		sort(d, d+n+1);
		while (left<=right) {
			int mid=(left+right)>>1;
			if(check(mid))right=mid-1;
			else left=mid+1;
		}
		printf("%d\n",right+1);
	}
    return 0;
}
