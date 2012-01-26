#include <iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
struct pos {
	double x;
	double y;
};
pos p[21];
int num[2<<20];
double dp[1<<20],dist[21][21],d[21][21];
double calDist(pos a,pos b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); 
}
double min(double a,double b)
{return a>b?b:a;}
int main (int argc, char * const argv[]) {
	int cases,n,i,j,k,T=1;
	for (i=0; i<(1<<20); i++) {
		int temp=i;
		num[i]=0;
		while (temp>0) {
			if((temp&1)>0)
				num[i]++;
			temp>>=1;
		}
	}
	cin>>cases;
	while (cases--) {
		cin>>p[0].x>>p[0].y;
		cin>>n;
		for (i=1; i<=2*n; i++) 
			cin>>p[i].x>>p[i].y;
		for (i=0; i<=2*n; i++) 
			for (j=0; j<=2*n; j++) 
				dist[i][j]=calDist(p[i],p[j]);
		for (i=1; i<=2*n; i++) 
			for (j=1; j<=2*n; j++) 
				d[i][j]=min(dist[0][i]+dist[i][j], dist[0][j]+dist[j][i]);
		dp[0]=0;
		for (i=1; i<((1<<(2*n))); i++) 
			dp[i]=100000000;
		for (i=0; i<((1<<(2*n))-1); i++) {
			if(num[i]%2==1)continue;
			for (j=0; j<2*n; j++)
				if((i&(1<<j))<=0)
					break;
			for (k=j+2; k<=2*n; k++) {
				if(k==(j+1)||(i&(1<<(k-1)))>0)continue;
				dp[i|(1<<j)|(1<<(k-1))]=min(dp[i]+d[k][j+1], dp[i|(1<<j)|(1<<(k-1))]);
			}
		}
		printf("Case #%d: %.2f\n",T++,dp[(1<<(2*n))-1]);
	}
    return 0;
}