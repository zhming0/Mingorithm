#include <iostream>
#include<string>
using namespace std;
string word;
string dict[610];
int dp[310];
int min(int a,int b){return a>b?b:a;}
int main (int argc, char * const argv[]) {
	int n,L,i,j;
	while (cin>>n>>L) {
		cin>>word;
		for (i=0; i<n; i++) 
			cin>>dict[i];
		dp[0]=0;
		for (i=1; i<=L; i++) 
		{
			dp[i]=i;
			for (j=0; j<n; j++) 
			{
				int p=i,k=dict[j].length()-1;
				while (p>0&&k>=0) 
				{
					if(dict[j][k]==word[p-1])
					{
						k--;p--;
					}
					else
						p--;
				}
				if(k<0)
					dp[i]=min(dp[p]+i-dict[j].length()-p, dp[i]);
			}
		}
		cout << dp[L]<<endl;
	}
    return 0;
}
