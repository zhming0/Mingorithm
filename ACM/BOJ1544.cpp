#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main (int argc, const char * argv[]) {
	long long x1,y1,x2,y2,r1,r2;
	int cases;
	scanf("%d",&cases);
	while (cases--) {
		//scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&r1,&x2,&y2,&r2);
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&x1,&y1,&r1,&x2,&y2,&r2);
		long long dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		long long l=(r1+r2)*(r1+r2);
		long long d=(r1-r2)*(r1-r2);
		if (x1==x2&&y1==y2&&r1==r2)
			printf("-1\n");
		else if (dis>l||dis<d)
			printf("0\n");
		else if(dis==l||dis==d)
			printf("1\n");
		else if(l>dis&&dis>d)
			printf("2\n");
	}
    return 0;
}
