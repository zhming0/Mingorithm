#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
int n;
const double eps=1e-7;
const double pi=acos(-1.0);
using namespace std;
double x[101];
int f(double len)
{
	double sum=0;
	for (int i=0; i<n; i++) {
		double a1=x[i],a2=(i==0)?x[n-1]:x[i-1];
		if (len-a1-a2>-eps) return -1;
		if (len-fabs(a1-a2)<-eps) return 1;
		sum+=acos((a1*a1+a2*a2-len*len)/(2*a1*a2));
	}
	if(fabs(sum-2*pi)<eps)return 0;
	if(sum-2*pi>eps) return -1;
	else return 1;
}
int main (int argc, char * const argv[]) {
	int cases,T=0;
	scanf("%d",&cases);
	while (cases--) {
		bool flag=false;
		scanf("%d",&n);
		double l=0,r=0,m;
		for (int i=0; i<n; i++) {
			scanf("%lf",&x[i]);
			r=max(x[i], r);
		}
		r*=2;
		printf("Case %d: ",++T);
		while (r-l>-eps) {
			m=(l+r)*0.5;
			int tmp=f(m);
			if (tmp==0){
				flag=true;
				break;
			}
			if(tmp<0)r=m-eps;
			else l=m+eps;
		}
		if (flag) 
			printf("%.3f\n",m);
		else
			printf("impossible\n");
	}
    return 0;
}
