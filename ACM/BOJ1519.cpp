#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Rope{
	int left;
	int right;
}Rope;

int main (int argc, const char * argv[]) {
	int cases;
	int p=1;
	int i,j;
	scanf("%d",&cases);
	while (cases--) 
	{
		int n;
		int ans=0;
		scanf("%d",&n);
		Rope rope[n];
		for(i=0;i<n;i++) 
		{
			scanf("%d%d",&rope[i].left,&rope[i].right);
		}
		
		for (i=0; i<n; i++) {
			for (j=i; j<n; j++) 
			{
				if ((rope[i].left-rope[j].left)*(rope[i].right-rope[j].right)<0) 
				{
					ans++;
				}
			}
		}
		
		printf("Case #%d: %d\n",p,ans);
		p++;
		
	}
    return 0;
}
