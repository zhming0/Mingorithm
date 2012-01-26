#include <iostream>
#include<string.h>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,n,i,j;
	cin>>cases;
	while (cases--) {
		double pro[6];
		double amount[6];
		double tot=0;
		double a=0,b=0;
		double otherPro=1;
		double ans;
		double minMoney;
		cin>>n;
		for (i=0; i<n; i++) 
		{
			cin>>pro[i];
			pro[i]/=100;
		}
		for (i=0; i<n; i++) {
			cin>>amount[i];
			tot+=amount[i];
		}
		cin>>minMoney;
		for (i=0; i<n; i++) {
			double tempRate=pro[i];
			/*for (j=0; j<n; j++) 
			{
				if (i!=j) 
					tempRate*=(1-pro[j]);
			}*/
			otherPro-=tempRate;
			b+=amount[i]*tempRate;
			a+=(tot-amount[i])*(1-tempRate);
		}
		a+=otherPro*tot;
		if (b<=0) {
			cout << -1<<endl;
			continue;
		}
		ans=(a-minMoney)/b;
		if (ans<0)
			cout <<-2<<endl;
		else {
			printf("%.4f\n",ans);
		}
		cout << a<<","<<b<<endl;
	}
    return 0;
}
