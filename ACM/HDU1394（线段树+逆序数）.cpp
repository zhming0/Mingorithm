#include <iostream>
#include<cstdio>
int sum[50000];
int num[5000];
int min(int a,int b){return a>b?b:a;}
void build(int l,int r,int rt)
{
	//printf("rt=%d\n",rt);
	sum[rt]=0;
	if (l==r) return;
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
}
void update(int p,int l,int r, int rt)
{
	if (l==r){
		sum[rt]++;
		return;
	}
	int m=(l+r)>>1;
	if (p<=m) update(p,l,m,rt<<1);
	else update(p,m+1,r,rt<<1|1);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int L, int R, int l, int r, int rt)
{
	if(L<=l&&r<=R)
		return sum[rt];
	int ret=0,m=(l+r)>>1;
	if (L<=m) ret+=query(L, R, l, m, rt<<1);
	if (R>m) ret+=query(L, R, m+1, r, rt<<1|1);
	return ret;
}
int main (int argc, char * const argv[]) {
	int n;
	while (~scanf("%d",&n)) {
		build(0, n-1, 1);
		int tot=0;
		for (int i=0; i<n; i++) {
			scanf("%d",&num[i]);
			tot+=query(num[i], n-1, 0, n-1, 1);
			update(num[i], 0, n-1, 1);
		}
		int res=tot;
		for (int i=0; i<n; i++) {
			tot+=n-num[i]-1-num[i];
			res=min(res, tot);
		}
		printf("%d\n",res);
	}
    return 0;
}
