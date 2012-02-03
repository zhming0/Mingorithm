#include <iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;

int main(int argc, char *argv[]) {
	int K, L, M, n, d;
	int ret=0;
	cin >> K >> L >> M >> n >> d;
	for (int i=1; i<=d; i++) {
		if(i%K==0 || i%M==0 || i % L ==0 || i%n==0) 
			ret++;
	}
	printf("%d\n", ret);
	return 0;
}