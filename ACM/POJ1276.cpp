#include <iostream>
#include<string>
#include<string.h>
#define MAX 1001

using namespace std;

int D[MAX];
int n[MAX];
int dp[100001];
int tot;
int max(int a ,int b)
{
	if (a>tot) {
		return b;
	}
	if (b>tot) {
		return a;
	}
	return a>b?a:b;
}

void DP(int num)
{
	int i,j,k;
	
	
	for (i=1; i<=num; i++) 
	{
		for (j=1; j<=tot; j++) 
		{
			for (k=1; k<=n[i];k++) 
			{
				if (j-k*D[i]<0) {
					dp[j]=dp[j];
				}
				else {
					dp[j]=max(dp[j], dp[j-k*D[i]]+D[i]);
				}

			}
		}
	}
	
}

int main (int argc, char * const argv[]) 
{
	int N;
	int i;
	while (cin>>tot>>N) 
	{
		memset(dp, 0, sizeof(dp));
		D[0]=0;
		n[0]=0;
		for (i=1; i<=N; i++)
		{
			cin>>n[i]>>D[i];
		}
		if (tot==0||N==0) {
			cout << 0<<endl;
			continue;
		}
		DP(N);
		cout << dp[tot]<<endl;
		
	}
    return 0;
}
