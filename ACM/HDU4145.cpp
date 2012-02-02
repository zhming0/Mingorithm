#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Pint{
	int x, y;
	int disq1, disq2;
	bool operator < (const Pint& b) const {
		return disq1 < b.disq1;
	}
}tower[2], army[100010];
int max_dist2[100010];
int disqr(const Pint& a, const Pint& b){
	return ((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y-b.y));
}

int main(int argc, char *argv[]) {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		int ret = 0x7fffffff;
		scanf("%d %d %d %d", &tower[0].x, &tower[0].y, &tower[1].x, &tower[1].y);
		scanf("%d", &n);
		for (int i=0; i<n; i++) {
			scanf("%d %d", &army[i].x, &army[i].y);
			army[i].disq1 = disqr(army[i], tower[0]);
			army[i].disq2 = disqr(army[i], tower[1]);
		}
		sort(army, army + n);
		max_dist2[n] = 0;
		for (int i=n-1; i>=0; i--) {
			ret = min(ret, army[i].disq1 + max_dist2[i+1]);
			max_dist2[i] = max(max_dist2[i+1], army[i].disq2);
		}
		ret = min(ret, max_dist2[0]);
		printf("%d\n", ret);
	}	
}