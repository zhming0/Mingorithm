#include <iostream>
#include<string.h>
#include<string>
using namespace std;
#define A 0
#define C 1
#define G 2
#define T 3
int cvalue(char a)
{
	if(a=='A') return A;
	if(a=='C') return C;
	if(a=='G') return G;
	if(a=='T') return T;
	return -1;
}
int max(int a, int b,int c)
{
	int d=a>b?a:b;
	return d>c?d:c;
}
int main (int argc, char * const argv[]) {
	int cases,i,j,l1,l2;
	int dp[101][101];
	int sum1[101];
	int sum2[101];
	int table[5][5]={{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},
		{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
	string s1,s2;
	cin>>cases;
	while (cases--) {
		cin>>l1>>s1;
		cin>>l2>>s2;
		memset(dp, 0, sizeof(dp));
		memset(sum1, 0, sizeof(sum1));
		memset(sum2, 0, sizeof(sum2));
		sum1[0]=table[4][cvalue(s1[0])];
		sum2[0]=table[4][cvalue(s2[0])];
		for (i=1; i<l1; i++) 
			sum1[i]=sum1[i-1]+table[4][cvalue(s1[i])];
		for (i=1; i<l2; i++) 
			sum2[i]=sum2[i-1]+table[4][cvalue(s2[i])];
		for (i=0; i<l1; i++) {
			for (j=0; j<l2; j++) 
			{
				if (s1[i]==s2[j])
				{
					if (i>0&&j>0) 
						dp[i][j]=dp[i-1][j-1]+5;	
					else if(i==0&&j>0)
					{
						int a=5+sum2[j-1];
						int b=dp[i][j-1]+table[4][cvalue(s2[j])];
						dp[i][j]=a>b?a:b;
					}
					else if(j==0&&i>0)
					{
						int a=5+sum1[i-1];
						int b=dp[i-1][j]+table[4][cvalue(s1[i])];
						dp[i][j]=a>b?a:b;
					}
					else
						dp[i][j]=5;
				}else 
				{
					if(i>0&&j>0)
					{
						dp[i][j]=max(dp[i-1][j-1]+table[cvalue(s1[i])][cvalue(s2[j])],
									 dp[i-1][j]+table[4][cvalue(s1[i])],
									 dp[i][j-1]+table[4][cvalue(s2[j])]);
						//printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
					}else if (i==0&&j>0)
					{
						int a=sum2[j-1]+table[cvalue(s1[0])][cvalue(s2[j])];
						int b=dp[i][j-1]+table[4][cvalue(s2[j])];
						dp[i][j]=a>b?a:b;
					}
					else if (j==0&&i>0)
					{
						int a=sum1[i-1]+table[cvalue(s1[i])][cvalue(s2[0])];
						int b=dp[i-1][j]+table[4][cvalue(s1[i])];
						dp[i][j]=a>b?a:b;
					}
					else
					{
						//dp[i][j]=max(table[cvalue(s1[i])][cvalue(s2[j])],
						//			 table[4][cvalue(s2[j])],
						//			 table[4][cvalue(s1[i])]);
						int a=table[cvalue(s1[i])][cvalue(s2[j])];
						//int b=table[4][cvalue(s1[i])]+table[4][cvalue(s2[j])];
						//dp[i][j]=a>b?a:b;
						dp[i][j]=a;
					}
				}
			}
		}
		cout << dp[l1-1][l2-1]<<endl;
		//cout << dp[l1-2][l2-1]<<endl;
		//cout << dp[l1-1][l2-2]<<endl;
		//cout << dp[l1-2][l2-2]<<endl;
	}
    return 0;
}
