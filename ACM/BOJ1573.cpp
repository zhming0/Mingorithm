#include <iostream>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,n,i,runs[51];
	i=1^1;
	//cout << i<<endl;
	cin>>cases;
	while (cases--) {
		int ans[2];
		int current=0;
		ans[0]=0;ans[1]=0;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>runs[i];
		for (i=0; i<n; i++) {
			ans[current]+=runs[i];
			if(runs[i]%2!=0)
				current=1^current;
			if((i+1)%6==0)
				current=1^current;
		}
		cout << 2<<endl;
		cout << ans[0]<<" "<<ans[1]<<endl;
	}
    return 0;
}
