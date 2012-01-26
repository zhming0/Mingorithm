#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
long long cal(long long x,long long y)
{
	long long a=x,b=y;
	long long temp;
	if(x<y)
		temp=x,x=y,y=temp;
    while(y!=0)
	{
		x%=y;
		temp=x;
		x=y;
		y=temp;
	}
	return (a*b)/x;
}

int main (int argc, char * const argv[]) {
	int cases,i;
	int num[500];
	cin>>cases;
	while (cases--) {
		int n;
		long long times=1;
		long long ans;
		memset(num, 0, sizeof(num));
		cin>>n;
		for (i=0; i<n; i++) 
			scanf("%d\n",&num[i]);
		times=num[n-1];
		for (i=n-2; i>=0; i--) 
		{
			times=cal(times,(long long)num[i]);
		}
		long long lower,upper;
		cin>>lower>>upper;
		ans=upper/times-(lower-1)/times;
		cout << ans<<endl;
		//printf("%I64d\n",ans);
	}

    return 0;
}
