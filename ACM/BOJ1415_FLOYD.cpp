#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000000
int dist[101][101];

int main (int argc, const char * argv[]) {
	int n,i,j,k;
	//freopen("test.txt", "r", stdin);
	while (1) {
		scanf("%d",&n);
		int ans=MAX;
		int ans_num;
		int isOk=1;
		for (i=0; i<101; i++) 
			for (j=0; j<101; j++) 
				dist[i][j]=MAX;
		if (n==0) 
			break;
		for (i=1; i<=n; i++) {
			int m;
			scanf("%d",&m);
			for (j=0; j<m; j++) {
				int a,b;
				scanf("%d %d",&a,&b);
				dist[i][a]=b;
			}
		}
		for (k=1; k<=n; k++) 
			for (i=1; i<=n; i++) 
				for (j=1; j<=n; j++) {
					if (i==j) 
						continue;
					int temp=dist[k][j]+dist[i][k];
					dist[i][j]=(dist[i][j]<temp)?dist[i][j]:temp;
				}
		for (i=1; i<=n; i++) {
			int max=0;
			for (j=1; j<=n; j++) {
				if (dist[i][j]==MAX&&i!=j) {
					isOk=0;break;
				}
				if (i==j) 
					continue;
				max=(max>dist[i][j])?max:dist[i][j];
			}
			if (isOk==1)
				if(ans>max){
					ans=max;
					ans_num=i;
				}
			isOk=1;
		}
		if (ans==MAX) 
			printf("disjoint\n");
		else
			printf("%d %d\n",ans_num,ans);
	}
    return 0;
}
