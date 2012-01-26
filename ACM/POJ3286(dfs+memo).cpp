#include <iostream>
using namespace std;
typedef long long ll;
ll dp[20][2][20][2];
int n,limit[20];
void pre(ll num){
	n=0;
	while (num) {
		limit[n++]=num%10;
		num/=10;
	}
}
ll dfs(int pos,int ctrl,int zero,int first)
{
	if (pos<0)return zero;
	if(dp[pos][ctrl][zero][first]!=-1)return dp[pos][ctrl][zero][first];
	dp[pos][ctrl][zero][first]=0;
	int res=ctrl?limit[pos]+1:10;
	for (int i=0; i<res; i++) {
		if(i==0&&first==0)
			dp[pos][ctrl][zero][first]+=dfs(pos-1,ctrl&&i==limit[pos],zero+1,0);
		else if(i==0&&first==1)
			dp[pos][ctrl][zero][first]+=dfs(pos-1,ctrl&&i==limit[pos],zero,1);
		else
			dp[pos][ctrl][zero][first]+=dfs(pos-1,ctrl&&i==limit[pos],zero,0);
	}
	return dp[pos][ctrl][zero][first];
}
int main (int argc, char * const argv[]) {
	ll p,q;
	ll a,b;
	while (cin>>p>>q&&(p!=-1||q!=-1)) {
		if(p>0)
		{
			memset(dp, -1, sizeof(dp));
			pre(p-1);
			a=dfs(n-1, 1, 0, 1);
		}
		memset(dp, -1, sizeof(dp));
		pre(q);
		b=dfs(n-1, 1, 0, 1);
		if(p==0)
			cout << b+1<<endl;
		else
			cout << b-a<<endl;
	}
    return 0;
}
