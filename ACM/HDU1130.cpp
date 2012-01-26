#include <iostream>
using namespace std;
int main (int argc, char * const argv[]) {
	long long i,j,f[101];
	memset(f, 0, sizeof(f));
	f[0]=1;
	f[1]=1;
	for (i=2; i<101; i++) {
		for (j=1; j<=i; j++) 
		{
			f[i]+=(f[j-1]*f[i-j]);
			//cout << f[i]<<endl;
		}
		cout << f[i]<<endl;
	}
	while (cin>>i) {
		//cout << f[i]<<endl;
	}
    return 0;
}
