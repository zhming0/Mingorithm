#include <iostream>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,n,t,i,ans,tmp[51];
	cin>>cases;
	while (cases--) {
		cin>>n;
		t=0;
		bool flag=true;
		for (i=0; i<n; i++) 
		{
			cin>>tmp[i];
			if(tmp[i]>=n)
				flag=false;
			t+=tmp[i];
		}
		ans=t/(n-1);
		for (i=0; i<n; i++) 
			if(ans!=tmp[i]&&ans!=(tmp[i]+1))
				flag=false;
		if(t%(n-1)!=0||ans>n||flag==false)
			cout << -1<<endl;
		else
			cout << ans<<endl;
	}
    return 0;
}
