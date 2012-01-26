#include <iostream>
#include<stdlib.h>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases;
	cin>>cases;
	//cout << -1%2<<endl;
	while (cases--) {
		int x,y;
		int ans;
		cin>>x>>y;
		if (x==0) {
			if (y>=0) {
				ans=y;
			}else if(y<0&&y%2!=0)
				ans=abs(y)+2;
			else
				ans=abs(y)+4;
		}
		else if (y>0) {
			if ((x<0&&x%2!=0&&y%2!=0)||(x>0&&x%2==0)||(x<0&&x%2==0)||(x>0&&x%2!=0&&y%2==0)||(x>0&&x%2!=0&&y%2==0)) {
				ans=y+abs(x);
			}
			if ((x>0&&x%2!=0&&y%2!=0)||(x<0&&x%2!=0&&y%2==0)) {
				ans=y+abs(x)+2;
			}
		}
		else if (y<0) {
			if ((x<0&&x%2!=0)||(x>0&&x%2==0&&y%2!=0)||(x<0&&x%2==0&&y%2!=0)) {
				ans=abs(y)+abs(x)+2;
			}
			if ((x<0&&x%2==0&&y%2==0)) {
				ans=abs(y)+abs(x)+4;
			}
			if ((x>0&&x%2!=0)||(x>0&&x%2==0&&y%2==0)) {
				ans=abs(x)+abs(y);
			}
		}
		else if(y==0)
		{
			if (x>=0) {
				ans=x;
			}
			else if(x<0&&x%2!=0)
			{
				ans=abs(x)+2;
			}
			else
				ans=abs(x)+4;
		}
		cout << ans<<endl;
	}
    return 0;
}
