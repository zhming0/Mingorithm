#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
int w[51],n,dp[10000001];
int min(int a,int b){return a>b?b:a;}
int gcd(int a,int b)
{
	while (b!=0) {
		int t=a%b;
		a=b;b=t;
	}
	return a;
}

int main () {
	int cases,i;
	cin>>cases;
	while (cases--) {
		cin>>n;
		for (i=0; i<n; i++) 
			cin>>w[i];
		int g=w[0];
		for (i=1; i<n; i++) 
			g=gcd(g,w[i]);
		for (i=0; i<n;i++) 
			w[i]/=g;
		queue<int> q;
		memset(dp, -1, sizeof(dp));
		q.push(0);
		dp[0]=0;
		while (!q.empty() && dp[1] == -1) {
			int x=q.front();
			q.pop();
			//if(x==1)
			//	break;
			for (i=0; i<n; i++) 
			{
				int y=gcd(w[i], x);
				if(dp[y]==-1)
				{
					dp[y]=dp[x]+1;
					q.push(y);
				}
			}
		}
		cout << dp[1]<<endl;
	}
    return 0;
}
