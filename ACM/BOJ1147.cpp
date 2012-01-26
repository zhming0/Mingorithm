#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20002

int father[MAX];

int getFather(int num)
{
	if (father[num]==num) 
		return num;
	father[num]=getFather(father[num]);
	return father[num];
}

int main (int argc, const char * argv[]) {
    int i;
	int n,m;
	int q;
	
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int num1,num2;	
		//memset(father,0,sizeof(father));
		for (i=1; i<=n; i++) {
			father[i]=i;
		}
		for (i=0; i<m; i++) 
		{
			scanf("%d %d",&num1,&num2);
			father[getFather(num1)]=father[getFather(num2)];
		}
		scanf("%d",&q);
		for (i=0;i<q ;i++ )
		{
			scanf("%d %d",&num1,&num2);
			if (getFather(num1)==getFather(num2)) 
				printf("YES\n");
			else 
				printf("NO\n");

		}
	}
	
	
    return 0;
}
