#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 500001

int main (int argc, const char * argv[]) {
	int ball[MAX];
	int temp[MAX];
	int n,m;
	int i;
	memset(ball,0,sizeof(ball));
	memset(ball,0,sizeof(temp));
	while (scanf("%d %d",&n,&m)) 
	{
		for (i=0; i<n; i++) 
			ball[i]=i+1;
		
	}
	
    return 0;
}
