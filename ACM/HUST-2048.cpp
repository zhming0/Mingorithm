#include <iostream>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
long long c[21][21];
long long ans[21];
long long a[21];
int main (int argc, char * const argv[]) {
	int i,j;
	double rate;
	memset(ans, 0, sizeof(ans));
	memset(a,0,sizeof(a));
	ans[0]=1;
	ans[1]=0;
	ans[2]=1;
	c[0][0]=0;
	a[1]=1;
	for (i=1; i<21; i++) {
		c[i][0]=1;
		c[i][i]=1;
		for (j=1; j<i; j++) 
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	for(i=2;i<21;i++)
		a[i]=a[i-1]*i;
	for (i=3; i<21; i++) {
		long long temp=0;
		for (j=0; j<i; j++) 
			temp+=c[i][j]*ans[j];
		ans[i]=a[i]-temp;
		//cout << ans[i]<<"--"<<a[i]<<"--"<<i<<endl;
	}
	//cout << a[20]<<endl;
	cin>>j;
	while (j--) {
		cin>>i;
		rate=(double)ans[i]/a[i];
		rate*=100;
		printf("%.2f%%\n",rate);
	}
    return 0;
}
