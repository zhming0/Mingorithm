#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int max(int a,int b){return (a>b)?a:b;}
int min(int a,int b){return (a<b)?a:b;}
int main (int argc, const char * argv[]) {
	int n,i,j;
	double h[1010];
	while (scanf("%d",&n)!=EOF) {
		int ans=-(1<<30);
		for (i=0; i<n; i++) 
			scanf("%lf",&h[i]);
		int d[1010],p[1010];
		for (i=0; i<n; i++) {
			d[i]=1;
			for (j=i-1; j>=0; j--) 
				if (h[i]>h[j]&&d[j]+1>d[i]) 
					d[i]=d[j]+1;
			printf("d[%d]=%d\n",i,d[i]);
		}
		printf("d[%d]=%d\n",n-1,d[n-1]);
		for (i=n-1; i>=0; i--) {
			p[i]=1;
			for (j=i+1; j<n; j++) 
				if (h[i]>h[j]&&p[j]+1>p[i])
					p[i]=p[j]+1;
		}
		for (i=0; i<n; i++) 
			for (j=i+1; j<n; j++) 
				ans=max(ans, d[i]+p[j]);
		printf("%d\n",n-ans);
	}
    return 0;
}
