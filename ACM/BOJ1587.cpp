#include <iostream>
#include<cstring>
using namespace std;
long long f[30];

int main (int argc, char * const argv[]) {
	int i,j,cases,n;
	memset(f, 0, sizeof(f));
	f[0]=1;f[1]=1;
	for (i=2; i<26; i++) 
		for (j=0; j<i; j++) 
			f[i]+=f[j]*f[i-j-1];
	cin>>cases;
	while(cases--)
	{
		cin>>n;
		cout << f[n/2]<<endl;
	}
    return 0;
}
