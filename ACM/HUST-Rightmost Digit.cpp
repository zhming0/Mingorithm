#include <iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases;
	cin>>cases;
	while (cases--) {
		long long n;
		scanf("%I64d",&n);
		int a=n%10;
		int ans=1;
		while (n) {
			if(n&1)ans=(ans*a)%10;
			a=(a*a)%10;
			n>>=1;
		}
		printf("%d\n",ans);
	}
    return 0;
}
