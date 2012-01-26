#include <iostream>
#include<string.h>
using namespace std;
int max(int a,int b)
{return a>b?a:b;}
int main (int argc, char * const argv[]) {
    int n,i,j;
	int num[1010];
	int f[1010];
	while (cin>>n) {
		int ans=1;
		memset(num, 0, sizeof(num));
		memset(f, 0, sizeof(f));
		for(i=0;i<n;i++){
			f[i]=1;
			cin>>num[i];
		}
		for (i=1; i<n; i++) {
			for(j=0;j<i;j++)
			{
				if (num[i]>num[j]) 
					f[i]=max(f[i], f[j]+1);
			}
			ans=max(ans, f[i]);
		}
		cout << ans<<endl;
	}
    return 0;
}
