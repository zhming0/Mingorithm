#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50001

int up[MAX];
int down[MAX];

int main (int argc, const char * argv[]) {
	int n;
	int head;
	int sum;
	int i,j;
	while (scanf("%d",&n)) 
	{
		head=0;
		sum=1;
		scanf("%d %d",&down[0],&up[0]);
		for (i=0; i<n; i++) 
		{
			int a,b;
			scanf("%d %d",&a,&b);
			for (j=0; j<sum; j++) 
			{
				if ((a>down[j]&&a<up[j])||(b>down[j]&&b<up[j])) 
				{
					
				}
			}
		}
	
	}
    return 0;
}
