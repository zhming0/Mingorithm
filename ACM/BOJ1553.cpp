#include <iostream>
#include<string.h>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,i;
	int f1[41];
	int f0[41];
	cin>>cases;
	memset(f1, 0, sizeof(f1));
	memset(f0, 0, sizeof(f0));
	f0[0]=1;
	f1[0]=0;
	f1[1]=1;
	f0[1]=0;
	f0[2]=1;
	f1[2]=1;
	for (i=3; i<=40; i++) {
		f0[i]=f0[i-1]+f0[i-2];
		f1[i]=f1[i-1]+f1[i-2];
	}
	while (cases--) {
		int n;
		cin>>n;
		cout << f0[n]<<" "<<f1[n]<<endl;
	}
    return 0;
}
