#include <iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


int main (int argc, char * const argv[]) {
	
	int cases;
	int p=1;
	int i;
	scanf("%d",&cases);
	while (cases--) 
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int num=1;
		for (i=0; i<n; i++) {
			num*=2;
		}
		if ((k+1)%num==0) {
			printf("Case #%d: ON\n",p);
		}
		else {
			printf("Case #%d: OFF\n",p);
		}
		p++;
	}
	
    return 0;
}
