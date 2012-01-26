#include <iostream>
#include<string>
#include<string.h>
using namespace std;
bool prime[10001];
int main (int argc, char * const argv[]) {
	int n,i,j;
	memset(prime, true, sizeof(prime));
	prime[0]=false;
	prime[1]=false;
	for (i=2; i<=100; i++) {
		if (prime[i]) 
		{
			for (j=2; j<i; j++) 
				if(i%j==0)prime[i]=false;
		}
		int a=i*2;
		while (a<=10000) {
			prime[a]=false;
			a+=i;
		}
	}
	while (cin>>n) {
		int ans=0;
		if(n==0)
			break;
		for (i=1; i<=n/2; i++)
			if(prime[i]&&prime[n-i]&&i!=(n-i))
				ans++;
		cout << ans<<endl;
	}
    return 0;
}
