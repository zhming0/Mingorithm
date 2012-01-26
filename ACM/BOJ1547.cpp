#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5000000
int sum[MAX+10];
int isPerfect(int a){
	if (a%4==3) {
		return 0;
	}
	if (a%8==3||a%8==6||a%8==7) {
		return 0;
	}
	if (a%16==3||a%16==7||a%16==11||a%16==12||a%16==14||a%16==15) {
		return 0;
	}
	return 1;
}
int main (int argc, const char * argv[]) {
	int cases;
	scanf("%d",&cases);
	int i;
	sum[0]=1;
	for (i=1; i<=MAX; i++) {
		if (isPerfect(i)) {
			sum[i]=sum[i-1]+1;
		}else {
			sum[i]=sum[i-1];
		}
	}
	while (cases--) {
		int u,d;
		scanf("%d %d",&d,&u);
		printf("%d\n",sum[u]-sum[d-1]);
	}
	
    return 0;
}
