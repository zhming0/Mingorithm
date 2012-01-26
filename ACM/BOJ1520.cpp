#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int f[101][256];
int num[101];
int cost_d,cost_i,dis,n;
int min(int a,int b){return (a>b)?b:a;}
int min_cost(int from,int to,int pos)
{
	int r;
	r=99999999;
	if (abs(to-from)>dis&&dis>0) 
		r=min(r,((abs(to-from)-1)/dis)*cost_i+abs(to-num[pos]));
	else if(dis>0)
		r=min(r,abs(to-num[pos]));
	return r;
}
int main (int argc, char * const argv[]) {
	//freopen("test2.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
	int cases,p=0;
	cin>>cases;
	memset(f, 0, sizeof(f));
	while (cases--) {
		int i,j,k;
		int ans=100000000;
		cin>>cost_d>>cost_i>>dis>>n;
		memset(num, 0, sizeof(num));
		for (i=1; i<=n; i++)
			cin>>num[i];
		for (i=0; i<=n; i++) 
			for (j=0; j<256; j++) 
				f[i][j]=100000000;
		for(j=0;j<256;j++)
			f[1][j]=min(abs(num[1]-j), cost_d);
		for (i=2; i<=n; i++) 
		{
			for (j=0; j<256; j++) 
				f[i][j]=min(f[i-1][j]+abs(num[i]-j), f[i-1][j]+cost_d);
			if (dis>0) 
				for (j=0; j<256; j++) 
					for (k=0; k<256; k++) 
						f[i][j]=min(f[i][j], f[i-1][k]+min_cost(k, j,i));
			
		}
		for (i=0;i<256;i++) 
			ans=min(ans,f[n][i]);
		printf("Case #%d: %d\n",++p,ans);
	}
    return 0;
}
