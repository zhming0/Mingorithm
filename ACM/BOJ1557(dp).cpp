//1557 dp
#include <iostream>
#include<math.h>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const double esp=0.0000000001;
typedef struct Point{
	int x,y;
	int money;
}Point;
int dp[51];
int g,v;
int max(int a,int b){return a>b?a:b;}
bool isConnect(int x1,int y1,int x2,int y2)//x1 is higher
{
	if(y1<y2) return false;
	if(x1==x2)return true;
	double t=double(abs(x2-x1))/v;
	double h=(g*t*t*1/2);
	double c=y1-y2;
	if((h-c)>esp)
		return false;
	return true;
}
int main (int argc, char * const argv[]) {
	int cases,n,i,j;
	//freopen("b.txt", "r", stdin);
	cin>>cases;
	while (cases--) {
		cin>>n;
		int ans=0;
		Point p[51];
		p[0].x=0;p[0].y=0;
		for(i=1;i<=n;i++) {
			int tempx,tempy,c;
			cin>>tempx>>tempy>>c;
			p[i].x=tempx;
			p[i].y=tempy;
			p[i].money=c;
		}
		cin>>v>>g;
		for (i=1; i<=n; i++) 
			for (j=i+1; j<=n; j++) 
				if(p[i].y<p[j].y)
				{
					Point temp=p[i];
					p[i]=p[j];
					p[j]=temp;
				}
		
		dp[0]=0;dp[1]=p[1].money;
		ans=p[1].money;
		for (i=2; i<=n; i++) {
			dp[i]=p[i].money;
			for (j=1; j<i; j++) {
				if(isConnect(p[j].x, p[j].y, p[i].x, p[i].y))
					dp[i]=max(dp[i], dp[j]+p[i].money);
				//cout << dp[i]<<endl;
			}
			ans=max(ans, dp[i]);
		}
		cout << ans<<endl;
		//printf("-----");
	}

    return 0;
}
