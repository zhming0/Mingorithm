#include <iostream>
#include<cstring>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,n,m,l;
	int times[51];
	cin>>cases;
	while (cases--) {
		int ans=0;
		cin>>n>>m>>l;
		memset(times, 0, sizeof(times));
		int i=1;
		while (1) {
			//printf("%d is holding\n",i);
			times[i]++;
			ans++;
			if(times[i]==m)
				break;
			if(times[i]%2==0)
			{
				i+=l;
				if(i>n)
					i-=n;
			}
			else 
			{
				i-=l;
				if(i<=0)
					i+=n;
			}
		}
		cout << ans-1<<endl;
	}
    return 0;
}
