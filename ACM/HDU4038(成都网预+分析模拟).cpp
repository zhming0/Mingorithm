#include <iostream>
#include<cstdio>
#include<cstring>
#define SIZE 100001
#define MOD 1000000007
using namespace std;
int n,m,x[SIZE];
long long product()
{
	long long ret=1;
	for (int i=0; i<n; i++) {
		ret*=x[i];
		ret%=MOD;
	}
	return ret;
}
long long pow(long long a, long long b)
{
	long long ret=1;
	b%=MOD;
	while (b) {
		if(b&1)
			ret=a*ret%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return ret;
}
int main (int argc, char * const argv[]) {
	int cases,T=0;
	scanf("%d",&cases);
	while (cases--) {
		scanf("%d%d",&n,&m);
		int nega=0,min=0x7fffffff,min_index=0;
		int nega_biggist=-1000000,nega_index=-1;
		int zero_cnt=0,zero_index[SIZE];
		for (int i=0; i<n; i++) {
			scanf("%d", &x[i]);
			nega+=(x[i]<0);
			if(x[i]==0)zero_index[zero_cnt++]=i;
			min_index=min<x[i]?min_index:i;
			min=min<x[i]?min:x[i];
			if(x[i]<0)
			{
				nega_biggist=nega_biggist>x[i]?nega_biggist:x[i];
				nega_index=nega_biggist>x[i]?nega_index:i;
			}
		}
		printf("Case %d: ", ++T);
		if(m<1||m<zero_cnt)
		{
			cout << product()<<endl;
			continue;
		}
		if (nega%2==1) 
		{
			if (m>=abs(nega_biggist)) {
				x[nega_index]=0;
				m+=(nega_biggist);
				zero_index[zero_cnt++]=nega_index;
			}else{
				x[nega_index]+=m;
				m=0;
			}
		}
		if(m<1||m<zero_cnt)
		{
			cout << product()<<endl;
			continue;
		}
		if(zero_cnt>0)
		{
			for (int i=0; i<zero_cnt; i++) 
				x[zero_index[i]]=1;
			m-=zero_cnt;
		}
		for (int i=0; i<n&&m>0; i++) 
			if(x[i]==1)
			{
				x[i]++;
				m--;
			}
		if (m<1) {
			cout << product()<<endl;
			continue;
		}
		for (int i=0; i<n&&m>0; i++) 
			if(x[i]==2)
			{
				x[i]++;
				m--;
			}
		if (m<1) {
			cout << product()<<endl;
			continue;
		}
		long long tmp=1;
		if (m>=3) {
			tmp=pow(3, m/3)%MOD;
			m%=3;
		}
		if(m==0){
			cout << tmp*product()%MOD<<endl;
			continue;
		}
		if (m==2) {
			cout << tmp*product()*2%MOD<<endl;
			continue;
		}
		if (m==1) {
			min=0x7fffffff;
			min_index=0;
			for (int i=0; i<n; i++) 
				if (x[i]<min&&x[i]>0) {
					min_index=i;
					min=x[i];
				}
			if(min>3&&tmp!=1)
				tmp=tmp*4/3;
			else
				x[min_index]++;
			cout << tmp*product()%MOD<<endl;
		}
	}
    return 0;
}





