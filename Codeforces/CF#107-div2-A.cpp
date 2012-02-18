#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int slices = d * c, mil = l * k, slat = p;
	int ans = 0;
	slices -= n*1;
	mil -= n*nl;
	slat -= n*np;
	while (slices>=0 && mil >=0 && slat >=0) {
		ans++;
		slices -= n*1;
		mil -= n*nl;
		slat -= n*np;
	}
	printf("%d\n", ans);
	return 0;
}