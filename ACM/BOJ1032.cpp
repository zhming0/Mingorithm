#include<stdlib.h>
#include<stdio.h>

int n;
int x[10001];
int y[10001];

int cmp(const void * a,const void * b)
{
	int* x=(int*)a;
	int* y=(int*)b;
	return (*x)-(*y);
}

int cal(int a,int b)
{
	int i;
	int ans=0;
	for (i=0; i<n; i++) 
	{
		ans+=(abs(a-x[i])+abs(b-y[i]));
	}
	return ans;
}

int main (int argc, char * const argv[]) {
	int i;
	while (scanf("%d",&n)!=EOF)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		//int x,y;
		
		qsort(x, n, sizeof(int), cmp);
		qsort(y, n, sizeof(int), cmp);
		int a,b;
		
		a=x[n/2];
		b=y[n/2];
		//printf("a=%d,b=%d\n",a,b);
		int ans=cal(a, b);
		printf("%d\n",cal(a, b));
	}
	
    return 0;
}
