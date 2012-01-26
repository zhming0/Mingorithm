#include <iostream>
#include<stdio.h>
#include<string>
#include<string.h>
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{return a<b?a:b;}
int main (int argc, char * const argv[]) {
	int maxtime,mintime;
	int cases,i,n,s,temp;
	scanf("%d\n",&cases);
	while (cases--) {
		maxtime=-1;mintime=-1;
		scanf("%d %d",&s,&n);
		for (i=0; i<n; i++) {
			scanf("%d",&temp);
			maxtime=max(maxtime,max(s-temp,temp));
			mintime=max(mintime,min(s-temp,temp));
		}
		printf("%d %d\n",mintime,maxtime);
	}
    return 0;
}
