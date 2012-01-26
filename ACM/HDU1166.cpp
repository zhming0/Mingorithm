#include <iostream>
#define SIZE 300000
int sum[SIZE];
void build(int l,int r,int id)
{
	if(l==r)
	{
		scanf("%d",&sum[id]);
		return;
	}
	int m=(l+r)>>1;
	build(l,m,id<<1);
	build(m+1,r,id<<1|1);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}
void update(int p, int add, int l, int r, int id)
{
	if (l==r) {
		sum[id]+= add;
		return;
	}
	int m = (l+r)>>1;
	if(p<=m)update(p,add,l,m,id<<1);
	else update(p,add,m+1,r,id<<1|1);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}
int query(int L, int R, int l, int r, int rt)
{
	if(L<=l&&R>=r)return sum[rt];
	int m=(l+r)>>1;
	int ret=0;
	if(L<=m)ret+=query(L, R, l, m, rt<<1);
	if(R>m) ret+=query(L, R, m+1, r, rt<<1|1);
	return ret;
}
int main (int argc, char * const argv[]) {
	int cases,T=0,n,a,b;
	scanf("%d",&cases);
	while (cases--) {
		printf("Case %d:\n",++T);
		scanf("%d",&n);
		build(1, n, 1);
		char op[10];
		while (scanf("%s",op)) {
			if(op[0]=='E')break;
			scanf("%d %d", &a, &b);
			if(op[0]=='Q')printf("%d\n",query(a, b, 1, n, 1));
			else if(op[0]=='S')update(a, -b, 1, n, 1);
			else update(a, b, 1, n, 1);
		}
	}
    return 0;
}
