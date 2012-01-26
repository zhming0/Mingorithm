#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define SIZE 111111
using namespace std;
int li[SIZE],ri[SIZE],ret;
int col[SIZE<<2];//延迟数组
bool isCount[SIZE<<2];
vector<int> v;
vector<int>::iterator it;
void PushDown(int rt)
{
	if (col[rt]!=-1) 
	{
		col[rt<<1]=col[rt<<1|1]=col[rt];
		col[rt]=-1;
	}
}
void update(int L,int R,int c,int l,int r,int rt)
{
	if (L<=l&&r<=R) {
		col[rt]=c;
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	if (L<=m) update(L,R,c,l,m,rt<<1);
	if (R>m) update(L,R,c,m+1,r,rt<<1|1);
}
void query(int l,int r,int rt)
{
	if(col[rt]!=-1)
	{
		if (!isCount[col[rt]]) 
			ret++;
		isCount[col[rt]]=true;
		return;
	}
	if(l==r)return;
	int m=(l+r)>>1;
	query(l,m,rt<<1);
	query(m+1,r,rt<<1|1);
}
int main (int argc, char * const argv[]) {
	int cases,n,m,a,b;
	scanf("%d",&cases);
	while (cases--) {
		scanf("%d",&n);
		ret=0;
		for (int i=0; i<n; i++) {
			scanf("%d%d",&a,&b);
			li[i]=a;ri[i]=b;
			v.push_back(a);v.push_back(b);
			v.push_back(b+1);
		}
		sort(v.begin(),v.end());
		it=unique(v.begin(), v.end());
		v.resize(it-v.begin());
		m=v.size();
		memset(col, -1, sizeof(col));
		for (int i=0; i<n; i++) {
			int l=upper_bound(v.begin(), v.end(), li[i])-1-v.begin();
			int r=upper_bound(v.begin(), v.end(), ri[i])-1-v.begin();
			update(l, r, i, 0, m, 1);
		}
		memset(isCount, false, sizeof(isCount));
		query(0, m, 1);
		printf("%d\n",ret);
	}
    return 0;
}
