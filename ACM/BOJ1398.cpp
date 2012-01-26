#include <stdio.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX 50001
int god[MAX];
int getGod(int num)
{
	if (god[num]==num) 
		return num;
	god[num]=getGod(god[num]);
	return god[num];
}

int main (int argc, const char * argv[]) {
    int m,n;
	int a,b;
	int i;
	int p=1;
	while (1) {
		scanf("%d %d",&n,&m);
		if (n==0&&m==0) {
			break;
		}
		for (i=0; i<MAX; i++) 
			god[i]=i;
		for (i=0; i<m; i++) {
			scanf("%d %d",&a,&b);
			if (getGod(a)!=getGod(b)) {
				god[getGod(a)]=god[getGod(b)];
				n--;
			}
		}
		printf("Case %d: %d\n",p,n);
		p++;
	}
    return 0;
}
