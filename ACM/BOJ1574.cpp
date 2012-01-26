#include <iostream>
#include<cstdio>
#include<string>
using namespace std;
int main (int argc, char * const argv[]) {
	int cases,n,bin,i,binmax;
	double rate[17],ans[17];
	cin>>cases;
	while (cases--) 
	{
		cin>>n;
		for (i=0; i<n; i++) 
		{
			scanf("%lf",&rate[i]);
			ans[i]=0;
		}
		ans[n]=0;
		binmax=1;
		for (i=0; i<n; i++) 
			binmax*=2;
		binmax-=1;
		for (bin=0; bin<=binmax; bin++) {
			int temp=1,num_fail=0;
			double temp_ans=1;
			for (i=0; i<n; i++) 
			{
				if ((bin&temp)>0)
				{
					temp_ans*=(rate[i]);
					num_fail++;
				}else 
					temp_ans*=(1-rate[i]);
				temp=temp<<1;
			}
			//printf("bin=%d!!num_fail=%d,temp_ans=%f\n",bin,num_fail,temp_ans);
			ans[num_fail]+=temp_ans;
		}
		printf("%d\n",n+1);
		for (i=0; i<n; i++) 
			printf("%.4f ",ans[i]);
		printf("%.4f\n",ans[n]);
	}
    return 0;
}
