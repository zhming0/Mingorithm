#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define SIZE 2010
const static double eps=1e-6;
double p[2010][4];
double dp[SIZE<<1][3];
int A,B,n;
int main (int argc, char * const argv[]) {
	//freopen("a.txt", "r", stdin);
	int cases;
	scanf("%d",&cases);
	while (cases--) {
		scanf("%d %d %d",&n,&A,&B);
		for (int i=1; i<=n; i++) 
			for (int j=0; j<4; j++) 
				scanf("%lf",&p[i][j]);
		for (int i=1; i<=B; i++) 
			for (int j=0; j<3; j++) {
				p[n+i][0]=p[n+i][1]=p[n+i][2]=p[n+i][3]=1;
				dp[n+i][j]=0;
			}
		dp[n][0]=dp[n][1]=dp[n][2]=1;
		for (int i=n-1; i>=0; i--) {
			for (int k=0; k<3; k++) {
				dp[i][k]=0;
				double tmp=1;
				for (int j=A; j<=B; j++) {
					if (i+j>n) {
						dp[i][k]+=tmp;
						break;
					}
					if (k==0) {
						dp[i][k]+=tmp*(p[i+j][3]*(dp[i+j][0]+1)+p[i+j][1]*(dp[i+j][1]+1)+p[i+j][2]*(dp[i+j][2]+1));
						if (p[i+j][3]!=0||+p[i+j][1]!=0||p[i+j][2]!=0) 
							tmp*=(p[i+j][0]);
					}
					else if (k==1) {
						dp[i][k]+=tmp*(p[i+j][2]*(dp[i+j][2]+1)+p[i+j][3]*(dp[i+j][0]+1));
						if (p[i+j][3]!=0||p[i+j][2]!=0) 
							tmp*=(p[i+j][0]+p[i+j][1]);
					}
					else{ 
						dp[i][k]+=tmp*(p[i+j][1]*(dp[i+j][1]+1)+p[i+j][3]*(dp[i+j][0]+1));
						if (p[i+j][3]!=0||p[i+j][1]!=0) 
							tmp*=(p[i+j][0]+p[i+j][2]);
					}
				}
			}
		}
		printf("%.8f\n",dp[0][0]);
	}
    return 0;
}
