#include <iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
const double esp=0.000000001;
typedef struct Point{
	int x,y;
}Point;
int money[51];
int dist[51][51];
int g,v;
int max(int a,int b)
{
	return a>b?a:b;
}
bool isConnect(int x1,int y1,int x2,int y2)
{
	if(x1==x2)return true;
	double t=double(abs(x2-x1))/v;
	double h=(g*t*t*1/2);
	double c=y1-y2;
	if((h-c)>esp)
		return false;
	return true;
}
int main (int argc, char * const argv[]) {
	//freopen("b.txt", "r", stdin);
	int cases,i,j,n,c,k;
	cin>>cases;
	while (cases--) {
		int ans=0;
		cin>>n;
		Point p[51];
		memset(dist, -1, sizeof(dist));
		for(i=0;i<n;i++) {
			int tempx,tempy;
			cin>>tempx>>tempy>>c;
			p[i].x=tempx;
			p[i].y=tempy;
			money[i]=c;
		}
		cin>>v>>g;
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				if(p[i].y>p[j].y)
					if(isConnect(p[i].x, p[i].y, p[j].x, p[j].y))
						dist[i][j]=money[j];
			}
		}
		//printf("dist[0][1]=%d,dist[1][2]=%d\n",dist[0][1],dist[1][0]);
		for (k=0; k<n; k++) {
			for (i=0; i<n; i++) {
				for (j=0; j<n; j++) {
					if(dist[i][k]!=-1&&dist[k][j]!=-1)
						dist[i][j]=max(dist[i][j], dist[i][k]+dist[k][j]);
					ans=max(ans,max(dist[i][j]+money[i],money[i]));
				}
			}
		}
		cout << ans<<endl;
	}
    return 0;
}
