#include<cstdio>
#include<cstring>
#define SIZE 65535
const int maxn = 131072;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

int XOR[SIZE<<3],cover[SIZE<<3];
bool hash[SIZE<<1];
void FXOR(int rt)
{
	if (cover[rt]!=-1) cover[rt]^=1;
	else XOR[rt]^=1;
}
void PushDown(int rt)
{
	if (cover[rt]!=-1) {
		cover[rt<<1]=cover[rt<<1|1]=cover[rt];
		XOR[rt<<1]=XOR[rt<<1|1]=0;
		cover[rt]=-1;   //???
	}
	if (XOR[rt]) {
		FXOR(rt<<1);
		FXOR(rt<<1|1);
		XOR[rt]=0;
	}
}
void update(char op,int L,int R,int l,int r,int rt)
{
	if (L<=l&&r<=R) {
		if (op=='U') {
			cover[rt]=1;
			XOR[rt]=0;
		}else if (op=='D') {
			cover[rt]=0;
			XOR[rt]=0;
		}else if (op=='C' || op=='S') {
			FXOR(rt);
		}
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	if (L<=m) update(op,L,R,l,m,rt<<1);
	else if(op=='I'||op=='C')
		XOR[rt<<1]=cover[rt<<1]=0;
	if (R>m) update(op,L,R,m+1,r,rt<<1|1);
	else if (op=='I'||op=='C') 
		XOR[rt<<1|1]=cover[rt<<1|1]=0;
}
void query(int l,int r,int rt)
{
	if(cover[rt]==1)
	{
		for (int i=l; i<=r; i++) 
			hash[i]=true;
		return;
	}else if(cover[rt]==0) return;
	if(l==r)return;
	PushDown(rt);
	int m=(l+r)>>1;
	query(l,m,rt<<1);
	query(m+1,r,rt<<1|1);
}
int main (int argc, char * const argv[]) {
	cover[1]=XOR[1]=0;
	int a,b;
	char op,l,r;
	//freopen("a.txt", "r", stdin);
	while (~scanf("%c %c%d,%d%c\n",&op,&l,&a,&b,&r)) {
		a<<=1; b<<=1;
		if(l=='(')a++;
		if(r==')')b--;//???
		if (a>b) {
			if (op=='C'||op=='I'){
				cover[1]=XOR[1]=0;
			}
		} else update(op, a, b, 0, 131072, 1);
	}
	memset(hash, false, sizeof(hash));
	query(0, 131072, 1);
	bool flag=false;
	int s=-1,e;
	for (int i=0; i<=131072; i++) {
		if (hash[i]) {
			if (s==-1) s=i;
			e=i;
		}else {
			if (s!=-1) {
				if (flag) printf(" ");
				flag = true;
				printf("%c%d,%d%c",s&1?'(':'[' , s>>1 , (e+1)>>1 , e&1?')':']');
				s = -1;
			}
		}
	}
	if (!flag) printf("empty set");
	printf("\n");
    return 0;
}
