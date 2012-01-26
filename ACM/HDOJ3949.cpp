#include <iostream>
#include<cstring>
typedef long long ll;
using namespace std;
ll a[10000];
int main (int argc, char * const argv[]) {
	ll cases,T=0,i,j,n,q,cnt,tmp,x,ans;
	ll b[64];b[0]=1;
	for (i=1; i<64; i++) b[i]=b[i-1]*2;
	cin>>cases;
	while (cases--&&(++T)) {
		memset(a, 0, sizeof(a));
		cin>>n;cnt=0;ans=1;
		for (i=0; i<n; i++) cin>>a[i];
		for (i=0; i<n; i++) {
			if(a[i]==0)continue;cnt++;
			for (j=63; j>=0; j--) 
				if(a[i]&b[j]){
					tmp=j;break;
				}
			for (j=0; j<n; j++) 
				if(i!=j&&(a[j]&b[tmp]))
					a[j]^=a[i];
		}
		ans=b[cnt];if(cnt==n)ans--;
		sort(a, a+n);
		cin>>q;
		cout << "Case #"<<T<<":"<<endl;
		while (q--) {
			ll res=0;
			cin>>x;
			if(x>ans){cout<<-1<<endl;continue;}
			if(cnt!=n)x--;
			tmp=n-cnt;
			while (x) {
				if(x&1)res^=a[tmp];
				x/=2;tmp++;
			}
			cout << res<<endl;
		}
	}
    return 0;
}
