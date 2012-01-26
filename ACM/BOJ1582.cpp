#include <iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int f[1000001];
int main (int argc, char * const argv[]) {
	int cases,i,n;
	n=1;
	f[0]=0;f[1]=0;
	for (i=2; i<=1000000; i++) 
	{
		if(i<(n*n+n+1))
			f[i]=f[i-1]+i-n*n-1;
		else if(i>(n*n+n+1))
			f[i]=f[i-1]+i-n*n-n-1;
		else
			f[i]=f[i-1];
		if(i==(n+1)*(n+1))
			n++;
	}
	cin>>cases;
	while (cases--) {
		cin>>n;
		cout << f[n]<<endl;
	}
    return 0;
}
