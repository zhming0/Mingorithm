#include <iostream>
#include<cstdio>
#include<cstring>
const static long long M=1000000007;
using namespace std;
int n,r,m,k;
long long f[1010][1010],s[1010][1010];
long long g[1010][1010];
int main (int argc, char * const argv[]) {
	while (~scanf("%d%d%d%d",&n,&r,&k,&m)) {
		g[1][0]=0;
		for (int i=1; i<=n; i++) {f[1][i]=1;g[1][i]=g[1][i-1]+1;}
		for (int i=2; i<=r; i++) 
			for (int j=i; j<=n; j++) {
				f[i][j]=0;
				if (j-k>0) {
					f[i][j]=g[i-1][j-k];
				}
				g[i][j]=(g[i][j-1]+f[i][j])%M;
			}
		s[1][1]=1;
		for (int i=2; i<=r; i++) 
			for (int j=1; j<=m&&j<=n; j++) {
				s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%M;
			}
		long long ret=0;
		for (int i=1; i<=m; i++) {
			ret+=s[r][i];
			ret%=M;
		}
		long long ret2=0;
		for (int i=1; i<=n; i++) {
			ret2+=f[r][i]%M;
			ret2%=M;
		}
		printf("%lld\n",(ret*ret2)% M );
		//cout << ((ret*ret2)%M)<<endl;
	}
    return 0;
}
