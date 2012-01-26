#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1<<30
int main (int argc, const char * argv[]) {
	int cases;
	int a[60];
	int isLegal[60][60];
	int ans[60];
	int n,i,j,k;
	scanf("%d",&cases);
	while (cases--) {
		scanf("%d",&n);
		memset(isLegal,0,sizeof(isLegal));
		memset(ans,0,sizeof(ans));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		a[n]=MAX;
		for (i=0; i<=n; i++) 
			for (j=i+1; j<=n; j++) 
				if (a[j]>a[i]) {
					k=i+1;
					while (k<j&&(a[k]<a[i]||a[k]>a[j])) 
						k++;
					if (k>=j) 
						isLegal[i][j]=1;	
				}
		ans[0]=1;
		for (i=1; i<=n; i++) {
			for (j=0; j<i; j++) {
				if (isLegal[j][i]==1) 
					ans[i]+=ans[j];
			}
			if (ans[i]==0)
				ans[i]=1;
		}
		printf("%d\n",ans[n]);
	}
    return 0;
}
