#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10001

int a[MAX];
int b[MAX];
int c[MAX];
int n;

double max(double x)
{
	double max=(1<<30);
	max=-max;
	int i;
	for (i=0; i<n; i++) {
		double temp=a[i]*x*x+b[i]*x+c[i];
		max=(max>temp)?max:temp;
	}
	return max;
}

double cal()
{
	double left=0,right=1000;
	double mid=(left+right)/2;
	double mid2=1000;
	while ((mid-mid2>0.000000001)||(mid2-mid>0.000000001)) {
		mid=(left+right)/2;
		mid2=(mid+right)/2;
		if (max(mid)<max(mid2)) 
		{
			right=mid2;
		}else 
		{
			left=mid;
		}
	}
	return max(mid);
}

int main (int argc, const char * argv[]) {
    int cases;
	scanf("%d",&cases);
	while (cases--)
	{
		int i;
		scanf("%d",&n);
		for (i=0; i<n; i++) {
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
		}
		
		printf("%.4f\n",cal());
		
	}
    return 0;
}
