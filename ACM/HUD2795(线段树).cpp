#include <iostream>
#include<cstdio>
#define SIZE 222222
int num[SIZE<<2],w,h;
int max(int a,int b){return a>b?a:b;}
void pushUp(int ind){num[ind]=max(num[ind<<1], num[ind<<1|1]);}
void build(int l,int r,int ind)
{
	num[ind]=w;
	if(l==r)return;
	int m=(l+r)>>1;
	build(l,m,ind<<1);
	build(m+1,r,ind<<1|1);
	pushUp(ind);
}
int query(int L,int R,int l,int r,int ind)
{
	if(L<=l&&r<=R)return num[ind];
	int ret=0,m=(l+r)>>1;
	if(L<=m)ret=max(ret,query(L,R,l,m,ind<<1));
	if(R>m)ret=max(ret,query(L,R,m+1,r,ind<<1|1));
	return ret;
}
int insert(int len,int l,int r,int ind)
{
	//printf("len=%d,l=%d,r=%d\n",len,l,r);
	if(l==r)
	{
		num[ind]-=len;
		return l;
	}
	int ret=0,m=(l+r)>>1;
	if(query(l, m, 1, h, 1)>=len)
		ret=insert(len,l,m,ind<<1);
	else
		ret=insert(len,m+1,r,ind<<1|1);
	pushUp(ind);
	return ret;
}

int main () {
	int n;
	while (~scanf("%d%d%d",&h,&w,&n)) {
		if(h>n)h=n;
		build(1, h, 1);
		//insert(2, 1, h, 1);
		
		while (n--) {
			int tmp;
			scanf("%d",&tmp);
			if(num[1]<tmp)printf("-1\n");
			else printf("%d\n",insert(tmp, 1, h, 1));
		}
	}
    return 0;
}
