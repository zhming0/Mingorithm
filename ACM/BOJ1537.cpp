#include <stdio.h>
#include<stdlib.h>
#include<string.h>
double min(double a,double b){
	return (a>b)?b:a;
}
int main (int argc, const char * argv[]) {
	int cases;
	scanf("%d",&cases);
	while (cases--) {
		int n,i,j;
		double ans=9999999999;
		double cost[60],tax[60],eff[60];
		double fuelPrice,annualDis,year;
		scanf("%d",&n);
		for (i=0; i<n; i++) {
			scanf("%lf %lf %lf",&cost[i],&tax[i],&eff[i]);
		}
		scanf("%lf%lf%lf",&fuelPrice,&annualDis,&year);
		for (i=0; i<n; i++) {
			double c=cost[i]+tax[i]*year;
			c+=(double)(fuelPrice*annualDis*year/eff[i]);
			ans=min(ans, c);
		}
		printf("%.4f\n",ans);
	}
    return 0;
}
