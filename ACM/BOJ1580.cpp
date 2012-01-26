#include <iostream>
#include<string>
using namespace std;
long long inv[1000001];
long long ten[14];
long long inv_num(long long num)
{
	long long ans=0;
	while (num!=0) {
		ans*=10;
		ans+=(num%10);
		num/=10;
	}
	return ans;
}
long long digit(long long num)
{
	long long ans=0;
	while (num!=0) {
		ans++;
		num/=10;
	}
	return ans;
}
int main () {
	long long cases,n,i,j,k,d;
	inv[0]=0;ten[0]=1;
	for (i=1; i<=1000000; i++)
		inv[i]=inv_num(i);
	for (i=1; i<14; i++) 
		ten[i]=ten[i-1]*10;
	cin>>cases;
	while (cases--) {
		long long res;
		bool flag=false;
		cin>>n;
		if(n==1000000||n%9!=0)
		{
			cout << "NONE"<<endl;
			continue;
		}
		d=digit(n);
		for (i=d; i<=2*d; i++) 
		{
			long long tmp=(i/2)+i%2;
			k=ten[tmp];
			for (j=k/10; j<k; j++) 
			{
				long long inv_j=inv[j];
				long long p=(n+inv_j)%(ten[i-tmp]);
				long long ans=j*(ten[i-tmp])+p;
				if ((ans-inv_num(ans))==n) 
				{
					flag=true;
					res=ans;
					break;
				}
			}
			if(flag)break;
		}
		if(!flag)
			cout << "NONE"<<endl;
		else
			cout << res<<endl;
	}
    return 0;
}
