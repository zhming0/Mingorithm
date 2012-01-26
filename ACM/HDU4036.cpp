#include <iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#define N 1010
using namespace std;
const static double g=20.0f;
double h[N],x[N];
double px[N],ph[N],pv[N];
int main (int argc, char * const argv[]) {
	int cases,T=1,tmp;
	//freopen("backup.txt", "r", stdin);
	scanf("%d",&cases);
	while (cases--) {
		int n,m;
		scanf("%d%d%d", &n, &m, &tmp);
		for (int i=0; i<n; i++) 
			scanf("%lf %lf",&x[i], &h[i]);
		for (int i=0; i<m; i++) 
			scanf("%lf %lf %d",&px[i], &pv[i], &tmp);
		for (int i=0; i<m; i++) 
			for (int j=0; j<n; j++) {
				if (px[i]==x[j]) {
					ph[i]=h[j];
					break;
				}else if (px[i]>x[j]&&px[i]<x[j+1]) {
					ph[i]=h[j]+(h[j+1]-h[j])*(px[i]-x[j])/(x[j+1]-x[j]);
					break;
				}
			}
		double ret=0;
		for (int i=0,j; i<n-1; i++) {
			double v=0;
			if(h[i+1]>h[i])
				v=sqrt(g*2*(h[i+1]-h[i]));
			for (j=0; px[j]<x[i+1]&&j<m; j++) {
				if (pv[j]*pv[j]-2*g*(h[i]-ph[j])<0)
					continue;
				if (h[i]==ph[j]) 
				{
					v=max(v, pv[j]);
					continue;
				}
				double temp_v=sqrt((pv[j]*pv[j]-2*g*(h[i]-ph[j])));
				v=max(temp_v, v);
			}
			if (v*v+2*g*(h[i]-h[0])>=0) {
				v=sqrt(v*v+2*g*(h[i]-h[0]));
			}else 
				v=0;
			ret=max(v, ret);
		}
		printf("Case %d: %.2f\n",T++,ret);
	}
    return 0;
}
