#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[50010];
int f[50010],n;
inline int lowbit(int x){return x&-x;}
void update(int pos,int delta){
	for (int i=pos; i<=n; i+=lowbit(i)) 
		f[i]+=delta;
}
int sum(int pos)
{
	int ret=0;
	while (pos) {
		ret+=f[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
int main (int argc, char * const argv[]) {
	int cases,m,T=1;
	scanf("%d",&cases);
	while (cases--) {
		scanf("%d %d",&n,&m);
		scanf("%s",s+1);
		memset(f, 0, sizeof(f));
		for (int i=3; i<=n; i++) 
			if (s[i-2]=='w'&&s[i-1]=='b'&&s[i]=='w') 
				update(i, 1);
		printf("Case %d:\n",T++);
		while (m--) {
			int flag;
			scanf("%d",&flag);
			if (flag) {
				int a;char b[10];
				scanf("%d",&a);
				scanf("%s",b);a++;
				for (int i=a; i<=a+2&&i<=n; i++) 
				{
					if (i<3) continue;
					if (s[i-2]=='w'&&s[i-1]=='b'&&s[i]=='w') 
						update(i, -1);
				}
				//printf("b[0]=%c\n");
				s[a]=b[0];
				for (int i=a; i<=a+2&&i<=n; i++) 
				{
					if (i<3) continue;
					if (s[i-2]=='w'&&s[i-1]=='b'&&s[i]=='w') 
						update(i, 1);
				}
			}else {
				int a,b;
				scanf("%d%d",&a,&b);
				a++,b++;
				if (a>=b||b-a<2) 
					printf("0\n");
				else
					printf("%d\n",sum(b)-sum(a+1));
			}
		}
	}
    return 0;
}
