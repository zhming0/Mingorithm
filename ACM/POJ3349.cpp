#include <iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<ctime>
using namespace std;
#define M 19139
#define SIZE 100
struct Node{
	int len[6];
};
Node node[M][SIZE];
int num[M];
bool isSame(const Node& a, const Node& b)
{
	int ret1 = 1, ret2 = 1;
	int ret3 = a.len[0], ret4 = b.len[0];
	for (int i=0; i<6; i++) {
		ret1 = (ret1 * a.len[i])%M; 
		ret2 = (ret2 * a.len[i])%M; 
		ret3 &= a.len[i];
		ret4 &= b.len[i];
	}
	if (ret1 != ret2 || ret3 != ret4) return false;
	for (int i=0; i<6; i++)
	{
		bool flag1 = true, flag2 = true;
		for (int j=0; j<6; j++)
		{
			if (a.len[(i+j)%6] != b.len[j])
				flag1 = false;
			if (a.len[(i+6-j)%6] != b.len[j])
				flag2 = false;
		}
		if (flag1 || flag2) return true;
	}
	return false;
}
int getKey(const Node& a)
{
	int ret = 0;
	for (int i=0; i<6; i++) 
		ret = (ret + a.len[i]%M)%M;
	return ret;
}
int main(int argc, char *argv[]) {
	int n;
	while(~scanf("%d", &n))
	{
		memset(num, 0, sizeof(num));
		bool flag = true;
		for (int i=0; i<n; i++) {
			Node tmp;
			for (int j=0; j<6; j++) scanf("%d", &tmp.len[j]);
			if (flag == false) continue;
			int key = getKey(tmp);
			for (int j = 0; j < num[key]; j++) {
				if (isSame(tmp, node[key][j]))
				{
					flag = false;
					break;
				}
			}
			node[key][num[key]++] = tmp;
		}
		if (flag)
			printf("No two snowflakes are alike.\n");
		else
			printf("Twin snowflakes found.\n");
	}
	return 0;
}