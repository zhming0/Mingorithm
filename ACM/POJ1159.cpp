#include<string>
#include<iostream>
#include<string.h>
using namespace std;
int max(int a, int b){return a>b?a:b;}
short dp[5001][5001];
int main()
{
	int n,i,j;
	string s1,s2;
	while (cin>>n) {
		cin>>s1;
		for (i=s1.length()-1,j=0; i>=0; i--,j++) 
			s2+=s1[i];
		for (i=0; i<n; i++) 
			for (j=0; j<n; j++) {
				if (s2[i]==s1[j]) 
				{
					if (i>0&&j>0) 
						dp[i][j]=dp[i-1][j-1]+1;
					else
						dp[i][j]=1;
				}else
				{
					if (i>0&&j>0) 
						dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
					else if(i==0&&j>0)
						dp[i][j]=dp[i][j-1];
					else if(j==0&&i>0)
						dp[i][j]=dp[i-1][j];
					else
						dp[i][j]=0;
				}
			}
		//cout << s1<<"||"<<s2<<endl;
		cout << n-dp[i-1][j-1]<<endl;
	}
}