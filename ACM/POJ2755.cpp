#include <iostream>
#include<string>
#include<string.h>

using namespace std;

int dp[41][1000];
int v[1000];
int n;

//dp[V][j]=dp[V-v[j]][j-1]+dp[V][j-1]
//

int main (int argc, char * const argv[]) {
	
	while (cin>>n) 
	{
		int i,j;
		for (i=0; i<n;i++ ) 
		{
			cin>>v[i];
		}
		
		//memset(dp, 0, sizeof(dp));
		for (i=0; i<41; i++) {
			for (j=0; j<1000; j++) {
				dp[i][j]=0;
			}
		}
		
		for (i=1; i<=40; i++) 
		{
			for (j=0; j<n; j++)
			{
				if (i-v[j]==0) 
				{
					dp[i][j]=dp[i-v[j]][j-1]+dp[i][j-1]+1;
					//cout << i<<","<<j<<endl;
				}
				else if(i-v[j]<0)
					dp[i][j]=dp[i][i-1];
				else {
					dp[i][j]=dp[i-v[j]][j-1]+dp[i][j-1];
				}

			}
		}
		
		cout << dp[40][n-1]<<endl;
		
	}
	
    return 0;
}
