#include <iostream>
#include<cstring>
#include<cstdio>
#include<map>
int num[1000100];
using namespace std;
map<int, int> mp; // MAP 一种以hash表为内核的数据结构
int main(int argc, char *argv[]) {
	int n, ret, l = 0;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &num[i]);
		if (mp[num[i]]) {       // 如果这个数字曾经出现过， 判断非0即true
			mp[num[i]]++;       // 关键！！ 把这个数字的统计量加1.
			while (mp[num[l]]>1) {      // 如果左端的数字出现过两次以上。
				mp[num[l]]--;
				l++;
				ret = min(ret, i - l + 1);      // 不断的更新ret
			}
		} else {                // 如果没出现过
			ret = i - l + 1;    // 覆盖ret， 这里没有用min， 原因很明确。
			mp[num[i]]++;
		}
	}
	printf("%d\n", ret);
	return 0;
}