#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
	int x,y;
}p[1010];
int n,r;
int Y[1010],cnt;
void findY(int from)
{
	cnt=0;
	for (int i=from; p[i].x-p[from].x<=r&&i<n; i++) 
		Y[cnt++]=p[i].y;
	sort(Y, Y+cnt);
}
int findMax()
{
	int ans=-1;
	for (int i=0; i<cnt; i++) {
		int temp=upper_bound(Y, Y+cnt, r+Y[i])-Y-i;
		ans=ans>temp?ans:temp;
	}
	return ans;
}
bool cmp(point a,point b)
{
	return a.x<b.x;
}
int main (int argc, char * const argv[]) {
	while (~scanf("%d %d",&n,&r)) {
		for (int i=0; i<n; i++) 
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p, p+n,cmp);
		int ret=0;
		for (int i=0; i<n; i++) {
			findY(i);
			int temp=findMax();
			//printf("temp=%d\n",temp);
			ret=ret>temp?ret:temp;
		}
		printf("%d\n",ret);
	}
    return 0;
}
