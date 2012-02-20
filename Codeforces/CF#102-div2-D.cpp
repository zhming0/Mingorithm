#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	if (m>n) swap(n, m);
	if (m==1) 
		printf("%d\n", n);
	else if (m==2) 
		printf("%d\n", 2*(2*(n/4) + min(n%4, 2)));
	else if (m==3 && n==3)
		printf("%d\n", 5);
	else if (m==3 && n==5)
		printf("%d\n", 8);
	else if (m==3 && n==6) 
		printf("%d\n", 8);
	else if (m==4 && n==4)
		printf("%d\n", 8);
	else
		printf("%d\n", n*m - n*m/2);
	return 0;
}