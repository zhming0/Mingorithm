#include <iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<cmath>

using namespace std;

int n,m;
int ans;

int main (int argc, char * const argv[]) {
	int i,j;
	while (cin>>n>>m) 
	{
		
		if (n>=0) 
		{
			m=abs(m);
			ans=1;
			
			if (n==0) 
			{
				if (m==1) {
					cout << 2<<endl;
					continue;
				}
				cout << 1<<endl;
				continue;
			}
			if (m==0||m==1) {
				cout << n<<endl;
				continue;
			}
			
			cout << n/m<<endl;
		}
		else 
		{
			n=abs(n);
			m=abs(m);
			if (m==0||m==1) {
				cout << n+2<<endl;
				continue;
			}
			
			cout << n/m+1<<endl;
			
		}

	}
    return 0;
}
