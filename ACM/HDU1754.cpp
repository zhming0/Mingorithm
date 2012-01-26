#include <iostream>
#include<cstdio>
#define SIZE 222222
int MAX[SIZE<<2];
int max(int a,int b){return a>b?a:b;}
void pushUp(int ind){MAX[ind]=max(MAX[ind<<1], MAX[ind<<1|1]);}
void build(int l,int r,int ind)
{
	if(l==r){
		scanf("%d",&MAX[ind]);
		return;
	}
	int m=(l+r)>>1;
	build(l,m,ind<<1);
	build(m+1,r,ind<<1|1);
	pushUp(ind);
	//MAX[ind]=max(MAX[ind<<1], MAX[ind<<1|1]);
}
void update(int p,int score,int l,int r,int ind)
{
	if (l==r) {
		MAX[ind]=score;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m)update(p,score,l,m,ind<<1);
	else update(p,score,m+1,r,ind<<1|1);
	pushUp(ind);
	//MAX[ind]=max(MAX[ind<<1], MAX[ind<<1|1]);
}
int query(int L,int R,int l,int r,int ind)
{
	if(L<=l&&r<=R)return MAX[ind];
	int ret=0,m=(l+r)>>1;
	if(L<=m)ret=max(ret,query(L,R,l,m,ind<<1));
	if(R>m)ret=max(ret,query(L,R,m+1,r,ind<<1|1));
	return ret;
}

//典型线段树
int main () {
	int n,m;
	while (~scanf("%d%d",&n,&m)) {
		build(1, n, 1);
		while (m--) {
			char op[2];
			int a,b;
			scanf("%s%d%d",op,&a,&b);
			if(op[0]=='Q')printf("%d\n",query(a, b, 1, n, 1));
			else if(op[0]=='U')update(a, b, 1, n, 1);
		}
	}
    return 0;
}
