#include <iostream>
#include<cstdio>
#define SIZE 111111
// 线段树成段更新
int sum[SIZE<<2],col[SIZE<<2];
void pushUp(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushDown(int rt,int num)
{
	if (col[rt]) {
		col[rt<<1]=col[rt<<1|1]=col[rt];
		sum[rt<<1]=(num-(num>>1))*col[rt];
		sum[rt<<1|1]=(num>>1)*col[rt];
		col[rt]=0;
	}
}
void build(int l,int r,int rt)
{
	sum[rt]=1;
	col[rt]=0;
	if(l==r)return;
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
	if(L<=l&&R>=r)
	{
		col[rt]=c;
		sum[rt]=(r-l+1)*c;
		return;
	}
	pushDown(rt, r-l+1);
	int m=(l+r)>>1;
	if(L<=m)update(L,R,c,l,m,rt<<1);
	if(R>m)update(L,R,c,m+1,r,rt<<1|1);
	pushUp(rt);
}
int main (int argc, char * const argv[]) {
	int cases,n,q,a,b,c;
	scanf("%d",&cases);
	for (int t=1; t<=cases; t++) {
		scanf("%d%d",&n,&q);
		build(1, n, 1);
		while (q--) {
			scanf("%d%d%d",&a,&b,&c);
			update(a, b, c, 1, n, 1);
			//printf("sum[1]=%d\n",sum[1]);
		}
		printf("Case %d: The total value of the hook is %d.\n",t,sum[1]);
	}
    return 0;
}
