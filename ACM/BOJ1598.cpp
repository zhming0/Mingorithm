#include <iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MAX 0x3fffffff
using namespace std;
struct point {
	double x,y;
};
point p[201];
double dist[201][201];
int n,m;
bool vst[201];
bool equ(double a, double b){return fabs(a - b) < 1e-7;}
int main (int argc, char * const argv[]) {
    int cases,T=1,i,j,k,one,four;
	scanf("%d",&cases);
	while (cases--) {
		double ans=0;
		scanf("%lf%lf",&p[0].x,&p[0].y);
		scanf("%d",&n);
		m=n*4;
		for (i=1; i<=m; i++) 
			scanf("%lf %lf",&p[i].x,&p[i].y);
		memset(vst, false, sizeof(vst));
		for (i=0; i<=m; i++) 
			for (j=0; j<=m; j++)
				dist[i][j]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+
								(p[i].y-p[j].y)*(p[i].y-p[j].y));
		for (i=0; i<n; i++) 
		{
			double mincost=MAX;
			double mindis=MAX;
			int tar[4];
			for (j=1; j<=m; j++) 
			{
				if(vst[j])continue;
				for (k=1; k<=m; k++) 
				{
					if(j==k||vst[k])continue;
					double min1[2];int first[2];
					min1[0]=min1[1]=MAX;
					for (one=1; one<=m; one++) {
						if(vst[one]||one==j||one==k)continue;
						double val=dist[0][one]+dist[one][j];
						if(val<min1[0]||(equ(min1[0],val)&&dist[0][one]<dist[0][first[0]]))
						{
							min1[1]=min1[0];first[1]=first[0];
							min1[0]=val;first[0]=one;
						}else if (val<min1[1]||(equ(min1[1],val)&&dist[0][one]<dist[0][first[1]])) {
							min1[1]=val,first[1]=one;
						}
					}
					double min4[2];int fourth[2];
					min4[0]=MAX;min4[1]=MAX;
					for (four=1; four<=m; four++) {
						if(vst[four]||four==j||four==k)continue;
						double val=dist[k][four];
						if(val<min4[0]||(equ(min4[0],val)&&dist[0][four]<dist[0][fourth[0]]))
						{
							min4[1]=min4[0];fourth[1]=fourth[0];
							min4[0]=val;fourth[0]=four;
						}else if (val<min4[1]||(equ(min4[1],val)&&dist[0][four]<dist[0][fourth[1]])) {
							min4[1]=val;fourth[1]=four;
						}
					}
					if (fourth[0]==first[0]) 
					{
						double val1=min1[0]+dist[j][k]+min4[1];double dis1=dist[first[0]][0]+dist[k][0]+dist[j][0]+dist[fourth[1]][0];
						double val4=min1[1]+dist[j][k]+min4[0];double dis2=dist[first[1]][0]+dist[k][0]+dist[j][0]+dist[fourth[0]][0];
						if(val1<val4)fourth[0]=fourth[1],min4[0]=min4[1];
						else if(val1>val4)first[0]=first[1],min1[0]=min1[1];
						else
						{
							if(dis1<dis2)fourth[0]=fourth[1],min4[0]=min4[1];
							else first[0]=first[1],min1[0]=min1[1];
						}
					}
					double cost=min1[0]+dist[j][k]+min4[0];
					double dis=dist[first[0]][0]+dist[k][0]+dist[j][0]+dist[fourth[0]][0];
					if(cost<mincost||(equ(mincost, cost)&&dis<mindis))
					{
						mincost=cost;mindis=dis;
						tar[0]=first[0];tar[1]=j;tar[2]=k;tar[3]=fourth[0];
					}
				}
			}
			ans+=mincost;
			vst[tar[0]]=vst[tar[1]]=vst[tar[2]]=vst[tar[3]]=true;
		}
		printf("Case #%d: %.2f\n",T++,ans);
	}
    return 0;
}
