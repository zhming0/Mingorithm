#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void * a ,const void * b){
	return (*(int*)a>*(int*)b)?1:-1;
}
int main (int argc, const char * argv[]) {
	int n,length,i,ans;
	int l[1001];
	while (scanf("%d %d",&n,&length)!=EOF) 
	{
		ans=0;
		memset(l,0,sizeof(l));
		for (i=0; i<n; i++) 
			scanf("%d",&l[i]);
		qsort(l,n,sizeof(int),cmp);
		for (i=0; i<n; i++) {
			length-=l[i];
			if (length>=0) 
				ans++;
			else
				break;
		}
		printf("%d\n",ans);
	}
    return 0;
}
