#include <stdio.h>
#include<string.h>
#define MAX 500000
int a[MAX+10];
char isHere[10*MAX];
int main (int argc, const char * argv[]) {
	int n,i;
	a[0]=0;
	memset(a,0,sizeof(a));
	isHere[0]=1;
	for (i=1; i<=MAX; i++) {
		if (a[i-1]-i>0&&isHere[a[i-1]-i]==0) 
			a[i]=a[i-1]-i;
		else 
			a[i]=a[i-1]+i;
		isHere[a[i]]=1;
	}
	while (scanf("%d",&n)!=EOF) {
		if (n==-1) 
			break;
		printf("%d\n",a[n]);
	}
    return 0;
}
