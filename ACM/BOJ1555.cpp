#include <iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;
int min(int a,int b)
{return a>b?b:a;}
int max(int a,int b)
{return a>b?a:b;}
int main (int argc, char * const argv[]) {
	int cases;
	int i,j,x1,x2,y1,y2,d;
	cin>>cases;
	while (cases--) {
		int ans=0;
		//scanf("%I64d %I64d %I64d %I64d %I64d",x1,y1,x2,y2,d);
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &d);
		//cin>>x1>>y1>>x2>>y2>>d;
		for (i=min(x1, x2)-d; i<=max(x1,x2)+d; i++) {
			for (j=min(y1,y2)-d; j<=max(y1,y2)+d; j++) {
				if(sqrt((i-x1) * (i-x1) + (j - y1) * (j - y1)) + sqrt((i-x2) * (i-x2) + (j - y2) * (j - y2)) < d) 
				{
					//printf("x=%.0f,y=%.0f\n",i,j);
					ans++;
				}
			}
		}
		//cout << dist(2, 2, 0, 0)<<endl;
		cout << ans<<endl;
	}
    return 0;
}
