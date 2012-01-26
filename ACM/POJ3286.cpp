#include <iostream>
using namespace std;
typedef long long ll;
ll zero(ll num)
{
	ll ans=0;
	while (num) {
		if(num%10==0)ans++;
		num/=10;
	}
	return ans;
}
ll cal(ll num)
{
	if(num==0)return 0;
	if(num%10!=9)
		return cal(num+1)-zero(num+1);
	return num/10+10ll*cal(num/10);
}
int main () {
	ll m,n;
	while (cin>>m>>n&&(n!=-1||m!=-1)) {
		if(m==0)
			cout << cal(n)+1<<endl;
		else if (m==1) 
			cout << cal(n)<<endl;
		else
			cout << cal(n)-cal(m-1)<<endl;
	}
    return 0;
}
