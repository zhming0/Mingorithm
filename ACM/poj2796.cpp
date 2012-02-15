#include<cstring>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int num[100100], le[100100], ri[100100], st[100100];
int top;
long long sum[100100];
int main()
{
	int n, idx;
	long long ret = -1;
	scanf("%d", &n);
	sum[0] = 0;
	num[0] = num[n+1] = -1;
	for (int i=1; i<=n; i++) {
		scanf("%d", &num[i]);
		sum[i] = sum[i-1] + num[i];
	}
	top = 0; st[top++] = 0;
	for (int i=1; i<=n; i++)
	{
		while(num[st[top-1]]>=num[i]) top--;
		le[i] = st[top-1];
		//printf("le[%d] = %d\n", i, le[i]);
		st[top++] = i;
	}
	top = 0; st[top++] = n+1;
	for (int i=n; i>=1; i--)
	{
		while(num[st[top-1]]>=num[i]) top--;
		ri[i] = st[top-1];
		//printf("ri[%d] = %d\n", i, ri[i]);
		st[top++] = i;
	}
	for (int i=1; i<=n; i++) {
		long long tmp =	(long long) (sum[ri[i]-1]-sum[le[i]+1] + num[le[i]+1]) * (long long)num[i];
		//printf("i=%d, tmp = %d\n", i, tmp);
		if (tmp > ret) {
			ret = tmp;
			idx = i;
		}
	}
	cout << ret << endl;
	cout << le[idx]+1 << " " << ri[idx] - 1 << endl;
	return 0;
}
