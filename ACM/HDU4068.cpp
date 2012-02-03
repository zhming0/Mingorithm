#include<cstring>
#include<string>
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int grid[6][6], seq1[6], seq2[6];
map<string, int> stokey;
map<int, string> keytos;
string s[6];
bool vst1[6], vst2[6];
bool judge(const int a[], const int b[], int n)
{
	int i=0, j=0;
	while (i<n && j<n) {
		if (grid[b[j]][a[i]]==1) 
			i++;
		else
			j++;
	}
	if (j==n) 
		return true;
	else
		return false;
}
bool test(int now, int limit)
{
	if (now == limit) {
		if (judge(seq1, seq2, limit)==false) 
			return false;
		return true;
	}
	for (int i=0; i<limit; i++) {
		if (!vst2[i]) {
			vst2[i] = true;
			seq2[now] = i;
			if (test(now+1, limit)==false) { 
				vst2[i] = false;
				return false;
			}
			vst2[i] = false;
		}
	}
	return true;
}
bool solve(int now, int limit)
{
	if (now == limit) {
	 	if (test(0, limit)==true) 
			return true;
		return false;
	}
	for (int i=0; i<limit; i++) {
		if (!vst1[i]) {
			vst1[i] = true;
			seq1[now] = i;
			if (solve(now+1, limit)==true) {
				vst1[i] = false;
				return true;
			}
			vst1[i] = false;
		}
	}
	return false;
}
int main(int argc, char *argv[]) {
	int cases, n, T = 0;
	cin >> cases;
	while (cases--) {
		T++;
		memset(grid, 0, sizeof(grid));
		memset(vst1, false, sizeof(vst1));
		memset(vst2, false, sizeof(vst2));
		cin >> n;
		for (int i=0; i<n; i++) 
			cin >> s[i];	
		sort(s, s+n);
		for (int i=0; i<n; i++) {
			stokey[s[i]] = i;
			keytos[i] = s[i];
		}
		for (int i=0; i<n; i++) {
			int tmp;
			cin >> tmp;
			for (int j=0; j<tmp; j++) {
				string tmp_s;
				cin >> tmp_s;
				grid[i][stokey[tmp_s]] = 1;
			}
		}
		bool ret = solve(0, n);
		if (ret) {
			printf("Case %d: Yes\n", T);
			for (int i=0; i<n-1; i++) 
				cout << keytos[seq1[i]] << " ";
			cout << keytos[seq1[n-1]] << endl;
		}else 
			printf("Case %d: No\n", T);
	}
	return 0;
}