#include <iostream>
#include<algorithm>
using namespace std;
int min(int a,int b)
{return a>b?b:a;}
int max(int a,int b)
{return a>b?a:b;}
int main(){
	freopen("1568.in", "r", stdin);
	int cases,i,j,minCus;
	int cost[22],customer[22],n;
	int dp[100001];
	cin>>cases;
	while (cases--) 
	{
		cin>>minCus;
		cin>>n;
		for (i=0; i<n; i++) cin>>customer[i];
		cin>>n;
		for (i=0; i<n; i++) cin>>cost[i];
		dp[0]=0;
		for (i=1; i<100001; i++) 
		{
			dp[i]=0;
			for (j=0; j<n; j++) 
				if((i-cost[j])>=0)
					dp[i]=max(dp[i], dp[i-cost[j]]+customer[j]);
			if(dp[i]>=minCus)
				break;
		}
		cout << i<<endl;
	}
	return 0;
}