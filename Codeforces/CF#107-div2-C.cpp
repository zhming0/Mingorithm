#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;
bool prime[10000000];
bool isPrime(long long n)
{
	long long qn = (long long)sqrt(n);
	for (long long i=2; i<=qn; i++) 
		if (n%i == 0) 
			return false;
	return true;
}
int main(int argc, char *argv[]) {
	long long q, qq, qqq, checkpnt, tmp;
	cin >> q;
	if (isPrime(q)) {
		cout << 1 << endl << 0 << endl;
		return 0;
	}
	qq = (long long)sqrt(q);
	qqq = (long long)sqrt(qq);
	memset(prime, true, sizeof(prime));
	for (long long i=2; i<=qqq; i++) {
		if (prime[i]) 
			for (long long j=2; j*i <= qq; j++)
				prime[j*i] = false;
	}
	bool flag = false;
	for (int i=2; i<=qq; i++) {
		if (q%i==0 && prime[i])
		{
			flag = true;
			tmp = i;
			checkpnt = q/i;
			break;
		}
	}
	if (flag)
	{
		if (isPrime(checkpnt))
			cout << 2 << endl;
		else {
			bool tmp_flag = false;
			for (int i=2; i<=qq; i++) {
				if (checkpnt%i==0 && prime[i])
				{
					checkpnt = tmp * i;
					tmp_flag = true;
					break;
				}
			}
			if (tmp_flag) {
				cout << 1 << endl;
				cout << checkpnt << endl;
			}else {
				cout << 2 << endl;
			}
		}
		return 0;
	}
	if (flag == false)
	{
		cout << 2 << endl;
	}
	return 0;
}