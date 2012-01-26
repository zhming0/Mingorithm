#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main (int argc, const char * argv[]) {
	int n,k,i;
	int dis[1001];
	while (scanf("%d %d",&n,&k)) {
		memset(dis,0,sizeof(dis));
		for (i=0; i<k+1; i++) 
			scanf("%d",&dis[i]);
		int temp=n;
		int ans=0;
		for (i=0; i<k; i++) {
			if (temp==n&&n<dis[i]) {
				printf("No Solution\n");
				return 0;
			}
			if (temp-dis[i]<dis[i+1]) {
				temp=n;
				ans++;
			}
			else
				temp-=dis[i];
		}
		printf("%d\n",ans);
	}
    return 0;
}
