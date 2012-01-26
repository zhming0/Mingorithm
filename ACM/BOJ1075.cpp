#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct interval{
	int from,to;
}interval;
int cmp(const void* a,const void* b){
	return ((interval*)a)->to>((interval*)b)->to?1:-1;
}
int main (int argc, const char * argv[]) {
	int n,i;
	interval in[102];
	while (scanf("%d",&n)!=EOF) {
		int ans=0;
		for (i=0; i<n; i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			if (a>b) 
			{
				in[i].from=b;
				in[i].to=a;
			}else {
				in[i].from=a;
				in[i].to=b;
			}
		}
		qsort(in, n, sizeof(interval), cmp);
		int last=-999999999;
		for (i=0; i<n; i++) {
			if (in[i].from>last) {
				last=in[i].to;
				ans++;
			}
		}
		printf("%d\n",n-ans);
	}
    return 0;
}
