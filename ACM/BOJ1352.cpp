#include <iostream>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;
int cmp(const void* a,const void* b)
{return (*((int*)a))>(*((int*)b))?1:-1;}
int main (int argc, char * const argv[]) {
	int num[16];
	int n,i,j,ans;
	while (cin>>n) {
		i=0;ans=0;
		if (n==-1) 
			break;
		num[i++]=n;
		while (cin>>n) {
			if(n==0)
				break;
			else
				num[i++]=n;
		}
		qsort(num, i, sizeof(int), cmp);
		n=i;
		for (i=0; i<n; i++) 
			for (j=i+1; j<n; j++) {
				if(num[j]==(2*num[i]))
					ans++;
			}
		cout << ans<<endl;
	}
    return 0;
}
