#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int SIZE=111111;
struct Node{
	ll sum[9];
	int cnt,col;
	bool flag;
};
Node node[SIZE<<2];
void pushUp(int rt){
	for (int i=0; i<9; i++) 
		node[rt].sum[i]=node[rt<<1].sum[i]+node[rt<<1|1].sum[i];
}
void pushDown(int rt)
{
	if (node[rt].col) {
		node[rt<<1].cnt+=node[rt].col;
		node[rt<<1].col+=node[rt].col;
		node[rt<<1|1].cnt+=node[rt].col;
		node[rt<<1|1].col+=node[rt].col;	
		node[rt].col=0;
	}
	node[rt].flag=false;
}
void build(int l,int r,int rt)
{
	node[rt].cnt=node[rt].col=0;
	node[rt].flag=true;
	if(l==r)
	{
		scanf("%I64d",&node[rt].sum[0]);
		//cin>>node[rt].sum[0];
		for (int i=1; i<9; i++) 
			node[rt].sum[i]=(ll)sqrt((double)node[rt].sum[i-1]);
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushUp(rt);
}
void update(int L,int R,int l,int r,int rt)
{
	if (L<=l&&r<=R) {
		node[rt].cnt++;
		node[rt].col++;
		return;
	}
	pushDown(rt);
	int m=(l+r)>>1;
	if(L<=m)update(L,R,l,m,rt<<1);
	if(R>m)update(L,R,m+1,r,rt<<1|1);
}
ll query(int L,int R,int l,int r,int rt)
{
	ll ret=0;
	if (L<=l&&R>=r) {
		if(node[rt].cnt>8)node[rt].cnt=8;
		if (node[rt].cnt==8||l==r||node[rt].flag) 
			return node[rt].sum[node[rt].cnt];
		pushDown(rt);
		int m=(l+r)>>1;
		return query(L,R,l,m,rt<<1)+query(L,R,m+1,r,rt<<1|1);
	}
	pushDown(rt);
	int m=(l+r)>>1;
	if (L<=m) ret+=query(L,R,l,m,rt<<1);
	if (R>m) ret+=query(L,R,m+1,r,rt<<1|1);
	return ret;
}
int main (int argc, char * const argv[]) {
	int n,m,T=0;
	while (~scanf("%d",&n)) {
		build(1, n, 1);
		scanf("%d",&m);
		printf("Case #%d:\n",++T);
		while (m--) {
			int t,l,r;
			scanf("%d%d%d",&t,&l,&r);
			if (l>r) swap(l, r);
			if (t==0) 
				update(l, r, 1, n, 1);
			else
			{
				printf("%I64d\n",query(l, r, 1, n, 1));
				//cout << query(l, r, 1, n, 1)<<endl;
			}
		}
		printf("\n");
	}
    return 0;
}
