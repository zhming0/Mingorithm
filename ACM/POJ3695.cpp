#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Rect {
	int x1,x2,y1,y2,area;
};
int ans,query[20],q;
Rect rec[20];
bool isTouch(Rect* a,Rect* b)
{
	if(a->x1>=b->x2)return false;
	if(a->x2<=b->x1)return false;
	if(a->y1>=b->y2)return false;
	if(a->y2<=b->y1)return false;
	return true;
}
void dfs(Rect r,int now,int tag)
{
	Rect temp;
	if(now==q)return;
	for (int i=now; i<q; i++)
		if (isTouch(&r,&rec[query[i]])) 
		{
			temp.x1=r.x1>rec[query[i]].x1?r.x1:rec[query[i]].x1;
			temp.y1=r.y1>rec[query[i]].y1?r.y1:rec[query[i]].y1;
			temp.x2=r.x2<rec[query[i]].x2?r.x2:rec[query[i]].x2;
			temp.y2=r.y2<rec[query[i]].y2?r.y2:rec[query[i]].y2;
			temp.area=(temp.x2-temp.x1)*(temp.y2-temp.y1);
			if(tag%2)ans+=temp.area;
			else ans-=temp.area;
			dfs(temp,i+1,tag+1);
		}
}
int main (int argc, char * const argv[]) {
	int n,m,i,cases=0;
	while (scanf("%d %d",&n,&m)&&(n||m)) {
		for (i=0; i<n; i++) {
			scanf("%d %d %d %d",&rec[i].x1,&rec[i].y1,&rec[i].x2,&rec[i].y2);
			rec[i].area=(rec[i].x2-rec[i].x1)*(rec[i].y2-rec[i].y1);
		}
		int qry=0;
		printf("Case %d:\n",++cases);
		while (m--) 
		{
			ans=0;
			scanf("%d",&q);
			for (i=0; i<q; i++) 
			{
				scanf("%d",&query[i]);
				query[i]--;
				ans+=rec[query[i]].area;
			}
			for (i=0; i<q; i++) 
				dfs(rec[query[i]], i+1, 0);
			printf("Query %d: %d\n",++qry,ans);
		}
		putchar('\n');
	}
    return 0;
}
