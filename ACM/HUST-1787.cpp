#include <iostream>
using namespace std;
int main (int argc, char * const argv[]) {
	int n,i;
	while (cin>>n) {
		if(n==0)break;
		int ans=1,tot=n;
		for (i=2; i*i<=n; i++) {
			if (n%i==0) 
			{
				ans*=(i-1);
				n/=i;
				while (n%i==0) {
					ans*=i;
					n/=i;
				}
			}
		}
		if(n!=1)
			ans*=(n-1);
		//cout << ans<<endl;
		cout << tot-ans-1<<endl;
	}
    return 0;
}
