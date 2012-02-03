#include <iostream>
#include<cstdio>
using namespace std;
int ret[110];
int main(int argc, char *argv[]) {
	int n, a, b;
	bool flag = true;
	cin >> n >> a >> b;
	int tb = 0, ta = 0;
	int tmp_count = 1, tmp_max = 1;
	int idx = 0;
	ret[0] = 1;
	while (1) {
		idx++;
		if (tb<b) {
			tb++;
			ret[idx] = tmp_count+1;
			if (ret[idx] > 50000) {
				flag = false;
				break;
			}
			tmp_max = ret[idx];
			tmp_count += ret[idx];
			continue;
		}
		if (ta<a) {
			if (tmp_max >= tmp_count) {
				ret[idx] = tmp_max;
				tmp_count += tmp_max;
				continue;
			}
			ta++;
			ret[idx] = tmp_max + 1;
			if (ret[idx] > 50000) {
				flag = false;
				break;
			}
			tmp_max = ret[idx];
			tmp_count += ret[idx];
			continue;
		}
		break;
	}
	for (int i=idx; i<n; i++) {
		ret[i] = ret[i-1];
	}
	if (!flag || idx > n ) {
		printf("-1\n");
		return 0;
	}
	for (int i=0; i<n-1; i++) {
		printf("%d ", ret[i]);
	}
	printf("%d\n", ret[n-1]);
	return 0;
}