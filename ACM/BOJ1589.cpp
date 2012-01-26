#include <iostream>
#include<string>
#include<cstring>
#include<cstdio>
#define INF 0x3fffffff
using namespace std;
int cost[17][17];
int dp[65536];
int op[65536];
int min(int a,int b){return a>b?b:a;}
int num_open(int num)
{
	int d=1,ans=0;
	while (d<65536&&d<=num)
	{
		if((num&d)>0)
			ans++;
		d<<=1;
	}
	return ans;
}
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int cases,n,minNum,i,j,k;
	char s[100];
	for (i=0; i<65536; i++) 
		op[i]=num_open(i);
	scanf("%d",&cases);
	while (cases--) 
	{
		int bin=1,state=0,open=0,ans=INF,biggist=1;
		scanf("%d",&n);
		for (i=0; i<n; i++) 
		{
			scanf("%s",s);
			for (j=0; s[j]!=0; j++) 
			{
				if(s[j]>='0'&&s[j]<='9')
					cost[i][j]=s[j]-'0';
				else
					cost[i][j]=s[j]-'A'+10;
			}
			biggist<<=1;
		}
		scanf("%s",s);i=0;
		while (bin<65536&&s[i]!=0) 
		{
			if (s[i]=='Y')
			{
				state+=bin;
				open++;
			}
			bin<<=1;
			i++;
		}
		scanf("%d",&minNum);
		if(open>=minNum)
		{
			printf("%d\n",0);
			continue;
		}
		for (i=0; i<biggist; i++) dp[i]=INF;
		dp[state]=0;
		for (i=state; i<biggist; i++) 
		{
			if(dp[i]==INF)continue;
			if (op[i]<open||i<state) continue;
			if(op[i]>minNum)continue;
			for (j=0; j<n; j++) 
			{
				if((i&(1<<j))>0) continue;
				for (k=0; k<n; k++)
					if(((1<<k)&i)>0&&k!=j)
						dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+cost[k][j]);
				if(op[i|(1<<j)]>=minNum)
					ans=min(ans,dp[i|(1<<j)]);
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}