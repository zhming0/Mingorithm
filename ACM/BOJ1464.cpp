//#include <iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>

using namespace std;
double x[50];
double y[50];
double inc[50];
int size;
double dp[50];
double dp2[50];

double distance(double x1,double x2,double y1,double y2)
{
	double temp=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return sqrt(temp);
}


void calculateInc()
{
	int i;
	for (i=0; i<size; i++) 
	{
		if (i==0) {
			inc[i]=distance(x[i+1],x[size-1],y[i+1],y[size-1])/2;
			//cout << inc[i]<<endl;
			continue;
		}
		if (i==size-1) {
			inc[i]=distance(x[0],x[i-1],y[0],y[i-1])/2;
			//cout << inc[i]<<endl;
			continue;
		}
		inc[i]=distance(x[i-1], x[i+1],y[i-1],y[i+1])/2;
		//cout << inc[i]<<endl;
	}
}

double max(double a,double b)
{
	return a>b?a:b;
}

void DP()
{
	int i;
	dp[0]=inc[0];
	dp[1]=inc[0];
	dp2[0]=0;
	dp2[1]=inc[1];
	for (i=2; i<size; i++) 
	{
		if (i==size-1) {
			dp[i]=dp[i-1];
			dp2[i]=max(dp2[i-1], dp2[i-2]+inc[i]);
			continue;
		}
		dp[i]=max(dp[i-1], dp[i-2]+inc[i]);
		dp2[i]=max(dp2[i-1], dp2[i-2]+inc[i]);
	}
}

int main (int argc, char * const argv[]) {
	int cases;
	int i;
	//cin>>cases;
	scanf("%d",&cases);
	while (cases--) 
	{
		double ans=0;
		//cin>>size;
		scanf("%d",&size);
		for (i=0; i<size; i++) 
		{
			//cin>>x[i];
			scanf("%lf",&x[i]);
		}
		for (i=0; i<size; i++) {
			//cin>>y[i];
			scanf("%lf",&y[i]);
		}
		
		calculateInc();
		
		memset(dp, 0, sizeof(dp));
		memset(dp2, 0, sizeof(dp2));
		DP();
		ans=dp[size-1]>dp2[size-1]?dp[size-1]:dp2[size-1];
		printf("%.4f\n",ans);
		//cout << dp[size]<<","<<dpx[size]<<endl;
		
	}
    return 0;
}
