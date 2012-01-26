#include <iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int maxSum[100001],bestStart[100001],a[100001];
int main (int argc, char * const argv[]) {
	int cases,n,i,p=0;
	scanf("%d",&cases);
	while (cases--) {
		p++;
		scanf("%d",&n);
		for (i=0; i<n; i++) 
			scanf("%d",&a[i]);
		maxSum[0]=a[0];
		bestStart[0]=0;
		for (i=1; i<n; i++) 
		{
			if(maxSum[i-1]+a[i]>=a[i]){
				maxSum[i]=maxSum[i-1]+a[i];
				bestStart[i]=bestStart[i-1];
			}else {
				maxSum[i]=a[i];
				bestStart[i]=i;
			}
		}
		int max=-100000001;
		int lastNum;
		for (i=0; i<n; i++)
			if(max<maxSum[i])
			{
				max=maxSum[i];
				lastNum=i;
			}
		printf("Case %d:\n",p);
		printf("%d %d %d\n",max,bestStart[lastNum]+1,lastNum+1);
		if (cases>0) 
			printf("\n");
	}
    return 0;
}
