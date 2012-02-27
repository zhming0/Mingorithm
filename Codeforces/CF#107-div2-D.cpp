#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define M 1000000007
bool vst[2010], grid[2010][2010];
int n;
void dfs(int from)
{
	for (int i=0; i<n; i++) {
		if (!vst[i] && grid[i][from])
		{
			vst[i] = true;
			dfs(i);
		}
	}
}
int main(int argc, char *argv[]) {
	int m, k;
	cin >> n >> m >> k;
	memset(vst, false, sizeof(vst));
	int comp = 0;
	for (int i=0; i<n; i++) {
		if (vst[i]) continue;
		for (int j=k-1; j >= 0; j-=2) {
			for (int p = (k - 1 - j)/2 ; p <= n - ( k - (k - 1 - j ) / 2); p++) {
				vst[p] = vst[p+j] = true;
				grid[p][p+j] = grid[p+j][p] = true;
			}
		}
	}
	memset(vst, 0, sizeof(vst));
	long long ret = 1;
	if (n < k) comp = n;
	else {
		for (int i=0; i<n; i++) {
			if (!vst[i])
			{
				comp++;
				dfs(i);
				vst[i] = true;
			}
		}
	}
	for (int i=0; i<comp; i++) {
		ret = ((ret % M) * (long long)(m % M)) % M;
	}
	cout << ret << endl;
	return 0;
}