#include <iostream>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;
typedef struct Matrix{
	int a,b;
	int c,d;
}Matrix;
Matrix combime(Matrix x,Matrix y)
{
	Matrix ans;
	ans.a=(x.a*y.a+x.b*y.c)%10000;
	ans.b=(x.a*y.b+x.b*y.d)%10000;
	ans.c=(x.c*y.a+x.d*y.c)%10000;
	ans.d=(x.c*y.b+x.d*y.d)%10000;
	return ans;
}
int main (int argc, char * const argv[]) {
	long long n;
	while (scanf("%I64d",&n)!=EOF) {
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		if(n==-1)
		{
			break;
		}
		Matrix m,ans;
		m.a=1;m.b=1;m.c=1;m.d=0;
		ans.a=1;ans.d=1;ans.c=0;ans.b=0;
		while (n) {
			if(n&1)ans=combime(ans, m);
			m=combime(m, m);
			n>>=1;
		}
		printf("%d\n",ans.b);
	}
    return 0;
}
